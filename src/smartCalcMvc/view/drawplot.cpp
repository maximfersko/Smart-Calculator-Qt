#include "drawplot.h"

#include "ui_drawplot.h"

drawPlot::drawPlot(model::controller *controller, QWidget *parent)
    : ui(new Ui::drawPlot), controller_(controller) {
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle("Draw Plot");
}

drawPlot::~drawPlot() { delete ui; }

void drawPlot::on_send_clicked() {
    if (!dots_.first.empty()) dots_.first.clear();
    if (!dots_.second.empty()) dots_.second.clear();
    if (!data_.empty()) data_.clear();
    xBegin_ = ui->xmin->text().toDouble();
    xEnd_ = ui->xmax->text().toDouble();
    double u = ui->ymin->text().toDouble();
    double i = ui->ymax->text().toDouble();
    h_ = 0.1;
    QErrorMessage msg;
    if (xBegin_ == 0 || xEnd_ == 0 || u == 0 || i == 0) {
        msg.showMessage(
            "Your fields are empty or null, please enter non-zero values!");
        msg.exec();
    } else {
        ui->widget->xAxis->setRange(-1 * u, u);
        ui->widget->yAxis->setRange(-1 * i, i);
        data_.push_back(xBegin_);
        data_.push_back(xEnd_);
        std::pair<std::vector<double>, std::vector<double>> tmp;
        try {
            tmp = controller_->graphBuilder(
                data_, ui->lineEdit->text().toStdString());
        } catch (std::invalid_argument &e) {
            msg.showMessage(e.what());
            msg.exec();
        }

        dots_.first = QVector<double>(tmp.first.begin(), tmp.first.end());
        dots_.second = QVector<double>(tmp.second.begin(), tmp.second.end());
        ui->widget->addGraph();
        ui->widget->graph(0)->setData(dots_.first, dots_.second);
        ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->widget->graph(0)->setScatterStyle(
            QCPScatterStyle(QCPScatterStyle::ssCircle, 4.0));
        ui->widget->replot();
        ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom |
                                    QCP::iSelectPlottables);
    }
}
