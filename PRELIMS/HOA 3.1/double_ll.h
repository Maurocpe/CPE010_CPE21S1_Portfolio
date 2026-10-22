#include <iostream>
#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

template <typename T>
class doubleList{
public:
    T data;
    doubleList<T>* next = nullptr;
    doubleList<T>* prev = nullptr;
};

// Creating a node
template <typename T>
doubleList<T>* newNode(T newData){

    doubleList<T>* newNode = new doubleList<T>;

    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}

// Traversal
template <typename T>
void dllTraverse(doubleList<T>* currentNode){

    doubleList<T>* tail = nullptr;

    std::cout << "Forward Traversal\n";

    while(currentNode != nullptr){
        std::cout << currentNode->data << " ";
        tail = currentNode;
        currentNode = currentNode->next;
    }

    std::cout << std::endl;

    std::cout << "Reverse Traversal\n";

    while(tail != nullptr){
        std::cout << tail->data << " ";
        tail = tail->prev;
    }

    std::cout << std::endl << std::endl;
}

// Insertion at the head
template <typename T>
void dllInsertHead(T newData, doubleList<T>** currentHead){

    doubleList<T>* newNodePtr = newNode(newData);

    newNodePtr->next = *currentHead;

    if(*currentHead != nullptr){
        (*currentHead)->prev = newNodePtr;
    }

    *currentHead = newNodePtr;
}

// General Insertion
template <typename T>
void dllInsert(T newData, doubleList<T>* prevNode){

    if(prevNode == nullptr){
        std::cout << "Previous node cannot be NULL!" << std::endl;
        return;
    }

    // Create a new node
    doubleList<T>* newNodePtr = newNode(newData);

    // Connect the new node
    newNodePtr->next = prevNode->next;
    newNodePtr->prev = prevNode;

    // Update the next node's previous pointer
    if(prevNode->next != nullptr){
        prevNode->next->prev = newNodePtr;
    }

    // Connect the previous node to the new node
    prevNode->next = newNodePtr;
}

// Insertion at the end
template <typename T>
void dllInsertEnd(T newData, doubleList<T>* currentHead){

    doubleList<T>* newNodePtr = newNode(newData);

    while(currentHead->next != nullptr){
        currentHead = currentHead->next;
    }

    currentHead->next = newNodePtr;
    newNodePtr->prev = currentHead;
}

// Delete
template <typename T>
void dllDelete(T findData, doubleList<T>** head){

    // Check if the list is empty
    if(*head == nullptr) return;

    doubleList<T>* currentNode = *head;

    // Search for the node
    while(currentNode != nullptr && currentNode->data != findData){
        currentNode = currentNode->next;
    }

    // If data is not found
    if(currentNode == nullptr) return;

    // Delete the head node
    if(currentNode->prev == nullptr){
        *head = currentNode->next;

        if(*head != nullptr){
            (*head)->prev = nullptr;
        }
    }
    else{
        currentNode->prev->next = currentNode->next;

        if(currentNode->next != nullptr){
            currentNode->next->prev = currentNode->prev;
        }
    }

    delete currentNode;
}

#endif