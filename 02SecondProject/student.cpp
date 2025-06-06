#include "student.h"
# include <QDebug>

Student::Student(QObject *parent)
    : QObject{parent}
{}

void Student::treat()
{
    qDebug() << "请老师吃饭";
}

void Student::treat(QString foodname)
{
    //把QString转为char*可借助帮助手册： QString->  先转为QByteArray (toUtf8()) ->  char* (data())
    qDebug() << "老师要吃" << foodname.toUtf8().data();
}
