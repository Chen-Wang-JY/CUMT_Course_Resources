#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVector>
#include <QPixmap>
#include <QDebug>
#include <ctime>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include "Form_reselection.h"
#include "Form_choseimg.h"
#include "Form_original.h"
#include <QTimer>
#include <QStringList>
#include "Form_records.h"
#include <QTableWidget>
#include <QPoint>
#include <QMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

/*-----------------------------------------------begin---------------------------------------*/
private:
    QPixmap pix0;//初始图片
    QPixmap** pix;//分割的图片数量个pixmap
    QLabel** label;//分割的图片数量个label
    QLabel* l;//存放拖拽模式下的被拖拽的图片
    //记录待交换的图片的相关参数
    int PC;
    QPixmap pixFormer;
    QPixmap pixLatter;
    int index_i;
    int index_j;
    //本地图片路径
    QString path;
    //计时器
    QTimer* timer;
    bool timeRun;//真则表示已经开始计时
    //本地记录
    QVector<double> records;
private:
    //判断是否拼图成功
    bool isSuccessful();
    //释放内存空间
    void Delete();
    //重写事件截取函数
    bool eventFilter(QObject* obj,QEvent* event);
    //读/写本地记录
    void readRecords();
    void writeRecords();
public:
    //难度系数
    int N;
    //初始化
    void Load();


private:
    //“难度重选”窗体对象
    Form_reselection form_reselection;
    //“重选图片”窗体对象
    Form_choseimg form_choseimg;
    int flag;
    //“查看原图”窗体对象
    Form_original form_original;
    //“本地记录”窗体对象
    Form_records form_records;
private slots:
    //打开“难度重选”窗体及button控件的槽函数
    void Form_reselection_Open();
    void Form_reselection_Button_easy();
    void Form_reselection_Button_hard();
    void Form_reselection_Button_hell();
    void Form_reselection_Button_confirm();
    //打开“重选图片”窗体及相关槽函数
    void Form_choseimg_Open();
    void Form_choseimg_Button_1();
    void Form_choseimg_Button_2();
    void Form_choseimg_Button_3();
    void Form_choseimg_Button_4();
    //打开“查看原图”窗体
    void Form_original_Open();
    //打开“本地记录”窗体
    void Form_records_Open();
    //“选择本地图片”槽函数
    void chooseLocalImg();
    //“打乱图片”槽函数
    void upsetImg();
    //计时器槽函数
    void setTime();
    //清空历史记录槽函数
    void Zero();


private:

};

#endif // MAINWINDOW_H
