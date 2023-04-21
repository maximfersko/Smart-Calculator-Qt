#ifndef SRC_MODEL_DEPOSIT_H_
#define SRC_MODEL_DEPOSIT_H_

#include <cmath>
#include <iostream>

namespace model {

struct DepositData {
  double amount;
  double period;
  double rate;
  bool capitalization;
  double taxRate;
  int replCount;
  double replAmount;
  int withdrCount;
  double withdrAmount;

  DepositData(double amount, double period, double rate, bool capitalization,
              double taxRate, int replCount, double replAmount, int withdrCount,
              double withdrAmount) {
    this->amount = amount;
    this->period = period;
    this->rate = rate;
    this->capitalization = capitalization;
    this->taxRate = taxRate;
    this->replCount = replCount;
    this->replAmount = replAmount;
    this->withdrCount = withdrCount;
    this->withdrAmount = withdrAmount;
  }
};

class deposit {
private:
  double depAmount_{};
  double depInterest_{};
  double depTax_{};

public:
  deposit() = default;
  ~deposit() = default;
  void calculateDeposit(DepositData &params);
  double getDepAmount() { return depAmount_; }
  double getInterest() { return depInterest_; }
  double getTax() { return depTax_; }
};

}; // namespace model

#endif
