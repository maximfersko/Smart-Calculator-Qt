#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QErrorMessage>
#include <QMainWindow>

#include "../controller/controller.h"
#include "credit.h"
#include "dialoggetx.h"
#include "drawplot.h"
#include "depositcalc.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
namespace model {

class MainWindow : public QMainWindow {
    Q_OBJECT

   private:
    Ui::MainWindow *ui;
    model::controller *controller_;
    dialogGetX *dialog_;
    drawPlot *graph_;
    credit *creditModel_;
    depositcalc *deposit_;

   private slots:
    void getNumbers();
    void on_pushButton_dot_clicked();
    void operations();
    void on_pushButton_equal_clicked();
    void mathFunc();
    void on_pushButton_clear_clicked();
    void connectButtons();
    void on_actioncredit_calc_triggered();
    void init();
    void on_actionsmartCalc_triggered();

    void on_actiondeposit_calc_triggered();

public:
    MainWindow(model::controller *controller, QWidget *parent = nullptr);
    ~MainWindow();

   public slots:
    void slotF(QString str);
};

}  // namespace model
#endif  // MAINWINDOW_H
