#ifndef DEPOSITCALC_H
#define DEPOSITCALC_H

#include <QWidget>
#include "../controller/controller.h"
namespace Ui {
class depositcalc;
}

class depositcalc : public QWidget
{
    Q_OBJECT

public:
    explicit depositcalc(model::controller *dep, QWidget *parent = nullptr);
    ~depositcalc();

private slots:
    void on_calculate_clicked();

private:
    Ui::depositcalc *ui;
    model::controller *dep_;
};

#endif // DEPOSITCALC_H
