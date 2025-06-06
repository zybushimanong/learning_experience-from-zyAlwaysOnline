#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);  //explicit 禁止隐式类型转换，必须传入指定参数 例如 int -> double  但必须是int
    ~MyPushButton();

signals:
};

#endif // MYPUSHBUTTON_H
