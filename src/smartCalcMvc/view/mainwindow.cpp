#include "mainwindow.h"

#include "ui_mainwindow.h"

using namespace model;

MainWindow::MainWindow(model::controller *controller, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller_(controller) {
    ui->setupUi(this);
    init();
    connectButtons();
    creditModel_->hide();
    this->setWindowTitle("Smart Calculator");
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::init() {
    this->setWindowTitle("smartCalc v2.0 by gwakame");
    dialog_ = new dialogGetX;
    graph_ = new drawPlot(controller_, this);
    creditModel_ = new credit(controller_);
    deposit_ = new depositcalc(controller_);
}

void MainWindow::connectButtons() {
    connect(dialog_, &dialogGetX::signalF, this, &MainWindow::slotF);
    connect(ui->pushButton_num0, SIGNAL(clicked()), this, SLOT(getNumbers()));
    connect(ui->pushButton_num1, SIGNAL(clicked()), this, SLOT(getNumbers()));
    connect(ui->pushButton_num2, SIGNAL(clicked()), this, SLOT(getNumbers()));
    connect(ui->pushButton_num3, SIGNAL(clicked()), this, SLOT(getNumbers()));
    connect(ui->pushButton_num4, SIGNAL(clicked()), this, SLOT(getNumbers()));
    connect(ui->pushButton_num5, SIGNAL(clicked()), this, SLOT(getNumbers()));
    connect(ui->pushButton_num6, SIGNAL(clicked()), this, SLOT(getNumbers()));
    connect(ui->pushButton_num7, SIGNAL(clicked()), this, SLOT(getNumbers()));
    connect(ui->pushButton_num8, SIGNAL(clicked()), this, SLOT(getNumbers()));
    connect(ui->pushButton_num9, SIGNAL(clicked()), this, SLOT(getNumbers()));
    connect(ui->pushButton_clear, SIGNAL(clicked()), this, SLOT(getNumbers()));
    connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(mathFunc()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(getNumbers()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(mathFunc()));
    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(mathFunc()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(mathFunc()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(mathFunc()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(mathFunc()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(mathFunc()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(mathFunc()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(mathFunc()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(mathFunc()));
    connect(ui->pushButton_graph, SIGNAL(clicked()), this, SLOT(mathFunc()));
    connect(ui->pushButton_openB, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_closeB, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_p, SIGNAL(clicked()), this, SLOT(getNumbers()));
    connect(ui->pushButton_e, SIGNAL(clicked()), this, SLOT(getNumbers()));
    connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(getNumbers()));
    connect(ui->input, SIGNAL(clicked()), this, SLOT(getNumbers()));
}

void MainWindow::getNumbers() {
    QPushButton *btn = (QPushButton *)sender();
    if (btn->text() == "0") {
        ui->input->setText(ui->input->text() + "0");
    } else if (btn->text() == "1") {
        ui->input->setText(ui->input->text() + "1");
    } else if (btn->text() == "2") {
        ui->input->setText(ui->input->text() + "2");
    } else if (btn->text() == "3") {
        ui->input->setText(ui->input->text() + "3");
    } else if (btn->text() == "4") {
        ui->input->setText(ui->input->text() + "4");
    } else if (btn->text() == "5") {
        ui->input->setText(ui->input->text() + "5");
    } else if (btn->text() == "6") {
        ui->input->setText(ui->input->text() + "6");
    } else if (btn->text() == "7") {
        ui->input->setText(ui->input->text() + "7");
    } else if (btn->text() == "8") {
        ui->input->setText(ui->input->text() + "8");
    } else if (btn->text() == "9") {
        ui->input->setText(ui->input->text() + "9");
    } else if (btn->text() == "p") {
        ui->input->setText(ui->input->text() + "p");
    } else if (btn->text() == "e") {
        ui->input->setText(ui->input->text() + "e");
    } else if (btn->text() == "x") {
        ui->input->setText(ui->input->text() + "x");
    }
}

void MainWindow::operations() {
    QPushButton *button = (QPushButton *)sender();
    if (button->text() == "+") {
        ui->input->setText(ui->input->text() + " " + '+' + " ");
    } else if (button->text() == '-') {
        ui->input->setText(ui->input->text() + " " + '-' + " ");
    } else if (button->text() == "﹡") {
        ui->input->setText(ui->input->text() + " " + "*" + " ");
    } else if (button->text() == "÷") {
        ui->input->setText(ui->input->text() + " " + '/' + " ");
    } else if (button->text() == "(") {
        ui->input->setText(ui->input->text() + " " + '(' + " ");
    } else if (button->text() == ")") {
        ui->input->setText(ui->input->text() + " " + ')' + " ");
    } else if (button->text() == "^") {
        ui->input->setText(ui->input->text() + " " + '^' + " ");
    }
}

void MainWindow::mathFunc() {
    QPushButton *btn = (QPushButton *)sender();
    if (btn->text() == "cos") {
        ui->input->setText(ui->input->text() + "cos(" + " ");
    } else if (btn->text() == "sin") {
        ui->input->setText(ui->input->text() + "sin(" + " ");
    } else if (btn->text() == "acos") {
        ui->input->setText(ui->input->text() + "acos(" + " ");
    } else if (btn->text() == "asin") {
        ui->input->setText(ui->input->text() + "asin(" + " ");
    } else if (btn->text() == "atan") {
        ui->input->setText(ui->input->text() + "atan(" + " ");
    } else if (btn->text() == "tan") {
        ui->input->setText(ui->input->text() + "tan(" + " ");
    } else if (btn->text() == "log") {
        ui->input->setText(ui->input->text() + "log(" + " ");
    } else if (btn->text() == "ln") {
        ui->input->setText(ui->input->text() + "ln(" + " ");
    } else if (btn->text() == "sqrt") {
        ui->input->setText(ui->input->text() + "sqrt(" + " ");
    } else if (btn->text() == "mod") {
        ui->input->setText(ui->input->text() + " " + "%" + " ");
    } else if (btn->text() == "graph") {
        graph_->show();
    }
}

void MainWindow::on_pushButton_clear_clicked() {
    ui->input->clear();
    ui->output->clear();
    controller_->clean();
}

void MainWindow::on_pushButton_dot_clicked() {
    if (!(ui->input->text().contains('.')))
        ui->input->setText(ui->input->text() + ".");
}

void MainWindow::slotF(QString str) {
    QErrorMessage msg;
    QString qstr = ui->input->text();
    std::string strf = qstr.toStdString();
    try {
        double result = controller_->RPN(qstr.toStdString(), str.toDouble());
        ui->output->setNum(result);
    } catch (std::invalid_argument const &e) {
        msg.showMessage(e.what());
        msg.exec();
        ui->output->setText("Error");
    }
}

void MainWindow::on_pushButton_equal_clicked() {
    QErrorMessage msg;
    QString qstr = ui->input->text();
    if (qstr.contains("x")) {
        dialog_->show();
    } else {
        try {
            double result = controller_->RPN(qstr.toStdString());
            ui->output->setText(QString::number(result));
        } catch (std::invalid_argument const &e) {
            msg.showMessage(e.what());
            msg.exec();
            ui->output->setText("Error");
        }
    }
}

void MainWindow::on_actioncredit_calc_triggered() {
    deposit_->hide();
    this->hide();
    creditModel_->show();
}

void MainWindow::on_actionsmartCalc_triggered() {
    deposit_->hide();
    creditModel_->hide();
    this->show();
}

void MainWindow::on_actiondeposit_calc_triggered()
{
    creditModel_->hide();
    this->hide();
    deposit_->show();
}

