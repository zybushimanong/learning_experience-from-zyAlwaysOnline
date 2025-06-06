#include "mywidget.h"
#include <QPushButton> //空间按钮的头文件
#include <QString>
# include "mypushbutton.h"
# include <QDebug>

// 命名规范
// 类名： 首字母大写，单词和单词之间首字母大写
// 函数名和变量名称： 首字母小写，单词和单词之间首字母大写

//快捷键
//注释： ctrl + /
//运行： ctrl + r
//编译： ctrl + b
//字体缩放： ctrl + 鼠标滚轮
//查找： ctrl + f
//整行移动： ctrl + shift + ↑ 或者 ↓
//帮助文档： F1 / esc退出
//自动对齐： ctrl + i
//同名之间的 .h 和 .cpp 的切换： F4




myWidget::myWidget(QWidget *parent)
    : QWidget(parent)       //初始化列表，告诉qtmyWidget继承自QWidget
{
    //创建一个按钮
    QPushButton* btn1 = new QPushButton;
    //btn -> show(); //show以顶层方式弹出按钮控件

    //让btn对象依赖在myWidget窗口中
    btn1->setParent(this);
    //等价于 QPushButton* btn1 = new QPushButton(this);，但是窗口大小不一样

    //显示文本
    btn1->setText("第一个按钮");

    //第二种创建方式
    QPushButton* btn2 = new QPushButton(QString("第二个按钮"), this);
    //重置窗口大小
    resize(600, 400);
    //btn2->resize(); 也可以重置按钮大小
    //移动按钮位置
    btn2->move(250, 200);
    //设置窗口标题
    setWindowTitle("第一个窗口");
    //固定窗口大小
    setFixedSize(600, 400); //没有resize也能运行成功
    btn2->show();

    MyPushButton * mybtn = new MyPushButton;
    //如果继承的父类是QObject,则会被创建在对象树中，不用手动析构
    mybtn->setParent(this);
    mybtn->setText("我的第一个按钮");
    mybtn->move(200, 0);

    connect(btn2, &MyPushButton::clicked, this, &myWidget::close);
    //发起者：btn2   发送的信号：clicked   接受者：this(myWidget)   信号槽(信号处理)：close
    //MyPushButton QPushButton 和 myWidget QWidget 组合都可以
}

myWidget::~myWidget()
{
    qDebug() << "窗口类析构调用";
    //析构顺序应为子类先释放，只是先打印了代码并未先释放
}
