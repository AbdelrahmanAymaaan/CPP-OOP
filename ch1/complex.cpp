#include <iostream>
#include <string>

using namespace std;
class Complex {
private:
    float real;
    float imag;

public:
    Complex(float r = 0.0f, float i = 0.0f)
        : real(r), imag(i) {}  // member initializer list to initialize the real and imaginary parts of the complex number.
        // take the value of i and assign it to the imag member variable.
        // also take the value of r and assign it to the real member variable.

        // equals to this f.n
        /*
            Complex(float r = 0.0f, float i = 0.0f) {
                real = r;
                imag = i;
            }
        */
    
    void print() const; // Function to print the complex number in the form "real + imag i".
    void adding_two_complex_numbers(const Complex& c1, const Complex& c2);
    void subtracting_two_complex_numbers(const Complex& c1, const Complex& c2);
};



void Complex::adding_two_complex_numbers(const Complex& c1, const Complex& c2) {
    float realSum = c1.real + c2.real;
    float imagSum = c1.imag + c2.imag;
    cout << "The sum of the two complex numbers is: " << realSum << " + " << imagSum << "i" << endl;
}

void Complex::subtracting_two_complex_numbers(const Complex& c1, const Complex& c2) {
    float realDiff = c1.real - c2.real;
    float imagDiff = c1.imag - c2.imag;
    cout << "The difference of the two complex numbers is: " << realDiff << " + " << imagDiff << "i" << endl;
}

void Complex::print() const {
    cout << real << " + " << imag << "i" << endl;
}



int main() {
    cout << "Enter the real and imaginary parts of a complex number: ";
    float realPart, imagPart;
    cin >> realPart >> imagPart; // Input the real and imaginary parts of a complex number from the user.
    
    cout << "please enter the real and imaginary parts of another complex number: " << endl;
    float realPart2, imagPart2;
    cin >> realPart2 >> imagPart2;
    
    Complex c1(realPart, imagPart); // Create an instance of the Complex class using the
    c1.print();
   
    Complex c2(realPart2, imagPart2);
    c2.print();

    c1.adding_two_complex_numbers(c1, c2);
    c1.subtracting_two_complex_numbers(c1, c2);
    return 0;
}