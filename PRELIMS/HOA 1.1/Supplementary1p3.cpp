#include <iostream>
#include <cmath>

double calculateDistance(double x1, double y1, double x2, double y2);

int main()
{
    double x1, y1, x2, y2;

    std::cout << "Enter x-coordinate of the first point: ";
    std::cin >> x1;

    std::cout << "Enter y-coordinate of the first point: ";
    std::cin >> y1;

    std::cout << "Enter x-coordinate of the second point: ";
    std::cin >> x2;

    std::cout << "Enter y-coordinate of the second point: ";
    std::cin >> y2;

    std::cout << "\nDistance between the two points: "
              << calculateDistance(x1, y1, x2, y2) << std::endl;

    return 0;
}

double calculateDistance(double x1, double y1, double x2, double y2)
{
    return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}