#include <iostream>

void displaySum(int a, int b);
bool isGreater(int a, int b);
bool logicalOperations(bool x, bool y);

int main()
{
    int num1, num2;
    int a, b;
    bool value1, value2;

    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    displaySum(num1, num2);

    std::cout << "\nEnter value for A: ";
    std::cin >> a;

    std::cout << "Enter value for B: ";
    std::cin >> b;

    if (isGreater(a, b))
    {
        std::cout << "A is greater than B." << std::endl;
    }
    else
    {
        std::cout << "A is not greater than B." << std::endl;
    }

    std::cout << "\nEnter first Boolean value (0 or 1): ";
    std::cin >> value1;

    std::cout << "Enter second Boolean value (0 or 1): ";
    std::cin >> value2;

    logicalOperations(value1, value2);

    return 0;
}

void displaySum(int a, int b)
{
    std::cout << "\nSum = " << a + b << std::endl;
}

bool isGreater(int a, int b)
{
    return a > b;
}

bool logicalOperations(bool x, bool y)
{
    std::cout << "\nAND: " << (x && y) << std::endl;
    std::cout << "OR: " << (x || y) << std::endl;
    std::cout << "NOT first: " << (!x) << std::endl;
    std::cout << "NOT second: " << (!y) << std::endl;

    return true;
}