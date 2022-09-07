#ifndef FORM_WELCOME_H
#define FORM_WELCOME_H

#include <QWidget>
#include <QString>
#include "Mainwindow.h"
#include "Form_reselection.h"

namespace Ui {
class Form_welcome;
}

class Form_welcome : public QWidget
{
    Q_OBJECT

public:
    explicit Form_welcome(QWidget *parent = nullptr);
    ~Form_welcome();

private slots:
    void on_Button_easy_clicked();

    void on_Button_hard_clicked();

    void on_Button_hell_clicked();

    void on_Button_comfirm_clicked();

private:
    Ui::Form_welcome *ui;
    MainWindow w;

    friend Form_reselection;
};

#endif // FORM_WELCOME_H
