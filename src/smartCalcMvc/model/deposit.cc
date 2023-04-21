#include "deposit.h"

namespace model {

void deposit::calculateDeposit(DepositData &params) {
  depAmount_ = 0.0;
  depTax_ = 0.0;
  depInterest_ = 0.0;
  if (params.amount < 0 || params.period < 0)
    throw std::invalid_argument("Error! Incorrect parameters");
  double monthRate = (((params.amount / 100.0) * params.rate) / 12.0);
  int tmpRate = 0;
  if (!params.capitalization) {
    if (params.withdrCount != 0 || params.replCount != 0) {
      double tmp = params.amount;
      depInterest_ = ((((tmp / 100) * params.rate) / 12) * params.period);
      for (int i = 1; i <= params.period; ++i) {
        tmpRate += depInterest_;
        if (params.replAmount > 0 && i % params.replCount == 0)
          params.amount += params.replAmount;
        if (params.withdrAmount > 0 && i % params.withdrCount == 0)
          params.amount -= params.withdrAmount;
      }
      depInterest_ -= ((tmp / 100 / 365) * 2);
      depAmount_ = params.amount;
    } else {
      depInterest_ =
          (((params.amount / 100.0) * params.rate) / 12.0) * params.period;
      depAmount_ = params.amount;
    }
    tmpRate += depInterest_;
  } else {
    double monthTax = 0;
    double tmp = params.amount;
    for (int i = 0; i <= params.period; ++i) {
      monthRate = ((((tmp / 100.0) * params.rate) / 12.0));
      monthTax = monthRate * (params.taxRate / 100.0);
      tmp += monthRate;
      tmpRate += monthTax;
      if (params.replAmount > 0 && i % params.replCount == 0)
        tmp += params.replAmount;

      if (params.withdrAmount > 0 && i % params.withdrCount == 0)
        tmp -= params.withdrAmount;

      depInterest_ += monthRate, depInterest_ -= (params.amount / 100 / 365);
      depAmount_ -= (params.amount / 100 / 365);
    }
    depInterest_ -= monthRate;
    depInterest_ -= ((params.amount / 100 / 365));
    depAmount_ = ((tmp - monthRate) + params.withdrAmount - params.replAmount) -
                 ((params.amount / 100 / 365) * 2);
  }
  depTax_ = tmpRate * params.taxRate;
}

}; // namespace model
