#include <iostream>
using namespace std;

// before operator overloading
/*
class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0)
    {
        real = r;
        imag = i;
    }

    void print()
    {
        cout << real << " + " << imag << "i" << endl;
    }

    Complex add(Complex c)
    {
        Complex temp;

        temp.real = real + c.real;
        temp.imag = imag + c.imag;

        return temp;
    }
};

int main()
{
    Complex c1(3,4);
    Complex c2(5,6);

    Complex c3;

    //following is c1 ==> this ,,, c2 ==> complex 
    //so add function should add this (c1) + [c.real ,, c.imag] of c2
    c3 = c1.add(c2); // we need to make it c3 = c1 + c2
    // but the compiler doesn't know complex + complex sooooooo use operator overloading

    c3.print();
}
*/


//After operator overloading


class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0)
    {
        real = r;
        imag = i;
    }

    void print()
    {
        cout << real << " + " << imag << "i" << endl;
    }

    Complex operator+(Complex c) // here is the new function 
    {
        Complex temp;
        // real = 3 || c.real = 5 ,,, imag = 4 || c.imag = 6
        temp.real = real + c.real;
        temp.imag = imag + c.imag;

        return temp;
    }

    Complex operator-(Complex c) // here is the new function 
    {
        Complex temp;
        // real = 3 || c.real = 5 ,,, imag = 4 || c.imag = 6
        temp.real = real - c.real;
        temp.imag = imag - c.imag;

        return temp;
    }
    bool operator==(Complex c)
    {
        return (real == c.real && imag == c.imag);
    }
};


// assignment handling 
// the biggest problem is Shallow copy (COPY THE POINTER ONLY ADDRESS NOT VALUE)

class Student
{
public:

    int* grade;

    Student()
    {
        grade = new int;
    }
};

// solution of assignment overload

class Studentt
{
public:
    int* grade;

    Studentt(int g = 0)
    {
        grade = new int(g);
    }

    // Assignment Operator
    Studentt& operator=(const Studentt& other)
    {
        if (this != &other)
        {
            *grade = *other.grade;
        }

        return *this;

    }

    // it could be like this
    //Studentt& operator=(const Studentt& other)
    //{
      //  if (this != &other)
        //{
          //  delete grade;              // امسح القديمة

            //grade = new int(*other.grade); // احجز Memory جديدة وانسخ القيمة
        //}

        //return *this;
    //}

    void print()
    {
        cout << *grade << endl;
    }

    ~Studentt()
    {
        delete grade;
    }
};

int main()
{
    Complex c1(3,4);
    Complex c2(5,6);

    Complex c3;
    Complex c4;
    Complex c5;

    c3 = c1 + c2;
    c4 = c1 - c2;
    c5 = c2 - c1;
 
    c3.print();
    c4.print();
    c5.print();
    if(c1==c2)
    {
        cout<<"Equal" << endl;
    }
    else
    {
        cout<<"Not Equal" << endl;
    }

    Student s1;
    *s1.grade = 90;

    Student s2;
    s2 = s1; // here will be the problem s2 will copy the pointer address not value so if you change s2 will affect s1
    cout << *s1.grade << endl; // output 90
    cout << *s2.grade << endl; // output 90

    *s2.grade = 600;
    cout << *s1.grade << endl; // output 600
    cout << *s2.grade << endl; // output 600


    // last

    Studentt s11(90);
    Studentt s22(10);

    cout << "Before assignment:\n";
    s11.print(); // 90
    s22.print(); // 10

    s22 = s11;

    cout << "\nAfter assignment:\n";
    s11.print(); // 90
    s22.print(); // 90

    *s22.grade = 500;

    cout << "\nAfter modifying s2:\n";
    s11.print(); // 90
    s22.print(); // 500

}