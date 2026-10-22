#ifndef QUEUELL_H
#define QUEUELL_H

template <typename T>
class qNode{
public:
    T data;
    qNode<T> *next;
};

// Create a new node
template <typename T>
qNode<T>* new_node(T newData){
    qNode<T>* newNode = new qNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

// Insert an element at the back of the queue
template <typename T>
void enqueue(qNode<T>** frontPtr, qNode<T>** backPtr, T newData){

    qNode<T>* newNode = new_node(newData);

    // Queue is empty
    if((*frontPtr) == nullptr && (*backPtr) == nullptr){
        *frontPtr = newNode;
        *backPtr = newNode;
        return;
    }

    // Queue is not empty
    (*backPtr)->next = newNode;
    *backPtr = newNode;
}

// Remove the front element
template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr){


    // Check if queue is empty
    if(*frontPtr == nullptr){
        std::cout << "Queue is empty!" << std::endl;
        return;
    }

    qNode<T>* deleteNode = *frontPtr;

    // Queue has only one node
    if((*frontPtr)->next == nullptr){
        *frontPtr = nullptr;
        *backPtr = nullptr;
        delete deleteNode;
        return;
    }

    // Queue has more than one node
    *frontPtr = deleteNode->next;
    delete deleteNode;
}

// Display all elements
template <typename T>
void display(qNode<T>* front){
    qNode<T>* temp = front;

    while(temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Return the front element
template <typename T>
T getFront(qNode<T>* front){

    if(front == nullptr){
     std::cout<<"Queue is empty!";
    }
    return front->data;
}

#endif
