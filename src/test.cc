#include <gtest/gtest.h>

#include "./smartCalcMvc/model/creditModel.h"
#include "./smartCalcMvc/model/deposit.h"
#include "./smartCalcMvc/model/smartCalc.h"

TEST(RPN, case1) {
    model::SmartCalc model;
    double result = model.RPN(
        "(15 / ( 7 - ( 1 + 1 ) ) * 3 - ( 2 + ( 1 + 1 ) ) * 15 / ( 7 - ( 200 + "
        "1 "
        ") ) * 3 - ( 2 + ( 1 + 1 ) ) * ( 15 / ( 7 - ( 1 + 1 ) ) * 3 - ( 2 + ( "
        "1 "
        "+ 1 ) ) +  15 / ( 7 - ( 1 + 1 ) ) * 3 - ( 2 + ( 1 + 1 ) ) ) * "
        "100.072165)");
    ASSERT_EQ(-3993, round(result));
}

TEST(RPN, case2) {
    model::SmartCalc model;
    double result = model.RPN("3 * ( ( sqrt(9) ^ sqrt(9) ) ^ 2)");
    ASSERT_EQ(3 * (pow((pow(sqrt(9), sqrt(9))), 2)), result);
}

TEST(RPN, case3) {
    model::SmartCalc model;
    double result = model.RPN("tan(sin( log( sqrt(9) * sqrt(9) ) ) )");
    ASSERT_EQ(tan(sin(log10(sqrt(9) * sqrt(9)))), result);
}

TEST(RPN, case4) {
    model::SmartCalc model;
    double result = model.RPN(
        "8 * 23456 - ( ( ( ( ( ( ( ( ( ( 8 * ( 2 + 2 ) ) - 3 ) ) - 3 ) * 2 ) - "
        "100 ) - 1 ) / 10 ) ) * 10 )");
    ASSERT_EQ(187697, result);
}

TEST(RPN, case5) {
    model::SmartCalc model;
    double result = model.RPN("acos( 1 ) * asin( 0 ) - atan( 1 )");
    ASSERT_EQ(result, acos(1) * asin(0) - atan(1));
}

TEST(RPN, case6) {
    model::SmartCalc model;
    double result = model.RPN("ln( 99 % 10 )");
    ASSERT_EQ(result, log(99 % 10));
}

TEST(RPN, case7) {
    model::SmartCalc model;
    double result = model.RPN("2 ^ 2 - 4 + ( 8 + 2)");
    ASSERT_EQ(result, pow(2, 2) - 4 + (8 + 2));
}

TEST(RPN, case8) {
    model::SmartCalc model;
    double result = model.RPN("cos(tan(sin( 3 * ( 5 - 2 ) ) ) )");
    ASSERT_EQ(result, cos(tan(sin(3 * (5 - 2)))));
}

TEST(RPN, case9) {
    model::SmartCalc model;
    double result =
        model.RPN("25990 / ( 2569 / ( cos( log( sqrt(100) ^ 2 ) ) ) )");
    ASSERT_EQ(result, 25990 / (2569 / (cos(log10(pow(sqrt(100), 2))))));
}

TEST(RPN, case10) {
    model::SmartCalc model;
    double result = model.RPN(" + ( - ( - ( - 5 ) ) )");
    ASSERT_EQ(result, -5);
}

TEST(RPN, case11) {
    model::SmartCalc model;
    double result = model.RPN("( + ( - ( - ( - 5 ) ) ) * cos( 1 ) ) / 5");
    ASSERT_EQ(result, (+(-(-(-5))) * cos(1)) / 5);
}

TEST(RPN, case12) {
    model::SmartCalc model;
    double result = model.RPN("- ( 8 + 9 ) + 8 - ( 9 * 9 )");
    ASSERT_EQ(result, -(8 + 9) + 8 - (9 * 9));
}

TEST(RPN, case13) {
    model::SmartCalc model;
    double result = model.RPN("+5");
    ASSERT_EQ(result, 5);
}

TEST(RPN, case14) {
    model::SmartCalc model;
    double result = model.RPN("cos( 90 / 3 - 2 ) - 3 * (3 * 3 - 10)");
    ASSERT_EQ(result, cos(90 / 3 - 2) - 3 * (3 * 3 - 10));
}

TEST(RPN, case15) {
    model::SmartCalc model;
    double result =
        model.RPN("( 1 + 2 ) * 4 * cos( 2 * 7 - 2 ) + sin( 2 * 90 )");
    ASSERT_EQ(result, (1 + 2) * 4 * cos(2 * 7 - 2) + sin(2 * 90));
}

TEST(RPN, case16) {
    model::SmartCalc model;
    double result = model.RPN(" * 9 9");
    ASSERT_EQ(result, 81);
}

TEST(RPN, case17) {
    model::SmartCalc model;
    double result = model.RPN("2 2 ^");
    ASSERT_EQ(result, 4);
}

TEST(RPN, case18) {
    model::SmartCalc model;
    double result = model.RPN("99%x", 10);
    ASSERT_EQ(result, 9);
}

TEST(RPN, case19) {
    model::SmartCalc model;
    double result = model.RPN("x^x", 3);
    ASSERT_EQ(result, 27);
}

TEST(RPN, case20) {
    model::SmartCalc model;
    double result = model.RPN("2.28 * 10 ^ 3");
    ASSERT_EQ(result, 2280);
}

TEST(RPN, case21) {
    model::SmartCalc model;
    double result = model.RPN("0.0008 * 10 ^ 6");
    ASSERT_EQ(result, 800);
}

TEST(RPN, case22) {
    model::SmartCalc model;
    double result = model.RPN("p * e");
    ASSERT_EQ(result, M_PI * M_E);
}

TEST(RPN, case23) {
    model::SmartCalc model;
    double result = model.RPN("p ^ e");
    ASSERT_EQ(result, std::pow(M_PI, M_E));
}

TEST(credit, caseAnnuity1) {
    model::creditModel model;
    model.annuity(1000, 12, 10);
    model::creditModel::data_c_t_ i = model.getResult();
    ASSERT_EQ(i.totalPayment, 1055.04);
    ASSERT_EQ(i.monthlyPayment, 87.92);
    ASSERT_EQ(i.overPayment, 55.04);
}

TEST(credit, caseAnnuity2) {
    model::creditModel model;
    model.annuity(228000, 24, 28);
    model::creditModel::data_c_t_ i = model.getResult();
    ASSERT_EQ(i.totalPayment, 300349.92);
    ASSERT_EQ(i.monthlyPayment, 12514.58);
    ASSERT_EQ(i.overPayment, 72349.92);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}