#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dialog.h>
#include <form.h>

// .h头文件定义类，声明函数和变量

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    //引入Qt信号和槽机制的一个宏
    Q_OBJECT

public:
    //构造函数中parent是指父窗口
    //如果parent是0，那么窗口就是一个顶层的窗口
    //explicit关键字用于修饰单参数的构造函数，防止隐式类型转换发生。当构造函数被声明为explicit时，它只能被显式地调用，而不能被隐式地调用。
    explicit MainWindow(QWidget *parent = nullptr);
    //析构函数，在对象被销毁时调用，用于资源的清理和释放，由编译器自己调用
    ~MainWindow();

    //头文件中定义函数
    void testPushButton();
    void testQDialog();
    void testQIcon();
    void testQFileDialog();
    void testQLabel();

    //测试常量成员函数 const
    void setConstValue(int v);
    int getConstValue() const;

    void lineEditTest();

private slots:
    void on_myPushButton_clicked();

    void on_myPushButton_pressed();

    void on_showDialogPushButton_clicked();

    void on_showMyQMsgBox_clicked();

    void on_showInfoQMsgBox_clicked();

    void on_showQtQMsgBox_clicked();

    void on_showErrQMsgBox_clicked();

    void on_showInfoIconQMsgBox_clicked();

    void on_pushButton_2_clicked();
    
    void on_btn_newpage_clicked();

private:
    Ui::MainWindow *ui;
    int constValue;

    Form* form = nullptr;
};

#endif // MAINWINDOW_H
