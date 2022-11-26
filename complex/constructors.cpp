#include "complex.h"

namespace cpx {
    complex::complex() {
        _a = _b = 0;
    }

    complex::complex(double aReal, double bImaginary) {
        _a = aReal;
        _b = bImaginary;
    }

    complex::complex(const complex& obj) {
        _a = obj._a;
        _b = obj._b;
    }
}