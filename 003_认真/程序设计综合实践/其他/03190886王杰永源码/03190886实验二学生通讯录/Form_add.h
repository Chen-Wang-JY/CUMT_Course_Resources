#ifndef FORM_ADD_H
#define FORM_ADD_H

#include <QWidget>

namespace Ui {
class Form_Add;
}

class Form_Add : public QWidget
{
    Q_OBJECT

public:
    explicit Form_Add(QWidget *parent = nullptr);
    ~Form_Add();


    Ui::Form_Add *ui;
private slots:
    void on_Button_Cancel_clicked();
};

#endif // FORM_ADD_H
