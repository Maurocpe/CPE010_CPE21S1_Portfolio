#include <iostream>
#include <string>
#include "4p1hC.h"

int main() {

    std::string expression;

    std::cout << "Symbol Balancing using Stack\n";

    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression);

    std::cout << "----- Array Stack -----\n";

    if (balancedArray(expression))
        std::cout << "Result: Balanced Symbols\n";
    else
        std::cout << "Result: Not Balanced\n";

    std::cout << "----- Linked List Stack -----\n";

    if (balancedLinked(expression))
        std::cout << "Result: Balanced Symbols\n";
    else
        std::cout << "Result: Not Balanced\n";

    return 0;
}