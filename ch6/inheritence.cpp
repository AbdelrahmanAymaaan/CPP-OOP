#include <iostream>
#include <string>

using namespace std;
/*
class Base
{
    private:
        int a;
        int b;
    protected:
        int sum; // you can see this from children only
    public:
        // constr.
        Base()
        {a=b=0;}
        Base(int n)
        {a=b=n;}
        Base(int x,int y)
        {a=x; b=y;}

        // Setters
        void setA(int x)
        {a=x; }
        void setB(int y)
        {b=y;}

        // Geters
        int getA()
        {return a;}
        int getB()
        {return b;}

        int productAB() {
        return a*b;
        }
};


class Derived: public Base
{
    private:
        int c;
    public:
        Derived() : Base()
        {c=0;}
        Derived (int n): Base(n)
        {c = n;}
        Derived (int x, int y, int z): Base(x,y)
        {c= z;}
        void setc(int z)
        {c= z;}
        int getc()
        {return c;}
        int productABC()
        {
            //return a*b*C;
            return productAB() * c; // return this->productAB() * c; as a and b is private in the base class so you can't make a*b*c directly
        }
        
};


int main()
{
    Derived objl; // default constructor of derived then base class (a,b) = 0
    objl.setA(3);
    objl.setB(7);
    objl.setc(1);
    cout<<"objl: "<<objl.productAB()<<endl;
    cout<<"objl: "<<objl.productABC () <<endl;
};*/


#include <iostream>
using namespace std;

//====================================================
// Base Class
//====================================================

class Shape // parent class
{
public:

    virtual void draw() = 0;

    virtual ~Shape() {}
};

//====================================================
// Point
//====================================================

class Point
{
private:

    int x;
    int y;

public:

    Point(int xx = 0, int yy = 0)
    {
        x = xx;
        y = yy;
    }

    void print() const
    {
        cout << "(" << x << "," << y << ")";
    }
};

//====================================================
// Line
//====================================================

class Line : public Shape
{
private:

    Point p1;
    Point p2;

public:

    Line(Point a, Point b)
        : p1(a), p2(b)
    {
    }

    void draw() override
    {
        cout << "Line : ";

        p1.print();

        cout << " ---> ";

        p2.print();

        cout << endl;
    }
};

//====================================================
// Rectangle
//====================================================

class Rect : public Shape
{
private:

    Point topLeft;
    Point bottomRight;

public:

    Rect(Point p1, Point p2)
        : topLeft(p1), bottomRight(p2)
    {
    }

    void draw() override
    {
        cout << "Rectangle : ";

        topLeft.print();

        cout << " ";

        bottomRight.print();

        cout << endl;
    }
};

//====================================================
// Circle
//====================================================

class Circle : public Shape
{
private:

    Point center;

    int radius;

public:

    Circle(Point c, int r)
        : center(c), radius(r)
    {
    }

    void draw() override
    {
        cout << "Circle : Center ";

        center.print();

        cout << " Radius = " << radius << endl;
    }
};

//====================================================
// Picture
//====================================================

class Picture
{
private:

    Shape* shapes[100];

    int count;

public:

    Picture()
    {
        count = 0;
    }

    void addShape(Shape* s)
    {
        if (count < 100)
        {
            shapes[count++] = s;
        }
    }

    void drawPicture()
    {
        cout << "\n========== Picture ==========\n\n";

        for (int i = 0; i < count; i++)
        {
            shapes[i]->draw();
        }

        cout << endl;
    }

    ~Picture()
    {
        for (int i = 0; i < count; i++)
        {
            delete shapes[i];
        }
    }
};

//====================================================
// Main
//====================================================

int main()
{
    Picture pic;

    pic.addShape(
        new Line(
            Point(0, 0),
            Point(5, 5)));

    pic.addShape(
        new Line(
            Point(2, 3),
            Point(8, 6)));

    pic.addShape(
        new Rect(
            Point(1, 1),
            Point(6, 4)));

    pic.addShape(
        new Circle(
            Point(10, 10),
            5));

    pic.addShape(
        new Circle(
            Point(20, 8),
            3));

    pic.drawPicture();

    return 0;
}