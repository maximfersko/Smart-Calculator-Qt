#include "smartCalc.h"

namespace model {

typename smartCalc::data smartCalc::RPN(std::string str) {
    return getPolishNotationX(str, 0);
}

typename smartCalc::data smartCalc::RPN(std::string str, data X) {
    return getPolishNotationX(str, X);
}

void smartCalc::calcBinary(int token) {
    data resultForCalcBinar = 0, first = 0, second = 0;
    first = stackRes_.back().first;
    stackRes_.pop_back();
    second = stackRes_.back().first;
    stackRes_.pop_back();
    if (token == PLUS) {
        resultForCalcBinar = first + second;
    } else if (token == MINUS) {
        resultForCalcBinar = second - first;
    } else if (token == DIV) {
        if (first == 0) error("You can't divide by zero");
        resultForCalcBinar = second / first;
    } else if (token == MULT) {
        resultForCalcBinar = first * second;
    } else if (token == MOD) {
        resultForCalcBinar = fmod(second, first);
    } else if (token == POW) {
        resultForCalcBinar = pow(second, first);
    }
    stackRes_.push_back(std::make_pair(resultForCalcBinar, NUMBER));
}

void smartCalc::calcUnary(int token) {
    data number = stackRes_.back().first;
    stackRes_.pop_back();
    data resultForCalcUnary = 0;
    if (token == COS) {
        resultForCalcUnary = cos(number);
    } else if (token == SIN) {
        resultForCalcUnary = sin(number);
    } else if (token == TAN) {
        resultForCalcUnary = tan(number);
    } else if (token == ACOS) {
        resultForCalcUnary = acos(number);
    } else if (token == ASIN) {
        resultForCalcUnary = asin(number);
    } else if (token == ATAN) {
        resultForCalcUnary = atan(number);
    } else if (token == SQRT) {
        resultForCalcUnary = sqrt(number);
    } else if (token == LN) {
        resultForCalcUnary = log(number);
    } else if (token == LOG) {
        resultForCalcUnary = log10(number);
    } else if (token == UMINUS) {
        resultForCalcUnary = number * -1;
    } else if (token == UPLUS) {
        resultForCalcUnary = number;
    }
    stackRes_.push_back(std::make_pair(resultForCalcUnary, NUMBER));
}

smartCalc::data smartCalc::getPolishNotationX(std::string &str, data x) {
    alhoritmTransferToPN(str);
    std::deque<std::pair<double, int>> items(stackNUM_);
    for (auto &item : items) {
        if (item.second == NUMBER) {
            stackRes_.push_back(std::make_pair(item.first, NUMBER));
        } else if (item.first >= PLUS && item.first <= MOD) {
            if (stackRes_.size() < 2) error("Error calculation !");
            calcBinary(item.first);
        } else if (item.first >= COS && item.first <= LN) {
            if (stackRes_.size() < 1) error("Error calculation !");
            calcUnary(item.first);
        } else if (item.second == X) {
            stackRes_.push_back(std::make_pair(x, NUMBER));
        }
    }
    stackNUM_.clear();
    data result = 0;
    if (stackRes_.size() > 1 || stackRes_.empty()) error("Error calculation !");
    result = stackRes_.back().first;
    clean();
    return result;
}

void smartCalc::clean() {
    stackNUM_.clear();
    stackOP_.clear();
    stackRes_.clear();
    it_ = 0;
}

};  // namespace model
