#pragma once

#include <math.h>
#include <limits>

#include "bigdecimal_global.h"

class BIGDECIMAL_EXPORT BigDecimal {
public:
    BigDecimal( const float value, const int precision = 0 );

    int intPart() const;
    int fractPart() const;
    int precision() const;

    BigDecimal operator+( const BigDecimal decimal ) const;

private:
    int _intPart;
    int _fractPart;
    int _precision;

    template<typename T> void extract( const T value, const int precision, int& intPart, int& fractPart ) const {
        T i = 0.0f;
        T fract = std::modf( value, &i );

        intPart = std::trunc( i );
        fractPart = precision > 0 ? fractPart = std::round( fract * std::pow( 10, precision ) ) : 0;
    }

};
