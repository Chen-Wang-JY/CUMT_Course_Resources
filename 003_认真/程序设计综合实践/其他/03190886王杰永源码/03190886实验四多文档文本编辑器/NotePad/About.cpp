#include "About.h"
#include "ui_About.h"
#include <QIcon>

About::About(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/icon/关于.png"));
}

About::~About()
{
    delete ui;
}
