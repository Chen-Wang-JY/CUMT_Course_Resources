#include "Form_reselection.h"
#include "ui_Form_reselection.h"
#include "Form_welcome.h"

Form_reselection::Form_reselection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_reselection)
{
    ui->setupUi(this);
    QRegExp regx("[1-9][0-9]+$");
    QValidator *validator = new QRegExpValidator(regx, ui->Edit_custom );
    ui->Edit_custom->setValidator(validator);
}

Form_reselection::~Form_reselection()
{
    delete ui;
}
