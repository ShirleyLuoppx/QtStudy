#ifndef MYTEST_H
#define MYTEST_H

#include <QObject>

class MyTestClass : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int age READ getAge WRITE setAge)//定义一个命名为age类型为int的宏，并给他设置set和get方法

public:
    explicit MyTestClass(QWidget *parent = nullptr) ;
    virtual ~MyTestClass() ;


private:
    int m_age;

public:
    void setAge(int age);
    int getAge() const;

    void printAHelloString(void);//这种函数的参数括号里面写一个void的，表示：这个函数不允许传任何参数，直接调用就好了

    void drawImge();
};




#endif // MYTEST_H



//头文件中，
//#ifndef xxx
//#define xxx
//#endif       都是QtCreateor 自动生成的


//一般新建文件的时候都是新建的h/cpp这一个，qtCreaetor会帮我们把两个文件所需的基本模式都添加起，.h头文件定义类、函数、变量，.cpp文件实现这个函数，然后可以在其他.cpp文件里面去调用这些函数
