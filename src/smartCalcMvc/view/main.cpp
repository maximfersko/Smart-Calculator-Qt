#include <QApplication>

#include "mainwindow.h"

using namespace model;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    model::smartCalc model;
    model::creditModel credit;
    model::deposit deposit;
    model::controller controller(&model, &credit, &deposit);
    MainWindow w(&controller);
    w.show();
    return a.exec();
}
