#include <bigdecimal/bigdecimal.h>

#include <math.h>
#include <limits>
#include <algorithm>

BigDecimal::BigDecimal( const float value, const int precision ) :
    _intPart{ 0 },
    _fractPart{ 0 },
    _precision{ 0 } {
    extract<float>( value, precision, _intPart, _fractPart );
}

int BigDecimal::intPart() const {
    return _intPart;
}

int BigDecimal::fractPart() const {
    return _fractPart;
}

int BigDecimal::precision() const {
    return _precision;
}

BigDecimal BigDecimal::operator+( const BigDecimal decimal ) const {
    return BigDecimal( intPart() + decimal.intPart(), std::max( precision(), decimal.precision() ) );
}
