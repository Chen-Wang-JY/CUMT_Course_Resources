#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include "history.h"
#include "ui_history.h"
#include <QSize>


//构造函数
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //初始化”历史记录"按钮的图标
    QIcon icon(":/res/history.png");
    ui->Button_history->setIcon(icon);
    QSize qsize(51,51);
    ui->Button_history->setIconSize(qsize);

    this->isOpen=false;//开始时，历史记录对话框未打开


    //初始化主窗体
    setWindowTitle("计算器");


}

//析构函数
Widget::~Widget()
{
    delete ui;
}

//运算符在栈外优先级
int Widget::icp(QString s){
    if(s=="#")
        return 0;
    else if(s=="(")
        return 9;
    else if(s=="sin"||s=="cos"||s=="tan"||s=="√"||s=="lg")
        return 8;
    else if(s=="×"||s=="÷"||s=="%")
        return 5;
    else if(s=="+"||s=="-")
        return 3;
    else if(s==")")
        return 1;
    else {
        ui->Screen->setText("错误！");
        return -1;
    }
}
//运算符在栈内优先级
int Widget::isp(QString s){
    if(s=="#")
        return 0;
    else if(s=="(")
        return 1;
    else if(s=="sin"||s=="cos"||s=="tan"||s=="√"||s=="lg")
        return 7;
    else if(s=="×"||s=="÷"||s=="%")
        return 6;
    else if(s=="+"||s=="-")
        return 4;
    else if(s==")")
        return 9;
    else {
        ui->Screen->setText("错误！");
        return -1;
    }
}

//中缀转换成后缀表达式
QStringList Widget::Transform(QStringList ex){

    QStack<QString> stack;
    stack.push("#");
    QString r;

    QStringList anssss;

    for(int i=0;!stack.isEmpty();){
        //如果ex[i]是操作数，则存入r中，直到遇到操作符为止。
        if(ex[i]!="+"&&ex[i]!="-"&&ex[i]!="×"&&ex[i]!="÷"&&ex[i]!="%"
                &&ex[i]!="("&&ex[i]!=")"&&ex[i]!="#"&&ex[i]!="sin"&&ex[i]!="cos"&&ex[i]!="tan"&&ex[i]!="√"&&ex[i]!="lg"){
            anssss.insert(i,ex[i]);
            i++;

        }
        //遇到了操作符时：
        else {


            //接下来处理操作符ex[i]

            //若栈外操作符ex[i]优先级大于栈内操作符stack.top()优先级，则ex[i]进栈
            if(icp(ex[i])>isp(stack.top())){
                stack.push(ex[i]);
                i++;
            }

            //若栈外操作符优先级小于栈内操作符优先级，则将栈内操作符输出到后缀表达式，并出栈。
            else if(icp(ex[i])<isp(stack.top()))
            {
                QString x=stack.top();
                anssss.insert(i,x);
                stack.pop();
            }
            //若栈外栈内优先级相同，退栈不输出。同时，如果栈内是“（“，则读取下一字符
            else if(icp(ex[i])==isp(stack.top())){
                QString pop=stack.top();
                stack.pop();
                if(pop=="(")
                    i++;
            }
        }
    }
    return anssss;
}

//取出两个操作数
bool Widget::GetOperand(double& left,double& right,bool& flag){
    flag=true;
    if(s.isEmpty()){
       ui->Screen->setText("输入表达式非法！");
       flag=false;
       return false;
    }
    right=s.top();
    s.pop();
    if(s.isEmpty()){
        ui->Screen->setText("输入表达式非法！");
        flag=false;
        return false;
    }
    left=s.top();
    s.pop();
    return true;
}
//取出一个操作数
bool Widget::GetOneOperand(double& lr,bool& flag){
    flag=true;
    if(s.isEmpty()){
        ui->Screen->setText("输入表达式非法！");
        flag=false;
        return false;
    }
    lr=s.top();
    s.pop();
    return true;
}

//开始计算
double Widget::Run(QStringList exx){
    int i=0;double l,r,x;
    bool flag=true;

    while(i<exx.length()){

        flag=true;

        if(exx[i]!=""&&exx[i]!="+"&&exx[i]!="-"&&exx[i]!="×"&&exx[i]!="÷"&&exx[i]!="%"
                &&exx[i]!="sin"&&exx[i]!="cos"&&exx[i]!="tan"&&exx[i]!="√"&&exx[i]!="lg"){
            //操作数进栈
            s.push(exx[i].toDouble());
            i++;
        }
        else if(exx[i]!=""){
            if(exx[i]=="+"){
                this->GetOperand(l,r,flag);
                if(!flag)
                    break;
                s.push(l+r);
                i++;
            }
            else if(exx[i]=="-"){
                this->GetOperand(l,r,flag);
                if(!flag)
                    break;
                s.push(l-r);
                i++;
            }
            else if(exx[i]=="×"){
                this->GetOperand(l,r,flag);
                if(!flag)
                    break;
                s.push(l*r);
                i++;
            }
            else if(exx[i]=="÷"){
                this->GetOperand(l,r,flag);
                if(!flag)
                    break;
                s.push(l/r);
                i++;
            }
            else if(exx[i]=="%"){
                this->GetOperand(l,r,flag);
                if(!flag)
                    break;
                s.push(fmod(l,r));
                i++;
            }
            else if(exx[i]=="sin"){
                this->GetOneOperand(x,flag);
                if(!flag)
                    break;
                s.push(sin(x));
                i++;
            }
            else if(exx[i]=="cos"){
                this->GetOneOperand(x,flag);
                if(!flag)
                    break;
                s.push(cos(x));
                i++;
            }
            else if(exx[i]=="tan"){
                this->GetOneOperand(x,flag);
                if(!flag)
                    break;
                s.push(QString::number(tan(x),'f',5).toDouble());
                i++;
            }
            else if(exx[i]=="√"){
                this->GetOneOperand(x,flag);
                if(!flag)
                    break;
                s.push(sqrt(x));
                i++;
            }
            else if(exx[i]=="lg"){
                this->GetOneOperand(x,flag);
                if(!flag)
                    break;
                s.push(log(x));
                i++;
            }
        }
        else{
            i++;
        }
    }
    if(!flag){
        Expression.clear();
        return -999999;
    }
    double ans=s.top();
    s.pop();

    if(fabs(ans)<1e-5)
        ans=0;
    //将“历史”对话框中的label文本改变。
    history_dia.ui->label->setText("历史记录:");

    ui->Screen->setText(QString::number(ans));

    return ans;
}

void Widget::on_Button_1_clicked()
{
    Expression += "1";
    expression += "1";
    ui->Screen->setText(expression);
}

void Widget::on_Button_2_clicked()
{
    Expression += "2";
    expression += "2";
    ui->Screen->setText(expression);
}

void Widget::on_Button_3_clicked(){
    Expression += "3";
    expression += "3";
    ui->Screen->setText(expression);
}

void Widget::on_Button_4_clicked()
{
    Expression += "4";
    expression += "4";
    ui->Screen->setText(expression);
}

void Widget::on_Button_5_clicked()
{
    Expression += "5";
    expression += "5";
    ui->Screen->setText(expression);
}

void Widget::on_Button_6_clicked()
{
    Expression += "6";
    expression += "6";
    ui->Screen->setText(expression);
}

void Widget::on_Button_8_clicked(){
    Expression += "8";
    expression += "8";
    ui->Screen->setText(expression);
}

void Widget::on_Button_7_clicked()
{
    Expression += "7";
    expression += "7";
    ui->Screen->setText(expression);
}

void Widget::on_Button_9_clicked()
{
    Expression += "9";
    expression += "9";
    ui->Screen->setText(expression);
}

void Widget::on_Button_add_clicked()
{
    Expression += "~+~";
    expression += "+";
    ui->Screen->setText(expression);
}

void Widget::on_Button_0_clicked()
{
    Expression += "~0~";
    expression += "0";
    ui->Screen->setText(expression);
}

void Widget::on_Button_point_clicked()
{
    Expression += ".";
    expression += ".";
    ui->Screen->setText(expression);
}

void Widget::on_Button_subtract_clicked()
{
    Expression += "~-~";
    expression += "-";
    ui->Screen->setText(expression);
}

void Widget::on_Button_multiply_clicked()
{
    Expression += "~×~";
    expression += "×";
    ui->Screen->setText(expression);
}

void Widget::on_Button_divide_clicked()
{
    Expression += "~÷~";
    expression += "÷";
    ui->Screen->setText(expression);
}

void Widget::on_Button_clear_clicked()
{
    Expression.clear();
    expression.clear();
    ui->Screen->clear();
    ui->Label->clear();
}

void Widget::on_Button_back_clicked()
{
    //只有lineedit中有输入才可以删除
    if(expression.length()!=0){
        if(Expression[Expression.length()-1]=="~")
            Expression.chop(3);
        else
            Expression.chop(1);
        expression.chop(1);
        ui->Screen->setText(expression);
    }
}

void Widget::on_Button_sin_clicked()
{
    expression += "sin";
    Expression += "~sin~";
    ui->Screen->setText(expression);
}

void Widget::on_Button_cos_clicked()
{
    expression += "cos";
    Expression += "~cos~";
    ui->Screen->setText(expression);
}

void Widget::on_Button_tan_clicked()
{
    expression += "tan";
    Expression += "~tan~";
    ui->Screen->setText(expression);
}

void Widget::on_Button_genhao_clicked()
{
    expression += "√";
    Expression += "~√~";
    ui->Screen->setText(expression);
}

void Widget::on_Button_log_clicked()
{
    expression += "ln";
    Expression += "~lg~";
    ui->Screen->setText(expression);
}

void Widget::on_Button_left_clicked()
{
    expression += "(";
    Expression += "~(~";
    ui->Screen->setText(expression);
}

void Widget::on_Button_right_clicked()
{
    expression += ")";
    Expression += "~)~";
    ui->Screen->setText(expression);
}

void Widget::on_Button_mod_clicked()
{
    expression += " Mod ";
    Expression += "~%~";
    ui->Screen->setText(expression);
}


void Widget::on_Button_e_clicked()
{
    expression += "e";
    Expression += "2.7182818284590452353602874713527";
    ui->Screen->setText(expression);
}


void Widget::on_Button_PI_clicked()
{
    expression += "Π";
    Expression += "3.141592653589793238462643383279";
    ui->Screen->setText(expression);
}


//等号按钮点击事件
void Widget::on_Button_equal_clicked()
{
    //将Expression分割，存入字符串数组ex中。ex最后一位为"#"
    QStringList ex=Expression.split("~");
    ex.insert(ex.length(),"#");




    //计算
    double Ans=this->Run(this->Transform(ex));

    //将表达式显示在laber上。
    ui->Label->setText(expression+"=");

    //将本次计算结果添加到“历史”对话框的最后，并换行
    history_dia.ui->textBrowser->setText
            (history_dia.ui->textBrowser->document()->toPlainText()    +expression+"="+QString::number(Ans)+"\n");

    //将两个E/expression归零，进而实现新的计算
    expression.clear();
    Expression.clear();
}


//展开“历史”对话框
void Widget::on_Button_history_clicked()
{
    if(isOpen==false){
        history_dia.show();
        isOpen=true;
    }
    else if(isOpen==true){
        history_dia.close();
        isOpen=false;
    }
}

