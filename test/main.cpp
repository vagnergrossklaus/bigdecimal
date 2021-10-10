#include "tst_bigdecimalconstructortest.h"
#include "tst_bigdecimalsumoperatortest.h"
#include "tst_bigdecimalsubtractoperatortest.h"

#include <gtest/gtest.h>

int main( int argc, char* argv[] ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
