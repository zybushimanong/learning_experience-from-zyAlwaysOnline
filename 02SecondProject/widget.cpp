#include "widget.h"
#include "ui_widget.h"
# include <QPushButton>

//老师类 Teacher
//学生类 Student
//下课了 老师触发信号“饿了”  学生  请客吃饭

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建一个老师对象
    this->t = new Teacher(this);

    //创建一个学生对象
    this->s = new Student(this);

    //老师  饿了  学生  请客  仅仅此无法实现“请客” -> 没有触发下课
    //connect(t, &Teacher::hungry, s, &Student::treat);

    //调用有参信号和槽
    //有参数时需要调用函数指针 来区分有参无参
    void (Teacher::*teachersignal)(QString) = &Teacher::hungry;
    void (Student::*studentslot)(QString) = &Student::treat;

    connect(t, teachersignal, s, studentslot);
    //1，信号可以连接信号
    //2，一个信号可以连接多个槽函数
    //3，多个信号可以连接一个槽函数
    //4，信号和槽的参数必须类型一一对应
    //5，信号的参数个数可以多与槽函数的参数个数 但必须一一对应

    QPushButton * btn = new QPushButton("下课", this);
    resize(600, 400);
    btn->move(250, 150);

    connect(btn, &QPushButton::clicked, this, &Widget::classisover);
    connect(btn, &QPushButton::clicked, this, &Widget::close);

    //断开连接  此时点击按钮不会关闭窗口
    disconnect(btn, &QPushButton::clicked, this, &Widget::close);

    //无参信号和槽连接
    void (Teacher::*teachersignal2)(void) = &Teacher::hungry;
    void (Student::*studentslot2)(void) = &Student::treat;

    connect(btn, &QPushButton::clicked, t, teachersignal2); //信号可以连接信号
    connect(t, teachersignal2, s, studentslot2);
    //connect(s, studentslot2, this, &Widget::close);  //closed与studentslot2返回值不一致
    //connect(this, &Widget::close, this, &Widget::classisover); //close不是信号且前后两者类型不匹配

    //lambda表达式
    [btn](){
        btn->setText("aaaa");  //修改了btn的文本值
    }();  //()表示调用lambda表达式

    //调用下课
    //classisover();
}

void Widget::classisover()
{
    //emit表示触发
    //emit t->hungry();
    //当参数为QString时，输出会带有  “”   需要把其转化为char*
    emit t->hungry("可乐鸡翅");
}

Widget::~Widget()
{
    delete ui;
}
