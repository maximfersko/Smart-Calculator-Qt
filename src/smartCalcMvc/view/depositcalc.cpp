#include "depositcalc.h"
#include "ui_depositcalc.h"

depositcalc::depositcalc(model::controller *dep, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::depositcalc),
    dep_(dep)
{
    ui->setupUi(this);
        setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle("Deposit Calculator");
}

depositcalc::~depositcalc()
{
    delete ui;
}

void depositcalc::on_calculate_clicked()
{
    double summa = ui->summa->value();
    double period = ui->period->value();
    double persent = ui->persents->value();
    double tax = ui->tax->value();
    bool isCapitalization = ui->capitalization->isChecked();
    double refillsSumma = ui->refillSumma->value();
    double refillsDate = ui->refill->value();
    double withdrawSumma = ui->withdrawSumma->value();
    double withdrawDate = ui->withdraw->value();

    dep_->SetParam(summa, period, persent, isCapitalization, true, refillsDate, refillsSumma,withdrawDate, withdrawSumma);
    ui->totalSum->setText(QString::number(dep_->getAmountTotalDeposit()));
    ui->totalrRate->setText(QString::number(dep_->getInterestDeposit()));
    ui->totalTaxRate->setText(QString::number(dep_->getTax()));
}

