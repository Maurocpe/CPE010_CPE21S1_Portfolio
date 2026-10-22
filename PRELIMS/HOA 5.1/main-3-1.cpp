#include <iostream>
#include "queuell.h"


int main(){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;
    // Enqueue elements
    enqueue(&front, &back, 'R');
    enqueue(&front, &back, 'Y');
    enqueue(&front, &back, 'A');
    enqueue(&front, &back, 'N');

    // Display queue
    std::cout << "Queue: ";
    display(front);

    // Return the front element
    std::cout << "Front element: " << getFront(front) << std::endl;

    // Dequeue one element
    dequeue(&front, &back);
    std::cout << "\nAfter dequeue:" << std::endl;
    std::cout << "Queue: ";
    display(front);
    std::cout << "Front element: " << getFront(front) << std::endl;

    return 0;
}
