#include "Form_records.h"
#include "ui_Form_records.h"
#include <QFile>
#include <QDebug>

Form_records::Form_records(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_records)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&Form_records::Zero);
}

Form_records::~Form_records()
{
    delete ui;
}
void Form_records::Zero(){
        QFile file("record.txt");
        file.open(QFile::WriteOnly|QFile::Truncate);
        file.close();
}
