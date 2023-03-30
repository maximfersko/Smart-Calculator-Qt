#include <algorithm>
#include <array>

#include "smartCalc.h"

namespace model {

void smartCalc::shift(int token) {
    if (token != NUMBER) ++it_;
    if ((token >= COS && token <= TAN) || (token == LOG)) {
        it_ += 2;
    } else if (token >= ATAN && token <= SQRT) {
        it_ += 3;
    }
}

void smartCalc::error(std::string str) {
    clean();
    throw std::invalid_argument(str);
}

int smartCalc::checkFunction(std::string &str, int type) {
    int token = UNDEFUIEND;
    if (type == COS && str.substr(it_, 3) == "cos") {
        token = COS;
    } else if (type == TAN && str.substr(it_, 3) == "tan") {
        token = TAN;
    } else if (type == SIN) {
        if (str.substr(it_, 3) == "sin")
            token = SIN;
        else if (str.substr(it_, 4) == "sqrt")
            token = SQRT;
    } else if (type == ACOS) {
        if (str.substr(it_, 4) == "acos")
            token = ACOS;
        else if (str.substr(it_, 4) == "asin")
            token = ASIN;
        else if (str.substr(it_, 4) == "atan")
            token = ATAN;
    } else if (type == LN) {
        if (str.substr(it_, 2) == "ln")
            token = LN;
        else if (str.substr(it_, 3) == "log")
            token = LOG;
    }
    return token;
}

int smartCalc::isUnarOrBinar(int type, bool flag) {
    int result = UNDEFUIEND;
    if (!flag && type == PLUS) {
        result = PLUS;
    } else if (!flag && type == MINUS) {
        result = MINUS;
    } else if (flag && type == PLUS) {
        result = UPLUS;
    } else if (flag && type == MINUS) {
        result = UMINUS;
    }
    return result;
}

int smartCalc::stringToToken(std::string &str, bool *flag,
                             std::vector<std::pair<char, int>> &elements) {
    int result = UNDEFUIEND;
    if (str[it_] == ' ') {
        ++it_;
    } else {
        if (isdigit(str[it_]) > 0) {
            result = NUMBER;
            *flag = false;
        } else {
            for (auto &elm : elements) {
                if (str[it_] == elm.first) {
                    result = elm.second;
                    if (result == DIV || result == MULT || result == MOD) {
                        *flag = true;
                    } else if (result == CONST_E || result == CONST_PI ||
                               result == X) {
                        *flag = false;
                    } else if (result == PLUS || result == MINUS) {
                        result = isUnarOrBinar(result, *flag);
                    } else if (result == COS || result == SIN ||
                               result == ACOS || result == LN ||
                               result == TAN) {
                        result = checkFunction(str, result);
                        if (result == UNDEFUIEND)
                            error("invalid expressions !");
                    }
                    break;
                }
            }
        }
        shift(result);
    }
    return result;
}

smartCalc::data smartCalc::getNumToString(std::string &str, data value,
                                          size_t *length) {
    data result = 0;
    if (value == NUMBER) {
        result = std::stod(str, length);
    } else {
        result = value == CONST_PI ? M_PI : value == CONST_E ? M_E : 0;
        *length += 1;
    }
    return result;
}

int smartCalc::getRange(int operation) {
    int result = 0;
    if (operation == PLUS || operation == MINUS) {
        result = LOW;
    } else if (operation == DIV || operation == MULT || operation == MOD) {
        result = MID;
    } else if (operation == POW) {
        result = HIGH;
    } else if (operation == UMINUS || operation == UPLUS) {
        result = VHIGH;
    } else if ((operation >= COS && operation <= LN) &&
               (operation != UPLUS && operation != UMINUS)) {
        result = VVHIGH;
    }
    return result;
}

void smartCalc::alhoritmTransferToPN(std::string &str) {
    check(str);
    bool flag = true;
    if (str.length() == 0) error("empty str !");
    std::vector<std::pair<char, int>> elements{
        {'+', PLUS}, {'-', MINUS},   {'/', DIV},          {'*', MULT},
        {'%', MOD},  {'^', POW},     {'(', OPEN_BRACKET}, {')', CLOSE_BRACKET},
        {'c', COS},  {'s', SIN},     {'a', ACOS},         {'l', LN},
        {'x', X},    {'e', CONST_E}, {'p', CONST_PI},     {'t', TAN},
        {'.', DOT}};
    do {
        int token = stringToToken(str, &flag, elements);
        if (token == DOT) error("invalid expressions !");
        if (token >= CONST_E && token <= NUMBER) {
            std::string num = str.substr(it_);
            size_t len = 0;
            stackNUM_.push_back(
                std::make_pair(getNumToString(num, token, &len), NUMBER));
            it_ += len;
        } else if (token == OPEN_BRACKET) {
            stackOP_.push_back(std::make_pair(token, OPERATION));
        } else if (token == CLOSE_BRACKET) {
            alhoritmAddBracketsStack();
        } else if (token >= PLUS && token <= LN) {
            alhoritmAddOperationStack(token);
        } else if (token == X) {
            stackNUM_.push_back(std::make_pair(token, X));
        }
    } while (str[it_]);
    transferStack();
    validateRPN(stackNUM_);
}

void smartCalc::alhoritmAddOperationStack(int token) {
    if (stackOP_.empty() ||
        getRange((stackOP_.back().first)) < getRange(token)) {
        stackOP_.push_back(std::make_pair(token, OPERATION));
    } else {
        while (!stackOP_.empty()) {
            if (getRange(stackOP_.back().first) >= getRange(token)) {
                stackNUM_.push_back(
                    std::make_pair(stackOP_.back().first, OPERATION));
                stackOP_.pop_back();
            } else {
                break;
            }
        }
        stackOP_.push_back(std::make_pair(token, OPERATION));
    }
}

void smartCalc::alhoritmAddBracketsStack() {
    int tmp = stackOP_.back().first;
    stackOP_.pop_back();
    while (!stackOP_.empty() && tmp != OPEN_BRACKET) {
        stackNUM_.push_back(std::make_pair(tmp, OPERATION));
        tmp = stackOP_.back().first;
        stackOP_.pop_back();
    }
}

void smartCalc::transferStack() {
    while (!stackOP_.empty()) {
        stackNUM_.push_back(std::make_pair(stackOP_.back().first, OPERATION));
        stackOP_.pop_back();
    }
}

};  // namespace model
