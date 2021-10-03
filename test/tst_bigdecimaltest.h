#pragma once

#include <gtest/gtest.h>

#include <bigdecimal/bigdecimal.h>

class BigDecimalTest : public ::testing::TestWithParam<std::tuple<float, int, int, int> > {
protected:
    BigDecimalTest() {}
    ~BigDecimalTest() override {}

    void SetUp() override {}
    void TearDown() override {}
};

INSTANTIATE_TEST_CASE_P(
    testBigDecimalConstructor,
    BigDecimalTest,
    ::testing::Values(
        std::make_tuple( 0.00, 0, 0, 0 ),
        std::make_tuple( 0.00, 1, 0, 0 ),
        std::make_tuple( 0.00, 2, 0, 0 ),
        std::make_tuple( 0.00, 3, 0, 0 ),
        std::make_tuple( 1.55, 0, 1, 0 ),
        std::make_tuple( 1.55, 1, 1, 5 ),
        std::make_tuple( 1.55, 2, 1, 55 ),
        std::make_tuple( 1.55, 3, 1, 550 ),
        std::make_tuple( 12.73, 0, 12, 0 ),
        std::make_tuple( 12.73, 1, 12, 7 ),
        std::make_tuple( 12.73, 2, 12, 73 ),
        std::make_tuple( 12.73, 3, 12, 730 ),
        std::make_tuple( 12.736, 0, 12, 0 ),
        std::make_tuple( 12.736, 1, 12, 7 ),
        std::make_tuple( 12.736, 2, 12, 74 ), // TODO Adjust round mode
        std::make_tuple( 12.736, 3, 12, 736 ),
        std::make_tuple( 12.1362365, 0, 12, 0 ),
        std::make_tuple( 12.1362365, 1, 12, 1 ),
        std::make_tuple( 12.1362365, 2, 12, 14 ), // TODO Adjust round mode
        std::make_tuple( 12.1362365, 3, 12, 136 ),
        std::make_tuple( 159.736258, 0, 159, 0 ),
        std::make_tuple( 159.736258, 1, 159, 7 ),
        std::make_tuple( 159.736258, 2, 159, 74 ), // TODO Adjust round mode
        std::make_tuple( 159.736258, 3, 159, 736 ),
        std::make_tuple( 159.736258, 4, 159, 7363 ), // TODO Adjust round mode
        std::make_tuple( 159.736258, 5, 159, 73625 ),
        std::make_tuple( 159.736258, 6, 159, 736252 ) // TODO Adjust round mode
        )
    );

TEST_P( BigDecimalTest, testBigDecimalConstructor ) {

    auto [value, precision, intPart, fractPart] = GetParam();

    BigDecimal decimal( value, precision );

    EXPECT_EQ( decimal.intPart(), intPart );
    EXPECT_EQ( decimal.fractPart(), fractPart );

}

TEST_P( BigDecimalTest, testBigDecimalSumOperator ) {

    auto [value, precision, intPart, fractPart] = GetParam();

    BigDecimal decimal01( 1, 0 );
    BigDecimal decimal02( 1, 0 );

    BigDecimal decimalSum = decimal01 + decimal02;

    EXPECT_EQ( decimalSum.intPart(), 2 );
    EXPECT_EQ( decimalSum.fractPart(), 0 );

}
