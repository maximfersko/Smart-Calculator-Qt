#ifndef SRC_CONTROLLER_CONTROLLER_H_
#define SRC_CONTROLLER_CONTROLLER_H_
#include "../model/creditModel.h"
#include "../model/deposit.h"
#include "../model/smartCalc.h"

namespace model {

class controller {
public:
  using data_t_credit = creditModel::data_c_t_;

private:
  SmartCalc *model_;
  creditModel *creditModel_;
  deposit *depositModel_;

public:
  controller()
      : model_(nullptr), creditModel_(nullptr), depositModel_(nullptr) {}
  controller(SmartCalc *model, creditModel *modelCredit, deposit *depositModel);
  double RPN(std::string str);
  double RPN(std::string str, double X);
  void clean();
  double getAmountTotalDeposit();
  double getInterestDeposit();
  double getTax();
  void SetParam(DepositData params);
  std::pair<std::vector<double>, std::vector<double>>
  graphBuilder(std::vector<double> &Data, std::string str);
  data_t_credit Annuity(double summa, double period, double rate);
  data_t_credit deffirentated(double summa, double rate, double period);
  ~controller() {}
};

}; // namespace model
#endif