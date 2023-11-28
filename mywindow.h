#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>

class MyWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MyWindow(QWidget *parent = nullptr);

signals:
};

#endif // MYWINDOW_H
