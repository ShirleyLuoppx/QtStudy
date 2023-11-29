#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    this->setWindowTitle("登陆");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_2_clicked()
{
    this->close();
}


void Dialog::on_pushButton_clicked()
{
    QString strName =ui->lineEditName->text();
    QString strPwd = ui->lineEditPwd->text();
    this->close();
    qDebug()<<"name = "<<strName<<"，pwd = "<<strPwd;
}

