#ifndef CREDIT_H
#define CREDIT_H

#include <QErrorMessage>
#include <QWidget>

#include "../controller/controller.h"

namespace Ui {
class credit;
}

class credit : public QWidget {
    Q_OBJECT

   private slots:
    void on_calc_clicked();

   private:
    Ui::credit *ui;
    model::controller *controller_;

   public:
    explicit credit(model::controller *controller, QWidget *parent = nullptr);
    ~credit();
};

#endif  // CREDIT_H
