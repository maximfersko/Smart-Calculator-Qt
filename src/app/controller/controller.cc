#include "controller.h"

namespace model {

controller::controller(SmartCalc *model, creditModel *modelCredit,
                       deposit *depositModel)
    : model_(model), creditModel_(modelCredit), depositModel_(depositModel) {}

double controller::RPN(std::string str, double X) {
  return model_->RPN(str, X);
}

void controller::clean() { model_->clean(); }

double controller::RPN(std::string str) { return model_->RPN(str, 0); }

std::pair<std::vector<double>, std::vector<double>>
controller::graphBuilder(std::vector<double> &Data, std::string str) {
  return model_->graphBuilder(Data, str);
}

typename controller::data_t_credit
controller::Annuity(double summa, double period, double rate) {
  creditModel_->annuity(summa, period, rate);
  return creditModel_->getResult();
}

typename controller::data_t_credit
controller::deffirentated(double summa, double period, double rate) {
  creditModel_->deffirentated(summa, rate, period);
  return creditModel_->getResult();
}

void controller::SetParam(DepositData params) {
  depositModel_->calculateDeposit(params);
}

double controller::getAmountTotalDeposit() {
  return depositModel_->getDepAmount();
}

double controller::getTax() { return depositModel_->getTax(); }

double controller::getInterestDeposit() { return depositModel_->getInterest(); }

}; // namespace model
