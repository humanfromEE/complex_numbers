#include "complex.h"

namespace cpx {
    complex operator+(const complex& obj1, const complex& obj2) {
        return complex(obj1._a + obj2._a, obj1._b + obj2._b);
    }

    complex operator-(const complex& obj1, const complex& obj2) {
        return complex(obj1._a - obj2._a, obj1._b - obj2._b);
    }

    complex operator*(const complex& obj1, const complex& obj2) {
        return complex( (obj1._a * obj2._a - obj1._b * obj2._b), (obj1._a * obj2._b + obj1._b * obj2._a) );
    }

    complex operator/(const complex& obj1, const complex& obj2) {
        return complex( (obj1._a * obj2._a + obj1._b * obj2._b) / (obj2._a * obj2._a +  obj2._b * obj2._b), (obj1._b * obj2._a - obj1._a * obj2._b) / (obj2._a * obj2._a +  obj2._b * obj2._b) );
    }

    std::istream& operator>>(std::istream& is, complex& obj) {
        return (is >> obj._a >> obj._b);
    }

    std::ostream& operator<<(std::ostream& os, const complex& obj) {
        return (obj.isnanReal() ||  obj.isnanImaginary()) ?
            (os << "not-complex=>division-by-zero-parts") :
            (os << obj._a << ( (obj._b >= 0) ? "+" : "" ) << obj._b << "i");
    }

    complex& complex::operator=(const complex& obj) {
        setParts(obj._a, obj._b);
        return *this;
    }

    complex& complex::operator+=(const complex& obj) {
        *this = *this + obj;
        return *this;
    }

    complex& complex::operator-=(const complex& obj) {
        *this = *this - obj;
        return *this;
    }

    complex& complex::operator*=(const complex& obj) {
        *this = *this * obj;
        return *this;
    }

    complex& complex::operator/=(const complex& obj) {
        *this = *this / obj;
        return *this;
    }

    bool complex::operator==(const complex& obj) const {
        return isEqualParts(obj._a, obj._b);
    }

    bool complex::operator!=(const complex& obj) const {
        return !isEqualParts(obj._a, obj._b);
    }

    bool complex::operator>(const complex& obj) const {
        return (this->absCPX() > obj.absCPX());
    }

    bool complex::operator>=(const complex& obj) const {
        return (this->absCPX() >= obj.absCPX());
    }

    bool complex::operator<(const complex& obj) const {
        return (this->absCPX() < obj.absCPX());
    }

    bool complex::operator<=(const complex& obj) const {
        return (this->absCPX() <= obj.absCPX());
    }
}