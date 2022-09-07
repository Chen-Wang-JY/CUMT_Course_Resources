#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QStack>
#include <QDialog>
#include "history.h"
#include <QIcon>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_Button_1_clicked();

    void on_Button_2_clicked();

    void on_Button_3_clicked();

    void on_Button_4_clicked();

    void on_Button_5_clicked();

    void on_Button_6_clicked();

    void on_Button_8_clicked();

    void on_Button_7_clicked();

    void on_Button_9_clicked();

    void on_Button_add_clicked();

    void on_Button_0_clicked();

    void on_Button_point_clicked();

    void on_Button_subtract_clicked();

    void on_Button_multiply_clicked();

    void on_Button_divide_clicked();

    void on_Button_clear_clicked();

    void on_Button_back_clicked();

    void on_Button_equal_clicked();

    void on_Button_left_clicked();

    void on_Button_right_clicked();

    void on_Button_mod_clicked();

    void on_Button_e_clicked();

    void on_Button_PI_clicked();

    void on_Button_history_clicked();

    void on_Button_sin_clicked();



    void on_Button_cos_clicked();

    void on_Button_tan_clicked();

    void on_Button_genhao_clicked();

    void on_Button_log_clicked();



private:
    Ui::Widget *ui;

    //储存两个表达式
    QString expression;
    QString Expression;

    //建立“历史记录”对话框的对象
    History history_dia;
    //判断“历史记录”对话框是否打开
    bool isOpen;




private:
    //下面的函数可以将中缀表达式转换为后缀表达式

    //运算符s位于栈外的优先级
    int icp(QString s);

    //运算符s位于栈内的优先级
    int isp(QString s);

    //将分割后的字符串作为参数，返回后缀表达式。
    QStringList Transform(QStringList ex);


    //实现后缀表达式的计算
private:
    QStack<double> s;

    //开始计算
    double Run(QStringList exx);

    //计算当前运算符ch
    void calculate(char ch);

    //从栈中取出两个操作数left和rigth
    bool GetOperand(double& left,double& right,bool& flag);

    //从栈中取出一个操作数lr;
    bool GetOneOperand(double& lr,bool& flag);


};

#endif // WIDGET_H
