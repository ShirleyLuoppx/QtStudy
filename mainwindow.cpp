#include "mainwindow.h"     //引用定义类和函数的头文件
#include "ui_mainwindow.h"  //引用名为mainwindow的ui文件生成的头文件
//.cpp 文件引用头文件，实现在头文件中定义好的函数

#include <QPushButton>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //在MainWindow的构造函数中，初始化ui界面
    ui->setupUi(this);
    //构造函数中调用函数
    testPushButton();
}

MainWindow::~MainWindow()
{
    //在MainWindow类的析构函数中，删除ui变量
    delete ui;
}

//同名的源文件中实现函数
void MainWindow::testPushButton(){
    QPushButton* qPushBtn =new QPushButton("this is a QPushButton ..");
    qPushBtn->setFixedSize(300,50);
    qPushBtn->setParent(this);
    // qPushBtn->setContentsMargins(30,0,0,0);
    qPushBtn->move(1,1);//设置move值太大了可能会导致看不到内容
    qPushBtn->setStyleSheet("color: red; font-size: 20px;");
}
