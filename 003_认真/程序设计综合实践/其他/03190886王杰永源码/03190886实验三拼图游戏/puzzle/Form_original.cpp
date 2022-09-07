#include "Form_original.h"
#include "ui_Form_original.h"

Form_original::Form_original(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_original)
{
    ui->setupUi(this);
}

Form_original::~Form_original()
{
    delete ui;
}
