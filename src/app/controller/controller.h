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
  std::unique_ptr<SmartCalc> model_;
  std::unique_ptr<creditModel> creditModel_;
  std::unique_ptr<deposit> depositModel_;

public:
  controller() = default;
  ~controller() = default;
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
};

}; // namespace model
#endif