#include "node.h"

#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

#include <iostream>


template <typename T>
void linearSearchArr(T data[], int arrSize, T dataFind){
    //step 1: I :=0
    int i = 0;
    //repeat while I <=n
    while(i < arrSize){
        if(dataFind == data[i]){
        std::cout <<"the search is a success\n";
        return;

        }
        //increment i to move to the next element
        i++;
    }

    std::cout<<"the element is not found \n";
    return;
}   


//Nodes -> starting node
template <typename T>
void linearSearchLL(Node<T>* node, T dataFind){
       
       //repeat the loop until the current node is not null
       while(node != nullptr){
        
        //if item = current node's data then display search is successful
        if(dataFind == node->data){
            std::cout<<"the search was a sucess\n";
            return;
        }

        //if not, move to the next node
        node = node->next;
       }

       //the searching reached nullptr -> search is unsuccessful
       std::cout<<"the search was unsuccessful \n";
       return;
}


template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){
     
     //use two pointers: 1. slow moves one node at a time, fast moves two at a time
     Node<T>* slow = start;
     Node<T>* fast = start;

     //get middle:
     while(fast != last && fast->next != last){

        //move slow (one step)
        slow = slow->next;

        //move fast (two steps)
        fast = fast->next->next;
     }

     //when fast reaches the end
     //slow points to the middle node
     return slow;
}


// Binary Search using Linked List
template <typename T>
void binarySearchLL(Node<T> *start, T findData){

    Node<T>* last = nullptr;

    while(start != last){

        //get the middle node
        Node<T>* middle = getMiddle(start, last);

        //if middle contains the data
        if(middle->data == findData){
            std::cout << "the search was a success\n";
            return;
        }

        //if findData is greater than middle data
        if(middle->data < findData){
            start = middle->next;
        }

        //if findData is smaller than middle data
        else{
            last = middle;
        }
    }

    std::cout << "the search was unsuccessful\n";
    return;
}

//create a binary search using array : getmiddle and binarySearchArr
template <typename T>
int getMiddle(T data[], int first, int last){

    return first + (last - first) / 2;
}


template <typename T>
void binarySearchArr(T data[], int arrSize, T findData){

    int first = 0;
    int last = arrSize - 1;

    while(first <= last){

        //get the middle index
        int middle = getMiddle(data, first, last);

        //if middle contains the data
        if(data[middle] == findData){
            std::cout << "the search was a success\n";
            return;
        }

        //if findData is greater than middle data
        if(data[middle] < findData){
            first = middle + 1;
        }

        //if findData is smaller than middle data
        else{
            last = middle - 1;
        }
    }

    std::cout << "the search was unsuccessful\n";
    return;
}


#endif