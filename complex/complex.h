#pragma once

#include <iostream>

/*
    cpx - ComPleX
    _a - real part
    _b - imaginary part
    create const-objects
    double has value nan
*/

namespace cpx {
    class complex {
        // Data fileds
        private:
            double _a;
            double _b;

        // Constructors
        public:
            complex();
            complex(double aReal, double bImaginary);
            complex(const complex& obj);

        // User methods
        public:
            void setReal(double aReal);
            void setImaginary(double bImaginary);
            void setParts(double aReal, double bImaginary);
            void setPartsNull();
            void setIsnanPartsNull();
            double getReal() const;
            double getImaginary() const;
            double getImaginaryConjugate() const;
            complex getConjugate() const;
            bool isnanReal() const;
            bool isnanImaginary() const;
            bool isnanCPX() const;
            bool isEqualReal(double aReal) const;
            bool isEqualImaginary(double bImaginary) const;
            bool isEqualParts(double aReal, double bImaginary) const;
            bool isConjugate(double aReal, double bImaginary) const;
            bool isConjugate(const complex& obj) const;
            void swapParts();
            void copy(const complex& obj);
            void copySwap(const complex& obj);
            double absCPX() const;
            double cosCPX() const;
            double sinCPX() const;
            double tanCPX() const;
            double cotCPX() const;
            int degreeCPX() const;
            double radianCPX() const;

        // Overload operators
        public:
            friend complex operator+(const complex& obj1, const complex& obj2);
            friend complex operator-(const complex& obj1, const complex& obj2);
            friend complex operator*(const complex& obj1, const complex& obj2);
            friend complex operator/(const complex& obj1, const complex& obj2);
            friend std::istream& operator>>(std::istream& is, complex& obj);
            friend std::ostream& operator<<(std::ostream& os, const complex& obj);
            complex& operator=(const complex& obj);
            complex& operator+=(const complex& obj);
            complex& operator-=(const complex& obj);
            complex& operator*=(const complex& obj);
            complex& operator/=(const complex& obj);
            bool operator==(const complex& obj) const;
            bool operator!=(const complex& obj) const;
            bool operator<(const complex& obj) const;
            bool operator<=(const complex& obj) const;
            bool operator>(const complex& obj) const;
            bool operator>=(const complex& obj) const;

    };
}

#include "constructors.cpp" // File of release constructors
#include "user_methods.cpp" // File of release user methods
#include "overload_operators.cpp" // File of release overload operators
