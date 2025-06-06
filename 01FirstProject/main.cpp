#include "mywidget.h"

#include <QApplication>
//包含应用程序头文件

//main程序入口 argc:命令行变量数量 argv:命令行变量的数组
int main(int argc, char *argv[])
{
    //应用程序对象，在Qt中，应用程序对象，有些仅有一个
    QApplication a(argc, argv);
    //窗口对象 myWidget父类 -> Qwidget
    myWidget w;
    //窗口对象，默认不会显示，必须调用show方法显示窗口
    w.show();
    //让应用程序进入消息循环
    return a.exec();
//     while(true)
//     {
//         if(点击叉号)
//         {
//             break;
//         }
//      }
}
