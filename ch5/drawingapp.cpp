#include <iostream>
using namespace std;

//======================
// Point
//======================

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

//======================
// Line
//======================

class Line
{
    private:
        Point p1;
        Point p2;

    public:
        Line(Point a, Point b)
            : p1(a), p2(b)
        {
        }

        void draw() const
        {
            cout << "Line : ";
            p1.print();
            cout << " ---> ";
            p2.print();
            cout << endl;
        }
};

//======================
// Rectangle
//======================

class Rect
    {
    private:
        Point topLeft;
        Point bottomRight;

    public:
        Rect(Point p1, Point p2)
            : topLeft(p1), bottomRight(p2)
        {
        }

        void draw() const
        {
            cout << "Rectangle : ";

            topLeft.print();

            cout << "  ";

            bottomRight.print();

            cout << endl;
        }
};

//======================
// Circle
//======================

class Circle
{
    private:
        Point center;
        int radius;

    public:
        Circle(Point c, int r)
            : center(c), radius(r)
        {
        }

        void draw() const
        {
            cout << "Circle : Center ";

            center.print();

            cout << " Radius = " << radius << endl;
        }
};

//======================
// Picture
//======================

class Picture
{
    private:

        Line* lines[10];
        Rect* rects[10];
        Circle* circles[10];

        int lineCount;
        int rectCount;
        int circleCount;

    public:

        Picture()
        {
            lineCount = 0;
            rectCount = 0;
            circleCount = 0;
        }

        //--------------------

        void addLine(Line* l)
        {
            if (lineCount < 10)
                lines[lineCount++] = l;
        }

        //--------------------

        void addRect(Rect* r)
        {
            if (rectCount < 10)
                rects[rectCount++] = r;
        }

        //--------------------

        void addCircle(Circle* c)
        {
            if (circleCount < 10)
                circles[circleCount++] = c;
        }

        //--------------------

        void drawPicture() const
        {
            cout << endl;
            cout << "========== Picture ==========" << endl;

            cout << endl;

            for (int i = 0; i < lineCount; i++)
                lines[i]->draw();

            cout << endl;

            for (int i = 0; i < rectCount; i++)
                rects[i]->draw();

            cout << endl;

            for (int i = 0; i < circleCount; i++)
                circles[i]->draw();

            cout << endl;
        }

        //--------------------

        ~Picture()
        {
            for (int i = 0; i < lineCount; i++)
                delete lines[i];

            for (int i = 0; i < rectCount; i++)
                delete rects[i];

            for (int i = 0; i < circleCount; i++)
                delete circles[i];
        }
};

//======================
// Main
//======================

int main()
{
    Picture pic;

    //--------------------

    pic.addLine(
        new Line(
            Point(0, 0),
            Point(5, 5)));

    pic.addLine(
        new Line(
            Point(2, 3),
            Point(8, 6)));

    //--------------------

    pic.addRect(
        new Rect(
            Point(1, 1),
            Point(6, 4)));

    //--------------------

    pic.addCircle(
        new Circle(
            Point(10, 10),
            5));

    pic.addCircle(
        new Circle(
            Point(20, 8),
            3));

    //--------------------

    pic.drawPicture();

    return 0;
}