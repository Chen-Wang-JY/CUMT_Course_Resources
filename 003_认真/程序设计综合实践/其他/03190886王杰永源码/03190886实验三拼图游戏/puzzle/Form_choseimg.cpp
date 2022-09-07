#include "Form_choseimg.h"
#include "ui_Form_choseimg.h"
#include "Mainwindow.h"

Form_choseimg::Form_choseimg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_choseimg)
{
    ui->setupUi(this);
}

Form_choseimg::~Form_choseimg()
{
    delete ui;
}


