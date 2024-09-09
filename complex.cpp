#include <iostream>

class Complex {
private:
    double real;  // Real part
    double imag;  // Imaginary part

public:
    // Default constructor
    Complex() {
        real = 0;
        imag = 0;
    }

    // Parameterized constructor
    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    // Overloaded + operator to add two complex numbers
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloaded * operator to multiply two complex numbers
    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    // Overloaded << operator to print complex numbers
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real;
        if (c.imag >= 0) os << " + " << c.imag << "i";
        else os << " - " << -c.imag << "i";
        return os;
    }

    // Overloaded >> operator to read complex numbers
    friend std::istream& operator>>(std::istream& is, Complex& c) {
        is >> c.real >> c.imag;
        return is;
    }
};

int main() {
    Complex c1, c2;

    std::cout << "Enter two complex numbers (format: real imag):\n";
    std::cin >> c1 >> c2;

    std::cout << "Sum: " << (c1 + c2) << "\n"; // Calculate and print sum

    return 0;
}
