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

    void displayRectangleParams()
    {
        std::cout << "Rectangle with " << width << " width and " << length << " length\n";
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
    int attr1, attr2, color;

    coord center;

    do
    {
        std::cout << "Input command: ";
        std::cin >> input;
        if(input=="circle")
        {
            std::cout << "Input center coordinates of figure x, y, radius and color(0-none, 1-red, 2-blue, 3-green): ";
            std::cin >> center.x >> center.y >> attr1 >> color;
            std::cout << "Circle has " << Circle (center.x, center.y, attr1, (colors)color).area() << " area and has ";
            Circle (center.x, center.y, attr1, (colors)color).rectangleFind().displayRectangleParams();
        }
        else if(input=="square")
        {
            std::cout << "Input center coordinates of figure x, y, edge and color(0-none, 1-red, 2-blue, 3-green): ";
            std::cin >> center.x >> center.y >> attr1 >> color;
            std::cout << "Square has " << Square (center.x, center.y, attr1, (colors)color).area() << " area and has ";
            Square (center.x, center.y, attr1, (colors)color).rectangleFind().displayRectangleParams();
        }
        else if(input=="triangle")
        {
            std::cout << "Input center coordinates of figure x, y, edge and color(0-none, 1-red, 2-blue, 3-green): ";
            std::cin >> center.x >> center.y >> attr1 >> color;
            std::cout << "Triangle has " << Triangle (center.x, center.y, attr1, (colors)color).area() << " area and has ";
            Triangle (center.x, center.y, attr1, (colors)color).rectangleFind().displayRectangleParams();
        }
        else if(input=="rectangle")
        {
            std::cout << "Input center coordinates of figure x, y, width, length and color(0-none, 1-red, 2-blue, 3-green): ";
            std::cin >> center.x >> center.y >> attr1 >> attr2 >> color;
            std::cout << "Rectangle has " << Rectangle (center.x, center.y, attr1, attr2, (colors)color).area() << " area and has ";
            Rectangle (center.x, center.y, attr1, (colors)color).rectangleFind().displayRectangleParams();
        }
    }
    while(input!="exit");

    return 0;
}
