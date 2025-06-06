#include "mypushbutton.h"
#include <QDebug>

MyPushButton::MyPushButton(QWidget *parent) //这里是QWidget的，目的是最终调用QWidget的构造函数以实现对象树
    : QPushButton{parent} //继承自QPushButton
{
    qDebug() << "我的按钮类调用";
}

MyPushButton::~MyPushButton()
{
    qDebug() << "我的按钮类析构";
}
