#ifndef SRC_MODEL_SMARTCALC_H_
#define SRC_MODEL_SMARTCALC_H_

#include <array>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <vector>
#include <limits>

namespace model {

enum {
    PLUS,
    MINUS,
    DIV,
    MULT,
    POW,
    MOD,
    COS,
    SIN,
    TAN,
    ATAN,
    ACOS,
    ASIN,
    SQRT,
    UPLUS,
    UMINUS,
    LOG,
    LN,
    X,
    DOT,
    CLOSE_BRACKET = -1,
    OPEN_BRACKET = -2,
    null
};

enum { CONST_E = 19, CONST_PI, NUMBER, UNDEFUIEND, OPERATION, EMPTY };

enum { LOW = 1, MID, HIGH, VHIGH, VVHIGH };

class smartCalc {
   public:
    using data = double;
    using stackOperation = std::deque<std::pair<int, int>>;
    using stackNumber = std::deque<std::pair<data, int>>;

   private:
    stackOperation stackOP_;
    stackNumber stackNUM_;
    stackNumber stackRes_;
    size_t it_ = 0;

    void alhoritmAddOperationStack(int token);
    void alhoritmAddBracketsStack();
    void transferStack();
    void check(std::string &str);
    int stringToToken(std::string &str, bool *flag, std::vector<std::pair<char, int>> &elements);
    void alhoritmTransferToPN(std::string &str);
    data getNumToString(std::string &str, data value, size_t *length);
    int getRange(int operation);
    void calcBinary(int token);
    void calcUnary(int token);
    int isUnarOrBinar(int type, bool flag);
    int checkFunction(std::string &str, int type);
    data getPolishNotationX(std::string &str, data x); 
    void validateRPN(const stackNumber &A);
    double calcPloting(std::string, data X);
    void shift(int token);
    void error(std::string str);
   public:
    smartCalc() {}
    ~smartCalc() {}
    void clean();
    data RPN(std::string str);
    data RPN(std::string str, data X);
    std::pair<std::vector<double>, std::vector<double>> graphBuilder(
        std::vector<double> &Data, std::string str);
};

};  // namespace model
#endif
