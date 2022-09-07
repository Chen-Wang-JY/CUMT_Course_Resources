#ifndef FORM_RESELECTION_H
#define FORM_RESELECTION_H

#include <QWidget>

namespace Ui {
class Form_reselection;
}

class Form_reselection : public QWidget
{
    Q_OBJECT

public:
    explicit Form_reselection(QWidget *parent = nullptr);
    ~Form_reselection();


public:
    Ui::Form_reselection *ui;

};

#endif // FORM_RESELECTION_H
