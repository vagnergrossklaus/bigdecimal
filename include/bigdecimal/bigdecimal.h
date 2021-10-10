#pragma once

#include <math.h>
#include <limits>

#include "bigdecimal_global.h"

class BIGDECIMAL_EXPORT BigDecimal {
public:
    BigDecimal( const float value, const int precision );
    BigDecimal( const int intPart, const int fracPart, const int precision );

    int intPart() const;
    int fractPart() const;
    int precision() const;

    BigDecimal operator+( const BigDecimal decimal ) const;
    BigDecimal operator-( const BigDecimal decimal ) const;

private:
    int _intPart;
    int _fractPart;
    const int _precision;
    const int _exponent;

    BigDecimal( const int precision );

    // TODO Move to private header
    // TODO Adjust exponent to represent correctly fractal parts with left zeros accordly preciosion like .3, .03, .003, ...,
    // Suggest to use negative exponent, this maybe useful when get value back to primitive floating point
    // or other ways to represent value, like string
    template<typename T> void extract( const T value, const int precision, int& intPart, int& fractPart ) const {
        T i = 0.0f;
        T fract = std::modf( value, &i );

        intPart = std::trunc( i );
        fractPart = precision > 0 ? fractPart = std::round( fract * std::pow( 10, precision ) ) : 0;
    }

};
