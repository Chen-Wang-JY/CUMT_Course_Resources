#ifndef FORM_SEARCH_H
#define FORM_SEARCH_H

#include <QWidget>

namespace Ui {
class Form_Search;
}

class Form_Search : public QWidget
{
    Q_OBJECT

public:
    explicit Form_Search(QWidget *parent = nullptr);
    ~Form_Search();

private slots:
    void on_Button_Close_clicked();

public:
    Ui::Form_Search *ui;
};

#endif // FORM_SEARCH_H
