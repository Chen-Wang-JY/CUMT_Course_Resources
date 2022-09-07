#ifndef FORM_LOGIN_H
#define FORM_LOGIN_H

#include <QWidget>
#include "Mainwindow.h"

namespace Ui {
class Form_Login;
}

class Form_Login : public QWidget
{
    Q_OBJECT

public:
    explicit Form_Login(QWidget *parent = nullptr);
    ~Form_Login();

private:
    Ui::Form_Login *ui;



private:
    MainWindow m;
    void login();
    QSqlDatabase DB;
private slots:
    void Button_Load_clicked();
    void Button_Register_clicked();
};

#endif // FORM_LOGIN_H
