#include <bigdecimal/bigdecimal.h>

#include <math.h>
#include <limits>
#include <algorithm>

BigDecimal::BigDecimal( const int precision ) :
    _intPart{ 0 },
    _fractPart{ 0 },
    _precision{ precision },
    _exponent{ static_cast<int>( std::pow( 10, precision ) ) } {}

BigDecimal::BigDecimal( const float value, const int precision ) :
    BigDecimal( precision ) {
    extract<float>( value, precision, _intPart, _fractPart );
}

BigDecimal::BigDecimal( const int intPart, const int fracPart, const int precision ) :
    BigDecimal( precision ) {
    _intPart = intPart;
    _fractPart = fracPart;
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

    int newPrecison = std::max( precision(), decimal.precision() );
    int exponenent = static_cast<int>( std::pow( 10, newPrecison ) );

    int newIntPart = intPart() + decimal.intPart();

    int newFractPart = 0;
    newFractPart += newPrecison > precision() ? fractPart() * ( static_cast<int>( std::pow( 10, std::abs( newPrecison - precision() ) ) ) ) : fractPart();
    newFractPart += newPrecison > decimal.precision() ? decimal.fractPart() * ( static_cast<int>( std::pow( 10, std::abs( newPrecison - decimal.precision() ) ) ) ) : decimal.fractPart();

    if ( newFractPart >= exponenent ) {
        newIntPart += std::trunc( newFractPart / exponenent );
        newFractPart -= exponenent;
    }

    return BigDecimal( newIntPart,
                       newFractPart,
                       newPrecison );

}

BigDecimal BigDecimal::operator-( const BigDecimal decimal ) const {

    int newPrecison = std::max( precision(), decimal.precision() );
//    int exponenent = static_cast<int>( std::pow( 10, newPrecison ) );

    int newIntPart = intPart() - decimal.intPart();

    int newFractPart = 0;
//    newFractPart += newPrecison > precision() ? fractPart() * ( static_cast<int>( std::pow( 10, std::abs( newPrecison - precision() ) ) ) ) : fractPart();
//    newFractPart += newPrecison > decimal.precision() ? decimal.fractPart() * ( static_cast<int>( std::pow( 10, std::abs( newPrecison - decimal.precision() ) ) ) ) : decimal.fractPart();

//    if ( newFractPart >= exponenent ) {
//        newIntPart += std::trunc( newFractPart / exponenent );
//        newFractPart -= exponenent;
//    }

    return BigDecimal( newIntPart,
                       newFractPart,
                       newPrecison );
}
