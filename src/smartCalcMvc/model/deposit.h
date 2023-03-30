#ifndef SRC_MODEL_DEPOSIT_H_
#define SRC_MODEL_DEPOSIT_H_

#include <iostream>
#include <cmath>

namespace model {

class deposit {
   private:
    double depAmount_ = 0.0;
    double depInterest_ = 0.0;
    double depTax_ = 0.0;
   public:
   deposit() {}
   ~deposit() {}
    void calculateDeposit(double amount, double period, double rate,
                               bool capitalization, double taxRate,
                               int replCount, double replAmount,
                               int withdrCount, double withdrAmount);
    double getDepAmount() { return depAmount_; }
    double getInterest() { return depInterest_; }
    double getTax() { return depTax_; }
};

};  // namespace model

#endif