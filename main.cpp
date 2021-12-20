#include <iostream>
#include <cmath>

double pi=3.1415926535;

enum colors {NONE, RED, BLUE, GREEN};

struct coord
{
    int x;
    int y;
};

class Rectangle;

class Figure
{
private:
    coord center;
    colors color;
public:
    Figure(int x, int y, colors color)
    {
        center.x=x;
        center.y=y;
        this->color=color;
    }

    coord getCoords()
    {
        return center;
    }

    colors getColor()
    {
        return color;
    }

    virtual Rectangle rectangleFind()=0;
    virtual double area()=0;
};

class Rectangle : public Figure
{
private:
    int width;
    int length;
public:
    Rectangle(int x, int y, int width, int length, colors color=NONE) : Figure(x,y,color)
    {
        this->width=width;
        this->length=length;
    }

    double area()
    {
        return (this->width)*(this->length);
    }

    Rectangle rectangleFind()
    {
        return *this;
    }
};

class Circle : public Figure
{
private:
    int radius;
public:
    Circle(int x, int y, int radius, colors color=NONE): Figure(x,y,color)
    {
        this->radius=radius;
    }

    Rectangle rectangleFind()
    {
        return Rectangle (this->getCoords().x, this->getCoords().y, radius, radius, this->getColor());
    }

    double area() { return pi*radius*radius; }

};

class Triangle : public Figure
{
private:
    int edge;
public:
    Triangle(int x, int y, int edge, colors color=NONE) : Figure(x,y,color)
    {
        this->edge=edge;
    }

    Rectangle rectangleFind()
    {
        return Rectangle (this->getCoords().x, this->getCoords().y, edge, (edge*std::sqrt(3)/2), this->getColor());
    }
    double area()
    {
        return (edge * edge * std::sqrt(3) )/4;
    }
};

class Square : public Figure
{
private:
    int edge;
public:
    Square(int x, int y, int edge, colors color=NONE) : Figure(x,y,color)
    {
        this->edge=edge;
    }

    Rectangle rectangleFind()
    {
        return Rectangle (this->getCoords().x, this->getCoords().y, edge, edge, this->getColor());
    }

    double area()
    {
        return edge*edge;
    }
};

int main()
{
    std::string input;
    int attr, color;

    coord center, ;

    do
    {
        std::cout << "Input command: ";
        if(input=="circle")
        {
            std::cin >> center.x >> center.y >> attr >> color;
        }
    }
    while(input!="exit");

    return 0;
}
