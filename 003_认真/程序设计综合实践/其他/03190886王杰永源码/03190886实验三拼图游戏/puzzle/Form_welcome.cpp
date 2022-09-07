#include "Form_welcome.h"
#include "ui_Form_welcome.h"
#include "Mainwindow.h"

Form_welcome::Form_welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_welcome)
{
    ui->setupUi(this);

    QRegExp regx("[1-9][0-9]+$");
    QValidator *validator = new QRegExpValidator(regx, ui->Edit_custom );
    ui->Edit_custom->setValidator(validator);
}

Form_welcome::~Form_welcome()
{
    delete ui;
}


void Form_welcome::on_Button_easy_clicked()
{
    w.N=3;
    this->close();
    w.Load();
    w.show();
}

void Form_welcome::on_Button_hard_clicked()
{
    w.N=4;
    this->close();
    w.Load();
    w.show();
}

void Form_welcome::on_Button_hell_clicked()
{
    w.N=5;
    this->close();
    w.Load();
    w.show();
}

void Form_welcome::on_Button_comfirm_clicked()
{
    if(ui->Edit_custom->text().isEmpty()){
        QMessageBox::warning(this,"警告","自定义难度不能为空!");
        return ;
    }
    int N=ui->Edit_custom->text().toUtf8().toInt();
    w.N=N;
    QMessageBox::about(this," ","祝你好运!");
    this->close();
    w.Load();
    w.show();
}
