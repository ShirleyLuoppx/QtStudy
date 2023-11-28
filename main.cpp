/**
  1、新建的项目，一般需要把，项目-Shadow Build这个复选框取消掉，要不然在项目路径下找不到 编译后生成的可执行文件
  2、构建项目之前一般先清理一下项目
  3、如果是用的515版本就可以直接在电脑上运行，会有一个窗口弹出来
*/

//#include <iostream>
//#include <string>
#include <QDebug>
#include "mainwindow.h"
#include <QApplication>


void testQChar(){
    //qt中的控件都是叫做Qxxx的，QT中的字符串就是QString，里面存储的都是一个个的QChar，可以使用[]或者at来获取指定索引的内容
    QString str = "Hello QString ...";
    //char 是一个关键字，不能用作对象名称
    QChar ch0 = str[0];
    QChar ch03 = str.at(3);

    //QChar的函数， isDigit：是否是数字；isLetter：是否是字母；isLower/isUpper 是否小写/大写；
    bool isDigit = ch0.isDigit();
    bool isLetter = ch0.isLetter();

    qDebug()<<"isDigit = "<<isDigit;//false
    qDebug()<<"isLetter = "<<isLetter;//true

    //toUpper转大写
    QChar ch03Upper = ch03.toUpper();
    qDebug()<<"ch03Upper = "<<ch03Upper;
}

void replaceQChar(){
    QString str = "你要记得微笑哟！";
    qDebug()<<"old QString is "<<str;

    QChar Yao = QChar(str[1].unicode());

    QChar Ni =  QChar(str[0].unicode());
    for (int i = 0; i < str.size(); ++i) {
        if(str[i].unicode() == Yao){
            str[i] = Ni;
        }
    }
    qDebug() <<"new str is "<<str;
}

void QStringTest(){
    QString qStr1 = "你好呀 皮皮虾~";
    QString qStr2 = "要永远开心~";
    QString qStr3 = "要永远爱自己~";

    qDebug() << "after append QString is "<<qStr1.append(qStr2);
    qDebug() <<"after preppend QString is"<<(qStr2.prepend(qStr3));


    QString sStr4 = "hello ppx, be kind to yourself";
    QChar fronChar = sStr4.front();//QString的第一个字符
    qDebug()<<fronChar;
    qDebug()<<sStr4.back();//最后一个字符

    QString toIntStr = "168";
    qDebug()<<toIntStr.toInt();//168

    //QString 转int，按16进制的来转换，如果转换失败，会返回0，如果成功会返回成功后的值
    bool ok= false;
    QString str= "FF";
    int N= str.toInt(&ok,16);
    qDebug()<< "" <<N;
}

int main(int argc, char *argv[])
{
    //ui显示跟实际车机窗口显示不一致，有时候车机显示不完全。 添加这句话，就可以让窗口显示跟ui显示的一致。
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    testQChar();
    replaceQChar();
    QStringTest();

    QApplication a(argc, argv);

    // QApplication::processEvents();

    //.ui文件，通过拖动控件生成ui，mainwindow.h 头文件声明类和函数，mainwindow.cpp 源文件引用.ui编译生成的.h文件和mainwindow.h头文件，并实现mainwindow.h中定义的函数，最终在main.cpp中通过.show()展示ui
    //展示窗口
    MainWindow w;
    w.testPushButton();
    w.show();

    return a.exec();
}
