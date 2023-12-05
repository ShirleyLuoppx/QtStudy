#include "mytest.h"

#include <QDebug>
#include <QPushButton>
#include <QString>

MyTestClass::MyTestClass(QWidget *parent)
{

}

MyTestClass::~MyTestClass()
{

}

void MyTestClass::setAge(int age)
{
    m_age = age;
}

int MyTestClass::getAge() const
{
    return m_age;
}

void MyTestClass::printAHelloString()
{
    qDebug()<<"qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq";
}

void MyTestClass::drawImge()
{
    /*QPushButton* qPushButton;
    qPushButton = new QPushButton();
    QString * qStyle = QString("QPushButton{border-image: url(%1)}");

    qPushButton->setStyle(qStyle);*/
}


