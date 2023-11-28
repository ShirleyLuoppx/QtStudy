/**
  1、新建的项目，一般需要把，项目-Shadow Build这个复选框取消掉，要不然在项目路径下找不到 编译后生成的可执行文件
  2、构建项目之前一般先清理一下项目
*/

//#include <iostream>
//#include <string>
#include <QDebug>
#include "mainwindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    //ui显示跟实际车机窗口显示不一致，有时候车机显示不完全。 添加这句话，就可以让窗口显示跟ui显示的一致。
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);


    //qt中的控件都是叫做Qxxx的，QT中的字符串就是QString，里面存储的都是一个个的QChar，可以使用[]或者at来获取指定索引的内容
    QString str = "Hello QString ...";
    //char 是一个关键字，不能用作对象名称
    QChar ch0 = str[0];
    QChar ch03 = str.at(3);

    //QChar的函数， isDigit：是否是数字；isLetter：是否是字母；isLower/isUpper 是否小写/大写；
    bool isDigit = ch0.isDigit();

    qDebug()<<"isDigit = "<<isDigit;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
