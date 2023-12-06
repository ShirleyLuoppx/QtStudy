/**
  1、新建的项目，一般需要把，项目-Shadow Build这个复选框取消掉，要不然在项目路径下找不到 编译后生成的可执行文件
  2、构建项目之前一般先清理一下项目
  3、如果是用的515版本就可以直接在电脑上运行，会有一个窗口弹出来

--------------------------uint8_t start-------------------------------------------
uint8_t：无符号8位整数类型，其中的u表示unsigned-无符号，int就是整数，t表示type-类型，所以就是无符号8位整数类型，取值范围是 [0~2^8-1]=[0-255]，是c++标准库<cstdint>中定义的类型；

<cstdint>标准库中还定义了其他的几个类型：

int8_t：有符号8位整数类型，依旧是一共有2^8=256个取值，取值范围有符号，包含正负数，所以是：-128~127，正数+0和负数各一半
uint16_t：无符号16位整数类型
int16_t：有符号16位整数类型
uint32_t：无符号32位整数类型
int32_t：有符号32位整数类型
uint64_t：无符号64位整数类型
int64_t：有符号64位整数类型
--------------------------uint8_t end-------------------------------------------

.h和.cpp文件命名都是全小写，但是类名就是驼峰命名

单走一个F4切换.h和.cpp；
光标在变量位置F2可以切换到变量声明和定义的地方；光标在函数的位置，可以在声明函数和函数实现之间切换；
Ctrl+B 编译;
光标选中qt源码里面的函数，按F1可以在qtCreator右侧展开对应的源码函数的英文文档


*/

//#include <iostream>
//#include <string>
#include <QDebug>
#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QMouseEvent>
#include <QString>
#include <QWidget>
#include <QStringList>
#include <QVBoxLayout>
#include <QLineEdit>

#include "mytest.h"

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

/**
 * @brief The EventLabel class 继承自QLabel，QLabel最终是继承自QWidget，QWidget中定义了很多protected的virtual的函数，例如鼠标按下事件，键盘按下事件，子类可以重写去实现这些方法
 */
class EventLabel: public QLabel
{
protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
};

/**
 * @brief EventLabel::mouseMoveEvent 重写鼠标移动事件
 * @param event
 */
void EventLabel::mouseMoveEvent(QMouseEvent *event){
    EventLabel::setText(QString("<center><h1>Move: (%1, %2)</h1></center>").arg(QString::number(event->x()),QString::number(event->y())));
}

/**
 * @brief EventLabel::mousePressEvent 重写鼠标按下事件
 * @param event
 */
void EventLabel::mousePressEvent(QMouseEvent *event){
    EventLabel::setText(QString("<center><h1>Press: (%1, %2)</h1></center>").arg(QString::number(event->x()),QString::number(event->y())));
}

/**
 * @brief EventLabel::mouseReleaseEvent 重写鼠标释放事件
 * @param event
 */
void EventLabel::mouseReleaseEvent(QMouseEvent *event){
    QString msg;
    msg.sprintf("<center><h1>Release: (%d, %d)</h1></center>",
                event->x(), event->y());
    this->setText(msg);
}

//处理键盘按下Tab事件并消费掉
// bool CustomWidget::event(QEvent e){
//     if(e.type()==QEvent::KeyPress){
//         QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
//         if(keyEvent == Qt::Key_Tab){
//             qDebug<<"press tab...";
//             return  true;
//         }
//     }
//     return QWidget::event(e);
// }

void MainWindow::setConstValue(int value){
    constValue = value;
    constValue = 1;
}

int MainWindow::getConstValue() const{
    return constValue;
}

/**
 * @brief testQStringList QStringList例子，见名知意，就是一个装QString类型的list集合
 */
void testQStringList(){
    //初始化一个QStringList
    QStringList qStringList = {"test","aaa","bbb","ccc"};
    //遍历集合
    for (int i = 0; i < qStringList.size(); ++i) {
        //数组方式
        qDebug()<<"qStringList[" << i <<"] = "<<qStringList[i];
        //列表方式
        qDebug()<<"qStringList["<<i<<"] = "<<qStringList.at(i);
    }

    qDebug()<<"---------------------------";

    //迭代器方式
    QStringListIterator iterator(qStringList);
    while(iterator.hasNext()){
        qDebug()<<"QStringListIterator content is " << iterator.next();
    }

    qDebug()<<"---------------------------";

    //一种很新的添加集合内容的方式  list<<"content"
    qStringList << "ddd";
    for (int i = 0; i < qStringList.size(); ++i) {
        qDebug()<<qStringList[i];
    }
}

void testQuatFun(int* x,int* y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    qDebug()<<"after swap the x and y = "<<x<<"，"<<y;
}


void showSencondView(){

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

    //追踪鼠标的x.y坐标值
    EventLabel *label = new EventLabel;
    label->setMouseTracking(true);//设置一开始就追踪鼠标，这个值默认false：点击一下之后才开始追踪鼠标
    label->setWindowTitle("MouseEvent Demo");
    label->resize(300, 200);
    // label->show();

    MainWindow mainWindow;
    mainWindow.setConstValue(10086);
    int r = mainWindow.getConstValue();
    qDebug()<<"getConstValue = "<< r;

    testQStringList();

    MyTestClass myTestClass ;
    myTestClass.setAge(100);//用指针对象.fun，用引用对象->函数
    uint8_t getAgeValue = myTestClass.getAge();
    qDebug()<<"get age value is = "<<getAgeValue;

    myTestClass.printAHelloString();

    int myNumA = 2;
    int myNumB  = 8;
    testQuatFun(&myNumA,&myNumB);

    showSencondView();


    return a.exec();
}
