#include "dialoggetx.h"

#include "ui_dialoggetx.h"

using namespace model;

dialogGetX::dialogGetX(QWidget *parent)
    : QWidget(parent), ui(new Ui::dialogGetX) {
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle("Replace X");
}

dialogGetX::~dialogGetX() { delete ui; }

void dialogGetX::on_pushButton_clicked() {
    QErrorMessage msg;
    if (ui->lineNum->value() == 0) {
        msg.showMessage("Error! x != 0");
        msg.exec();
    } else {
        emit signalF(ui->lineNum->text());
        hide();
    }
}
