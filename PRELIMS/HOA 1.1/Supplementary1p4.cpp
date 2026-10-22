#include <iostream>
#include <cmath>

class Triangle
{
private:
    double totalAngle, angleA, angleB, angleC;
    double sideA, sideB, sideC;

public:
    Triangle(double A, double B, double C, double sA, double sB, double sC);
    void setAngles(double A, double B, double C);
    const bool validateTriangle();
    double getArea();
    double getPerimeter();
    void getTriangleType();
};

Triangle::Triangle(double A, double B, double C, double sA, double sB, double sC)
{
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;

    sideA = sA;
    sideB = sB;
    sideC = sC;
}

void Triangle::setAngles(double A, double B, double C)
{
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

const bool Triangle::validateTriangle()
{
    return (totalAngle == 180);
}

double Triangle::getPerimeter()
{
    return sideA + sideB + sideC;
}

double Triangle::getArea()
{
    double s = getPerimeter() / 2;
    return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

void Triangle::getTriangleType()
{
    if (angleA < 90 && angleB < 90 && angleC < 90)
    {
        std::cout << "Triangle Type: Acute-angled" << std::endl;
    }
    else if (angleA > 90 || angleB > 90 || angleC > 90)
    {
        std::cout << "Triangle Type: Obtuse-angled" << std::endl;
    }
    else
    {
        std::cout << "Triangle Type: Others" << std::endl;
    }
}

int main()
{
    double A, B, C;
    double sideA, sideB, sideC;

    std::cout << "Enter angle A: ";
    std::cin >> A;

    std::cout << "Enter angle B: ";
    std::cin >> B;

    std::cout << "Enter angle C: ";
    std::cin >> C;

    std::cout << "Enter side A: ";
    std::cin >> sideA;

    std::cout << "Enter side B: ";
    std::cin >> sideB;

    std::cout << "Enter side C: ";
    std::cin >> sideC;

    Triangle set1(A, B, C, sideA, sideB, sideC);

    if (set1.validateTriangle())
    {
        std::cout << "The shape is a valid triangle." << std::endl;
        std::cout << "Perimeter: " << set1.getPerimeter() << std::endl;
        std::cout << "Area: " << set1.getArea() << std::endl;
        set1.getTriangleType();
    }
    else
    {
        std::cout << "The shape is NOT a valid triangle." << std::endl;
    }

    return 0;
} 