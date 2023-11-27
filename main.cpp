/**
  新建的项目，一般需要把，项目-Shadow Build这个复选框取消掉，要不然在项目路径下找不到 编译后生成的可执行文件
*/
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
