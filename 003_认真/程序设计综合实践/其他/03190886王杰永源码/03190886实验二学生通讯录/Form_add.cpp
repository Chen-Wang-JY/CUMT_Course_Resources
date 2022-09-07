#include "Form_add.h"
#include "ui_Form_add.h"

Form_Add::Form_Add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Add)
{
    ui->setupUi(this);

    //限定学号
    QRegExp regx("[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]");
    QValidator *validator = new QRegExpValidator(regx, ui->Edit_ID );
    ui->Edit_ID->setValidator(validator);

    //限定手机号码
    QRegExp regx1("[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]");
    QValidator *validator1 = new QRegExpValidator(regx1, ui->Edit_Tell );
    ui->Edit_Tell->setValidator(validator1);

    //限定年龄
    QRegExp regx2("[0-9]+$");
    QValidator *validator2 = new QRegExpValidator(regx1, ui->Edit_Age );
    ui->Edit_Age->setValidator(validator2);

    //限定qq号码
    QRegExp regx3("[0-9]+$");
    QValidator *validator3 = new QRegExpValidator(regx1, ui->Edit_QQNum );
    ui->Edit_QQNum->setValidator(validator3);


}

Form_Add::~Form_Add()
{
    delete ui;
}

void Form_Add::on_Button_Cancel_clicked()
{
    this->close();
}
