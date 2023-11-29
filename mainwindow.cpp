#include "mainwindow.h"     //引用定义类和函数的头文件
#include "ui_mainwindow.h"  //引用名为mainwindow的ui文件生成的头文件
//.cpp 文件引用头文件，实现在头文件中定义好的函数
//在.ui界面的时候右键MainWindow可以选择添加工具栏、菜单栏，可以给状态栏添加子选项
//.ui设计界面修改编译后，会生成一个ui_mainwindow.h文件，里面就是QtCreateor给我们生成的对应mainwindow.ui文件的界面代码
#include <QPushButton>
#include <QDebug>


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
    QPushButton* qPushBtn =new QPushButton();
    qPushBtn->setFixedSize(300,50);
    qPushBtn->setParent(this);
    qPushBtn->setText("this is a QPushButton ..");
    // qPushBtn->setContentsMargins(230,0,0,0);//这个没得效果
    qPushBtn->move(1,100);//设置move值太大了可能会导致看不到内容
    qPushBtn->setStyleSheet("color: red; font-size: 20px;");

    //修改窗口的标题
    this->setWindowTitle("QPushBottonTitle");
    //设置窗口大小，仅是这样设置了之后，窗口还是能拖动大小
    this->resize(1600,300);
    //限制窗口大小，设置了之后就无法拖动修改窗口的大小了
    this->setFixedSize(1600,300);


    //创建一个QPushButton,构造方法直接传参给button的内容和parent父窗口
    QPushButton* closeBtn = new QPushButton("close",this);
    closeBtn->move(0,60);
    //connect函数是建立信号发送者、信号、信号接收者、槽四者关系的函数：谁，发了啥信号，给谁，要做啥
    //四个参数都是指针，信号和槽是函数指针
    connect(closeBtn,&QPushButton::clicked,this,&MainWindow::close);

    //ui->xxx  获取mainwindow.ui 中的控件，xxx对应QtDesigner中的控件名称
    ui->mylabel->setText("after setText on Lable");

}

//快速创建控件的事件(信号)和对应的操作(槽)，在.ui界面右键控件，点击转到槽，选择自己需要的事件，然后QtCreator就会给我们分别在.h和.cpp文件生成一个槽函数，而且也为我们做好了连接，我们只需要实现.cpp里面的函数即可
void MainWindow::on_myPushButton_clicked()
{
    ui->myPushButton->setText("create a slot by QtCreator");
}


void MainWindow::on_myPushButton_pressed()
{
    qDebug()<<"click myPushButton";
}

