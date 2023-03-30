#include "deposit.h"

namespace model {

void deposit::calculateDeposit(double amount, double period, double rate,
                               bool capitalization, double taxRate,
                               int replCount, double replAmount,
                               int withdrCount, double withdrAmount) {
    depAmount_ = 0.0;
    depTax_ = 0.0;
    depInterest_ = 0.0;
    if (amount < 0 || period < 0)
        throw std::invalid_argument("Error! Incorrect parameters");
    double monthRate = (((amount / 100.0) * rate) / 12.0);
    int tmpRate = 0;
    if (!capitalization) {
        if (withdrCount != 0 || replCount != 0) {
            double tmp = amount;
            depInterest_ = ((((tmp / 100) * rate) / 12) * period);
            for (int i = 1; i <= period; ++i) {
                tmpRate += depInterest_;
                if (replAmount > 0 && i % replCount == 0) amount += replAmount;
                if (withdrAmount > 0 && i % withdrCount == 0)
                    amount -= withdrAmount;
            }
            depInterest_ -= ((tmp / 100 / 365) * 2);
            depAmount_ = amount;
        } else {
            depInterest_ = (((amount / 100.0) * rate) / 12.0) * period;
            depAmount_ = amount;
        }
        tmpRate += depInterest_;
    } else {
        double monthTax = 0;
        double tmp = amount;
        for (int i = 0; i <= period; ++i) {
            monthRate = ((((tmp / 100.0) * rate) / 12.0));
            monthTax = monthRate * (taxRate / 100.0);
            tmp += monthRate;
            tmpRate += monthTax;
            if (replAmount > 0 && i % replCount == 0) tmp += replAmount;
            if (withdrAmount > 0 && i % withdrCount == 0) tmp -= withdrAmount;
            depInterest_ += monthRate, depInterest_ -= (amount / 100 / 365);
            depAmount_ -= (amount / 100 / 365);
        }
        depInterest_ -= monthRate;
        depInterest_ -= ((amount / 100 / 365));
        depAmount_ = ((tmp - monthRate) + withdrAmount - replAmount) -
                     ((amount / 100 / 365) * 2);
    }
    depTax_ = tmpRate * taxRate;
}

};  // namespace model