#include "credit.h"

#include "ui_credit.h"

credit::credit(model::controller *controller, QWidget *parent)
    : QWidget(parent), ui(new Ui::credit), controller_(controller) {
    ui->setupUi(this);
    ui->monthlyPay->setReadOnly(true);
    ui->overPay->setReadOnly(true);
    ui->totalPay->setReadOnly(true);
    setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle("Credit Calculator");
}

credit::~credit() { delete ui; }

void credit::on_calc_clicked() {
    QErrorMessage errorMsg;
    double summa = ui->summa->value();
    double period = ui->period->value();
    double p = ui->present->value();
    if (ui->annuity->isChecked()) {
        try {
            auto a = controller_->Annuity(summa, period, p);
            ui->monthlyPay->setText(QString::number(a.monthlyPayment));
            ui->overPay->setText(QString::number(a.overPayment));
            ui->totalPay->setText(QString::number(a.totalPayment));
        } catch (std::invalid_argument &e) {
            errorMsg.showMessage(e.what());
            errorMsg.exec();
        }
    } else if (ui->diff->isChecked()) {
        try {
            auto d = controller_->deffirentated(summa, period, p);
            ui->monthlyPay->setText(QString::number(d.maxMonthlyPayment) +
                                    "..." +
                                    QString::number(d.minMonthlyPayment));
            ui->overPay->setText(QString::number(d.overPayment));
            ui->totalPay->setText(QString::number(d.totalPayment));
        } catch (std::invalid_argument &e) {
            errorMsg.showMessage(e.what());
            errorMsg.exec();
        }
    } else if (!ui->annuity->isChecked() && !ui->diff->isChecked()) {
        errorMsg.showMessage("Please select the type of loan!");
        errorMsg.exec();
    }
    if (summa == 0 || period == 0 || p == 0) {
        errorMsg.showMessage(
            "Your fields are empty or null, please enter non-zero values!");
        errorMsg.exec();
        ui->monthlyPay->setText("Error");
        ui->overPay->setText("Error");
        ui->totalPay->setText("Error");
    }
}
