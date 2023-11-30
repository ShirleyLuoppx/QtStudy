#include "mainwindow.h"     //引用定义类和函数的头文件
#include "ui_mainwindow.h"  //引用名为mainwindow的ui文件生成的头文件
//.cpp 文件引用头文件，实现在头文件中定义好的函数
//在.ui界面的时候右键MainWindow可以选择添加工具栏、菜单栏，可以给状态栏添加子选项
//.ui设计界面修改编译后，会生成一个ui_mainwindow.h文件，里面就是QtCreateor给我们生成的对应mainwindow.ui文件的界面代码
#include <QPushButton>
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QTextEdit>
#include <QAction>
#include <QVBoxLayout>

//看看其他项目的多界面是如何跳转的


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //在MainWindow的构造函数中，初始化ui界面
    ui->setupUi(this);
    //构造函数中调用函数
    testPushButton();
    // testQIcon();

    // testQFileDialog();

    // this->setWindowIcon(QIcon("/images/icon.jpg"));
    setWindowIcon(QIcon(QApplication::applicationDirPath() + "icon.jpg"));


    testQLabel();
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

//show一个dialog出来
void MainWindow::testQDialog(){
    QDialog *dialog = new QDialog;
    //对话框关闭时，自动销毁对话框，防止内存泄漏
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setWindowTitle(tr("Hello, dialog!"));
    dialog->show();
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


void MainWindow::on_showDialogPushButton_clicked()
{
    testQDialog();
}

//弹出一个框，带有取消、保存等按钮的
void MainWindow::on_showMyQMsgBox_clicked()
{
    QMessageBox* qMessageBox = new QMessageBox();
    qMessageBox->setWindowTitle("QMessageTitle");
    qMessageBox->setText("content ..........");
    qMessageBox->setInformativeText(tr("informative Text >..."));
    qMessageBox->setDetailedText(tr("detailed text ...."));

    qMessageBox->setStandardButtons(QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel);//使用 | 来展示需要展示出来的按钮
    qMessageBox->setDefaultButton(QMessageBox::Save);
    int ret = qMessageBox->exec();
    switch(ret){
    case QMessageBox::Save:
        qDebug()<<"click save btn";
        break;
    case QMessageBox::Discard:
        qDebug()<<"click discard btn";
        break;
    case QMessageBox::Cancel:
        qDebug()<<"click cancel btn";
        break;
    }
}


/**
 * @brief MainWindow::on_showInfoQMsgBox_clicked
 * 弹出一个信息展示框，包含标题、内容和一个确认按钮
 */
void MainWindow::on_showInfoQMsgBox_clicked()
{
    QMessageBox* infoMsgBox = new QMessageBox();
    // infoMsgBox->setWindowTitle("QMsgBox");//标题
    // infoMsgBox->setText("info msg dialog content..");//内容
    // infoMsgBox->show();

    //上面3行，完全等于下面这一行，也不能调用show，about函数里面应该是自己调用了的，这个函数还比较方便
    infoMsgBox->about(this,"Title..","dialog by about function from QMessageBox");
}


/**
 * @brief MainWindow::on_showQtQMsgBox_clicked
 * qt信息展示框，就是给普通信息展示框添加了很多Qt相关的content内容
 */
void MainWindow::on_showQtQMsgBox_clicked()
{
    QMessageBox* qtMsgBox = new QMessageBox();
    qtMsgBox->aboutQt(this,"aboutQtTitle");
}

/**
 * @brief MainWindow::on_showErrQMsgBox_clicked
 * 错误信息展示框，包含一个红×的图标，title和content以及一个默认的ok按钮
 */
void MainWindow::on_showErrQMsgBox_clicked()
{
    QMessageBox* qtErrBox = new QMessageBox();
    //前面三个必传参数，后面都是非必传的，只传前面三个参数的时候只有一个默认的ok按钮，后面如果添加了按钮就展示自己添加的
    qtErrBox->critical(this,"errTitle","content ......",QMessageBox::Save,QMessageBox::Cancel);

}

/**
 * @brief MainWindow::on_showInfoIconQMsgBox_clicked
 * 带有info图标的信息展示弹框，跟QMessageBox.about就是一个图标的差异；
 * 类似的弹框还有Question、warning就不一一写了
 */
void MainWindow::on_showInfoIconQMsgBox_clicked()
{
    QMessageBox* infoWithIcon = new QMessageBox();
    infoWithIcon->information(this,"infomationTitle","information text ...");
}


void MainWindow:: testQIcon(){
    QIcon qIcon = QIcon(":/images/icon.jpg");

    QPushButton* qBtn = new QPushButton();
    qBtn->setIcon(qIcon);
    // qBtn->show();
    // qBtn->move(480,100);

}

/**
 * @brief MainWindow::testQFileDialog
 * 文件管理器dialog
 */
void MainWindow::testQFileDialog(){
    QAction*  openAction = new QAction(QIcon(":/images/icon"),tr("&Open..."), this);
    openAction->setStatusTip(tr("Open an existing file"));
    QAction*  saveAction = new QAction(QIcon(":/images/alias01"), tr("&Save..."), this);
    saveAction->setStatusTip(tr("Save a new file"));
    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);
    file->addAction(saveAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);


    QTextEdit* textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);
}

void MainWindow::on_pushButton_2_clicked()
{
    Dialog d ;
    d.exec();
}


/**
 * @brief MainWindow::testQLabel
 * 常用的Qt控件之一：QLabel：可以显示文字，可以添加html，可以显示图片，可以展示动画
 */
void MainWindow::testQLabel(){
    QLabel* htmlLink = new QLabel(this);
    htmlLink->setText("<h1><a href=\"https://www.baidu.com\">百度一下</a></h1>");
    htmlLink->setOpenExternalLinks(true);
    htmlLink->move(500,200);
}
