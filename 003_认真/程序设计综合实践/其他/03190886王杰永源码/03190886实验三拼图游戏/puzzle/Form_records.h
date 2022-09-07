#ifndef FORM_RECORDS_H
#define FORM_RECORDS_H

#include <QWidget>

namespace Ui {
class Form_records;
}

class Form_records : public QWidget
{
    Q_OBJECT

public:
    explicit Form_records(QWidget *parent = nullptr);
    ~Form_records();

public:
    Ui::Form_records *ui;
private slots:
    void Zero();
};

#endif // FORM_RECORDS_H
