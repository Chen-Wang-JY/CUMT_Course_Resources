#include "history.h"
#include "ui_history.h"

History::History(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::History)
{
    ui->setupUi(this);

    //更改窗口属性
    setWindowTitle("历史记录");
}

History::~History()
{
    delete ui;
}
