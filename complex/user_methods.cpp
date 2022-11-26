#include "complex.h"

#include <math.h>

#define numberPI 3.1415926535897932384626433832795
#define angleStraight 180.0

namespace cpx {
    void complex::setReal(double aReal) {
        _a = aReal;
    }

    void complex::setImaginary(double bImaginary) {
        _b = bImaginary;
    }

    void complex::setParts(double aReal, double bImaginary) {
        _a = aReal;
        _b = bImaginary;
    }

    void complex::setPartsNull() {
        setParts(0, 0);
    }

    void complex::setIsnanPartsNull() {
        if (isnanReal()) {
            setReal(0);
        }
        if (isnanImaginary()) {
            setImaginary(0);
        }
    }

    double complex::getReal() const {
        return _a;
    }

    double complex::getImaginary() const {
        return _b;
    }

    double complex::getImaginaryConjugate() const {
        return -_b;
    }

    bool complex::isnanReal() const {
        return std::isnan(_a);
    }
    
    bool complex::isnanImaginary() const {
        return std::isnan(_b);
    }

    bool complex::isnanCPX() const {
        return (getImaginary() || getReal());
    }

    complex complex::getConjugate() const {
        return complex(_a, -_b);
    }

    bool complex::isEqualReal(double aReal) const {
        return (_a == aReal);
    }

    bool complex::isEqualImaginary(double bImaginary) const {
        return (_b == bImaginary);
    }

    bool complex::isEqualParts(double aReal, double bImaginary) const {
        return (isEqualReal(aReal) && isEqualImaginary(bImaginary));
    }

    bool complex::isConjugate(double aReal, double bImaginary) const {
        return ( (_a == aReal) && (bImaginary) );
    }

    bool complex::isConjugate(const complex& obj) const {
        return isConjugate(obj._a, obj._b);
    }

    void complex::swapParts() {
        std::swap(_a, _b);
    }

    void complex::copy(const complex& obj) {
        setParts(obj._a, obj._b);
    }

    void complex::copySwap(const complex& obj) {
        setParts(obj._b, obj._a);
    }

    double complex::absCPX() const {
        return std::sqrt(_a * _a + _b * _b);
    }

    double complex::cosCPX() const {
        return (_a / absCPX());
    }
    
    double complex::sinCPX() const {
        return (_b / absCPX());
    }

    double complex::tanCPX() const {
        return (sinCPX() / cosCPX());
    }

    double complex::cotCPX() const {
        return (cosCPX() / sinCPX());
    }

    int complex::degreeCPX() const {
        return ( asin(sinCPX()) * angleStraight / numberPI );
    }

    double complex::radianCPX() const {
        return ( degreeCPX() * numberPI / angleStraight );
    }
}