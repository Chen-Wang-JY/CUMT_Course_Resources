#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <Form_add.h>
#include <Form_search.h>
#include <QMessageBox>
#include <QFileDialog>
#include <QProcess>
#include <QList>
#include <QVector>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


public:
    Ui::MainWindow *ui;



public:
    QSqlDatabase DB;
    //初始化，连接数据库
    void connectMySQL();
public:
    //将数据库中数据显示在表格中
    void refresh();
    void Refresh();
    int DB_Row;


//“添加/编辑联系人”窗口相关方法
private:
    int flag;//值为1，代表当前请求为添加；值为0，代表当前请求为编辑
    Form_Add formAdd;
    QString ID0;//编辑操作时，获取原始ID
private slots:
    void Add();
    void Edit();
    void Delete();
    void Button_confirm_clicked();

//“查找联系人” 相关方法
private:
    Form_Search formSearch;
private slots:
    void Search();
    void Button_Search_clicked();

//“备份与恢复” 相关方法
private slots:
    void Back_up();
    void Recovery();

//左侧树形图 相关方法
public:
    void Load();
private:
    QList<QString> major;
private slots:
    void Sorts();


//登录 相关方法
public:
    bool IsAdmin;

};

#endif // MAINWINDOW_H
