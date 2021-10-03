#pragma once

#include <gtest/gtest.h>

#include <bigdecimal/bigdecimal.h>

class BigDecimalTest : public ::testing::Test {
protected:

    BigDecimalTest() {}
    ~BigDecimalTest() override {}

    void SetUp() override {}
    void TearDown() override {}

};

// Tests that the Foo::Bar() method does Abc.
TEST_F( BigDecimalTest, MethodBarDoesAbc ) {
//    const std::string input_filepath = "this/package/testdata/myinputfile.dat";
//    const std::string output_filepath = "this/package/testdata/myoutputfile.dat";
    BigDecimal decimal;
    EXPECT_EQ( 0, 0 );
}
