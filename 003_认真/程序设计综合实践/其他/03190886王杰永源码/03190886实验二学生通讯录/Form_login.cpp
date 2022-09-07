#include "Form_login.h"
#include "ui_Form_login.h"
#include "Mainwindow.h"
#include "ui_Mainwindow.h"

Form_Login::Form_Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Login)
{
    ui->setupUi(this);
    //登录/注册 信号与槽函数连接
    connect(ui->Button_Load,&QPushButton::clicked,this,&Form_Login::Button_Load_clicked);
    connect(ui->Button_Register,&QPushButton::clicked,this,&Form_Login::Button_Register_clicked);
    login();
}

Form_Login::~Form_Login()
{
    delete ui;
}

void Form_Login::login(){
    DB=QSqlDatabase::addDatabase("QMYSQL","myContractssql");
    DB.setHostName("localhost");
    DB.setPort(3306);
    DB.setUserName("root");
    DB.setPassword("y25557656755723");
    if(!DB.open()){
        qDebug()<<"连接失败:"<<DB.lastError().text();
        return;
    }
    else {
        qDebug()<<"连接成功！";
    }

    QSqlQuery query(DB);
    query.exec("create table if not exists mycontracts.users\
                  (\
                        UserName varchar(20) primary key,\
                        Password varchar(20)\
                   )"
               );
}


void Form_Login::Button_Load_clicked(){

    QString UserName=ui->Edit_UserName->text();
    QString Password=ui->Edit_Password->text();

    QSqlQuery query(DB);
    query.prepare("select count(*) from mycontracts.users where UserName = \'"+UserName+"\' and Password = \'"+Password+"\'");
    query.exec();
    query.next();

    if(query.value(0)==1){

        m.ui->Table_Student->clearContents();
        m.ui->Table_Student->setRowCount(1);

        m.DB=QSqlDatabase::addDatabase("QMYSQL","myContractssql");
        m.DB.setHostName("localhost");
        m.DB.setPort(3306);
        m.DB.setUserName("root");
        m.DB.setPassword("y25557656755723");
        if(!m.DB.open()){
            qDebug()<<"连接失败:"<<DB.lastError().text();
            return;
        }
        else {
            qDebug()<<"连接成功！";
        }

        QMessageBox::about(this,"提示","登陆成功！");
        ui->Edit_Password->clear();
        ui->Edit_UserName->clear();

        //连接数据库

            //创建数据库
            QSqlQuery query(m.DB);
            query.exec("create database if not exists myContracts");

            //创建表
            query.exec("create table if not exists mycontracts.student\
                          (\
                                ID varchar(20) primary key,\
                                Name varchar(20),\
                                Sex varchar(5),\
                                Age varchar(5),\
                                Tell varchar(20),\
                                Address varchar(20),\
                                QQNum varchar(20),\
                                Major varchar(20)\
                           )"
                       );

        //刷新表格内容
        m.refresh();
        m.ui->Table_Student->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        //加载左侧树形图
        m.Load();

        if(UserName=="Chen")
            m.IsAdmin=true;
        else {
            m.IsAdmin=false;
        }
    }
    else{
        QMessageBox::about(this,"提示","用户名或密码错误!");
        return;
    }
    this->close();
    m.show();
}

void Form_Login::Button_Register_clicked(){
    QSqlQuery query(DB);
    QString UserName=ui->Edit_UserName->text();
    QString Password=ui->Edit_Password->text();
    query.prepare("select count(*) from mycontracts.users where UserName = \'"+UserName+"\'");
    query.exec();
    query.next();

    if(UserName==""||Password==""){
        QMessageBox::about(this,"提示","用户名或密码不能为空！");
        return;
    }
    else if(query.value(0)==1){
        QMessageBox::about(this,"提示","该用户已存在");
        return;
    }

    else {
        QMessageBox::about(this,"提示","注册成功！");
        query.prepare("insert into mycontracts.users values(?,?)");
        query.addBindValue(UserName);
        query.addBindValue(Password);
        query.exec();
        ui->Edit_Password->clear();
        ui->Edit_UserName->clear();
        return;
    }
}

