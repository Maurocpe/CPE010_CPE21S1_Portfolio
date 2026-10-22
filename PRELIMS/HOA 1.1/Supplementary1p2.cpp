#include <iostream>

double convertToFahrenheit(double kelvin);

int main()
{
    double kelvin;

    std::cout << "Enter temperature in Kelvin: ";
    std::cin >> kelvin;

    std::cout << "Temperature in Fahrenheit: "
              << convertToFahrenheit(kelvin) << std::endl;

    return 0;
}

double convertToFahrenheit(double kelvin)
{
    return (kelvin - 273.15) * 9 / 5 + 32;
}