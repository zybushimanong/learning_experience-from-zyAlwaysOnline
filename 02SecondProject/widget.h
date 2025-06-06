#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
# include"teacher.h"
# include"student.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    Teacher * t;
    Student * s;

    //在private里体现封装性
    void classisover();
};
#endif // WIDGET_H
