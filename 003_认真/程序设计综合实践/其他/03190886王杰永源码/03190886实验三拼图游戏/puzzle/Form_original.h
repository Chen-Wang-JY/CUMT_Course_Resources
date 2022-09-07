#ifndef FORM_ORIGINAL_H
#define FORM_ORIGINAL_H

#include <QWidget>

namespace Ui {
class Form_original;
}

class Form_original : public QWidget
{
    Q_OBJECT

public:
    explicit Form_original(QWidget *parent = nullptr);
    ~Form_original();

public:
    Ui::Form_original *ui;
};

#endif // FORM_ORIGINAL_H
