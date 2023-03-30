#ifndef DRAWPLOT_H
#define DRAWPLOT_H
#include <QWidget>

#include "../controller/controller.h"

namespace Ui {
class drawPlot;
}

class drawPlot : public QWidget {
    Q_OBJECT

   private:
    Ui::drawPlot *ui;
    double xBegin_, xEnd_, h_, X_;
    int N_;
    QVector<double> x_, y_;
    model::controller *controller_;
    std::pair<QVector<double>, QVector<double>> dots_;
    std::vector<double> data_;

   private slots:
    void on_send_clicked();

   public:
    drawPlot(model::controller *controller, QWidget *parent = nullptr);
    ~drawPlot();
};

#endif  // DRAWPLOT_H
