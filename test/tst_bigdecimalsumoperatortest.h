#pragma once

#include <gtest/gtest.h>

#include <bigdecimal/bigdecimal.h>

class BigDecimalSumOperatorTest : public ::testing::TestWithParam<std::tuple<BigDecimal, BigDecimal, BigDecimal> > {};

INSTANTIATE_TEST_SUITE_P(
    testBigDecimalSumOperator,
    BigDecimalSumOperatorTest,
    ::testing::Values(
        std::make_tuple( BigDecimal( 0.00, 0 ), BigDecimal( 0.00, 0 ), BigDecimal( 0.00, 0 ) ),
        std::make_tuple( BigDecimal( 0.00, 1 ), BigDecimal( 0.00, 1 ), BigDecimal( 0.00, 1 ) ),
        std::make_tuple( BigDecimal( 0.00, 0 ), BigDecimal( 1.00, 0 ), BigDecimal( 1.00, 0 ) ),
        std::make_tuple( BigDecimal( 0.00, 1 ), BigDecimal( 1.00, 1 ), BigDecimal( 1.00, 1 ) ),
        std::make_tuple( BigDecimal( 0.00, 2 ), BigDecimal( 1.00, 2 ), BigDecimal( 1.00, 2 ) ),
        std::make_tuple( BigDecimal( 5.00, 0 ), BigDecimal( 2.00, 0 ), BigDecimal( 7.00, 0 ) ),
        std::make_tuple( BigDecimal( 5.00, 1 ), BigDecimal( 2.00, 1 ), BigDecimal( 7.00, 1 ) ),
        std::make_tuple( BigDecimal( 5.00, 2 ), BigDecimal( 2.00, 2 ), BigDecimal( 7.00, 2 ) ),
        std::make_tuple( BigDecimal( 5.00, 3 ), BigDecimal( 2.00, 3 ), BigDecimal( 7.00, 3 ) ),
        std::make_tuple( BigDecimal( 5.00, 0 ), BigDecimal( 6.00, 0 ), BigDecimal( 11.00, 0 ) ),
        std::make_tuple( BigDecimal( 5.00, 1 ), BigDecimal( 6.00, 1 ), BigDecimal( 11.00, 1 ) ),
        std::make_tuple( BigDecimal( 5.00, 2 ), BigDecimal( 6.00, 2 ), BigDecimal( 11.00, 2 ) ),
        std::make_tuple( BigDecimal( 21.00, 2 ), BigDecimal( 18.00, 2 ), BigDecimal( 39.00, 2 ) ),

        std::make_tuple( BigDecimal( 1.00, 0 ), BigDecimal( 0.5, 0 ), BigDecimal( 1.5, 0 ) ),
        std::make_tuple( BigDecimal( 1.00, 1 ), BigDecimal( 0.5, 1 ), BigDecimal( 1.5, 1 ) ),
        std::make_tuple( BigDecimal( 1.00, 2 ), BigDecimal( 0.5, 2 ), BigDecimal( 1.5, 2 ) ),
        std::make_tuple( BigDecimal( 1.00, 3 ), BigDecimal( 0.5, 3 ), BigDecimal( 1.5, 3 ) ),
        std::make_tuple( BigDecimal( 1.00, 2 ), BigDecimal( 0.5, 1 ), BigDecimal( 1.5, 2 ) ),
        std::make_tuple( BigDecimal( 1.25, 2 ), BigDecimal( 0.5, 2 ), BigDecimal( 1.75, 2 ) ),
        std::make_tuple( BigDecimal( 1.253, 2 ), BigDecimal( 0.5, 2 ), BigDecimal( 1.75, 2 ) ),
        std::make_tuple( BigDecimal( 1.256, 2 ), BigDecimal( 0.5, 2 ), BigDecimal( 1.76, 2 ) ),
        std::make_tuple( BigDecimal( 1.253, 3 ), BigDecimal( 0.5, 2 ), BigDecimal( 1.753, 3 ) ),
        std::make_tuple( BigDecimal( 1.256, 3 ), BigDecimal( 0.5, 2 ), BigDecimal( 1.756, 3 ) ),
        std::make_tuple( BigDecimal( 1.253, 4 ), BigDecimal( 0.5, 2 ), BigDecimal( 1.753, 4 ) ),
        std::make_tuple( BigDecimal( 1.256, 4 ), BigDecimal( 0.5, 2 ), BigDecimal( 1.756, 4 ) ),
        std::make_tuple( BigDecimal( 1.253, 4 ), BigDecimal( 0.5, 5 ), BigDecimal( 1.753, 5 ) ),
        std::make_tuple( BigDecimal( 1.256, 4 ), BigDecimal( 0.5, 5 ), BigDecimal( 1.756, 5 ) ),

        std::make_tuple( BigDecimal( 16.73, 2 ), BigDecimal( 9.2, 1 ), BigDecimal( 25.93, 2 ) ),
        std::make_tuple( BigDecimal( 16.73, 2 ), BigDecimal( 9.23, 1 ), BigDecimal( 25.93, 2 ) ),
        std::make_tuple( BigDecimal( 16.73, 2 ), BigDecimal( 9.27, 1 ), BigDecimal( 26.03, 2 ) ),
        std::make_tuple( BigDecimal( 16.73, 2 ), BigDecimal( 9.26, 2 ), BigDecimal( 25.99, 2 ) ),
        std::make_tuple( BigDecimal( 16.73, 2 ), BigDecimal( 9.261, 2 ), BigDecimal( 25.99, 2 ) ),
        std::make_tuple( BigDecimal( 16.73, 2 ), BigDecimal( 9.265, 2 ), BigDecimal( 26.000, 2 ) ),
        std::make_tuple( BigDecimal( 16.73, 2 ), BigDecimal( 9.265, 3 ), BigDecimal( 25.995, 3 ) ),
        std::make_tuple( BigDecimal( 16.73, 2 ), BigDecimal( 9.261, 3 ), BigDecimal( 25.991, 3 ) ),
        std::make_tuple( BigDecimal( 16.73, 2 ), BigDecimal( 9.26, 2 ), BigDecimal( 25.99, 2 ) ),
        std::make_tuple( BigDecimal( 16.73, 2 ), BigDecimal( 9.27, 2 ), BigDecimal( 26.00, 2 ) ),
        std::make_tuple( BigDecimal( 16.73, 2 ), BigDecimal( 9.28, 2 ), BigDecimal( 26.01, 2 ) ),
        std::make_tuple( BigDecimal( 39.73, 2 ), BigDecimal( 79.55, 2 ), BigDecimal( 119.28, 2 ) )

        // TODO adicionar combinacoes com precisoes diferentes

        )
    );

TEST_P( BigDecimalSumOperatorTest, testBigDecimalSumOperator ) {

    std::tuple<BigDecimal, BigDecimal, BigDecimal> params = GetParam();

    BigDecimal decimalSum = std::get<0>( params ) + std::get<1>( params );

    EXPECT_EQ( decimalSum.intPart(), std::get<2>( params ).intPart() );
    EXPECT_EQ( decimalSum.fractPart(), std::get<2>( params ).fractPart() );
    EXPECT_EQ( decimalSum.precision(), std::get<2>( params ).precision() );

}
