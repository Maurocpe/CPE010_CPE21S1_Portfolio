#include <iostream>

int main()
{
    int firstNumber, secondNumber, temp;

    std::cout << "Enter the first number: ";
    std::cin >> firstNumber;

    std::cout << "Enter the second number: ";
    std::cin >> secondNumber;

    std::cout << "\nBefore swapping:" << std::endl;
    std::cout << "First number: " << firstNumber << std::endl;
    std::cout << "Second number: " << secondNumber << std::endl;

    temp = firstNumber;
    firstNumber = secondNumber;
    secondNumber = temp;

    std::cout << "\nAfter swapping:" << std::endl;
    std::cout << "First number: " << firstNumber << std::endl;
    std::cout << "Second number: " << secondNumber << std::endl;

    return 0;
}