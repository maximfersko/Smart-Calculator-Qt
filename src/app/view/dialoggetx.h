#ifndef DIALOGGETX_H
#define DIALOGGETX_H

#include <QWidget>
#include <QErrorMessage>

namespace Ui {
class dialogGetX;
}

namespace model {

class dialogGetX : public QWidget {
    Q_OBJECT

   private:
    Ui::dialogGetX *ui;

   private slots:
    void on_pushButton_clicked();

   public:
    explicit dialogGetX(QWidget *parent = nullptr);
    ~dialogGetX();

   signals:
    void signalF(QString str);
};

}  // namespace model
#endif  // DIALOGGETX_H
