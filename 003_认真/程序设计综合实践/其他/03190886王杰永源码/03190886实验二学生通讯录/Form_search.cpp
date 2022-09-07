#include "Form_search.h"
#include "ui_Form_search.h"

Form_Search::Form_Search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Search)
{
    ui->setupUi(this);
}

Form_Search::~Form_Search()
{
    delete ui;
}

void Form_Search::on_Button_Close_clicked()
{
    this->close();
}
