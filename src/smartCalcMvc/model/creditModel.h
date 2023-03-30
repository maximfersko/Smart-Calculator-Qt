#ifndef SRC_MODEL_CREDITMODEL_H_
#define SRC_MODEL_CREDITMODEL_H_

#include <cmath>
#include <iostream>
namespace model {

struct creditData {
    double totalPayment = 0;
    double monthlyPayment = 0;
    double overPayment = 0;
    double minMonthlyPayment = 0;
    double maxMonthlyPayment = 0;
};

class creditModel {
   public:
    using data_c_t_ = creditData;

   private:
    data_c_t_ data_;

   public:
    creditModel() {}
    ~creditModel() {}

    void annuity(double summa, double period, double rate);
    void deffirentated(double summa, double rate, double period);
    void validate(double period, double rate, double creditSum);
    double round(double number);
    void clear();
    data_c_t_ getResult() { return data_; }
};

};  // namespace model
#endif