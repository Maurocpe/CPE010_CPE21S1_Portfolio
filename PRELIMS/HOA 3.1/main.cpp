#include <iostream>
#include "double_LL.h"

int main(){

    // Create nodes
    doubleList<char>* head = newNode('C');
    doubleList<char>* second = newNode('P');
    doubleList<char>* third = newNode('E');

    // Link nodes
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    std::cout << "Initial Traversal" << std::endl;
    dllTraverse(head);

    std::cout << "Insertion at the Head" << std::endl;
    dllInsertHead('G', &head);
    dllTraverse(head);

    std::cout << "General Insertion" << std::endl;
    dllInsert('X', second);
    dllTraverse(head);

    std::cout << "Insertion at the End" << std::endl;
    dllInsertEnd('1', head);
    dllTraverse(head);

    std::cout << "Delete" << std::endl;
    dllDelete('X', &head);
    dllTraverse(head);

    return 0;
}