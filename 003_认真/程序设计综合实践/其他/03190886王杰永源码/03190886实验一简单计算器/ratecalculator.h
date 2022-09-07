#ifndef RATECALCULATOR_H
#define RATECALCULATOR_H

#include <QWidget>

namespace Ui {
class RateCalculator;
}

class RateCalculator : public QWidget
{
    Q_OBJECT

public:
    explicit RateCalculator(QWidget *parent = nullptr);
    ~RateCalculator();

private slots:
    void on_Button_back_clicked();

    void on_pushButton_clicked();

private:
    Ui::RateCalculator *ui;
};

#endif // RATECALCULATOR_H
