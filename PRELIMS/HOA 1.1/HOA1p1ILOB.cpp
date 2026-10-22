#include <iostream>

class Triangle
{
private:
    double totalAngle, angleA, angleB, angleC;

public:
    Triangle(double A, double B, double C);
    void setAngles(double A, double B, double C);
    const bool validateTriangle();
};

Triangle::Triangle(double A, double B, double C)
{
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
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

int main()
{
    double A, B, C;

    std::cout << "Enter angle A: ";
    std::cin >> A;

    std::cout << "Enter angle B: ";
    std::cin >> B;

    std::cout << "Enter angle C: ";
    std::cin >> C;

    Triangle set1(A, B, C);

    if (set1.validateTriangle())
    {
        std::cout << "The shape is a valid triangle." << std::endl;
    }
    else
    {
        std::cout << "The shape is NOT a valid triangle." << std::endl;
    }

    return 0;
}