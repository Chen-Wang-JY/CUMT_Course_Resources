#ifndef FORM_CHOSEIMG_H
#define FORM_CHOSEIMG_H

#include <QWidget>

namespace Ui {
class Form_choseimg;
}

class Form_choseimg : public QWidget
{
    Q_OBJECT

public:
    explicit Form_choseimg(QWidget *parent = nullptr);
    ~Form_choseimg();

private slots:

public:
    Ui::Form_choseimg *ui;
};

#endif // FORM_CHOSEIMG_H
