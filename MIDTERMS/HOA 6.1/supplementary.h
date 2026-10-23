#include "node.h"

#ifndef SUPPLEMENTARY_H
#define SUPPLEMENTARY_H

#include <iostream>
// PROBLEM 1 - Linear Search for Array
template <typename T>
int linearSearchComparisonsArr(T data[], int arrSize, T dataFind){
    int comparisons = 0;
    for(int i = 0; i < arrSize; i++){
        comparisons++;
        if(data[i] == dataFind){
            return comparisons;
        }
    }

    return comparisons;
}
// PROBLEM 1 - Linear Search for Linked List
template <typename T>
int linearSearchComparisonsLL(Node<T>* node, T dataFind){
    int comparisons = 0;
    while(node != nullptr){
        comparisons++;
        if(node->data == dataFind){
            return comparisons;
        }
        node = node->next;
    }
    return comparisons;
}
// PROBLEM 2 - Count Repeating Instances in Array
template <typename T>
int linearSearchCount(T data[], int arrSize, T dataFind){
    int count = 0;
    for(int i = 0; i < arrSize; i++){
        if(data[i] == dataFind){
            count++;
        }
    }
    return count;
}

// PROBLEM 2 - Count Repeating Instances in Linked List
template <typename T>
int linearSearchCountLL(Node<T>* node, T dataFind){
    int count = 0;
    while(node != nullptr){
        if(node->data == dataFind){
            count++;
        }
        node = node->next;
    }
    return count;
}

// Get middle element
template <typename T>
int getMiddle(T data[], int first, int last){

    return first + (last - first) / 2;
}

// PROBLEM 3 - Iterative Binary Search
template <typename T>
int binarySearchArr(T data[], int arrSize, T findData){
    int first = 0;
    int last = arrSize - 1;
    while(first <= last){
        int middle = getMiddle(data, first, last);
        std::cout << "Middle element: "
                  << data[middle] << std::endl;
        if(data[middle] == findData){
            return middle;
        }
        if(data[middle] < findData){
            first = middle + 1;
        }
        else{
            last = middle - 1;
        }
    }
    return -1;
}

// PROBLEM 4 - Recursive Binary Search
template <typename T>
int binarySearchRecursive(
    T data[],
    int first,
    int last,
    T findData
){

    if(first > last){
        return -1;
    }
    int middle = getMiddle(data, first, last);

    std::cout << "Middle element: "
              << data[middle] << std::endl;
    if(data[middle] == findData){
        return middle;
    }
    if(data[middle] < findData){

        return binarySearchRecursive(
            data,
            middle + 1,
            last,
            findData
        );
    }
    return binarySearchRecursive(
        data,
        first,
        middle - 1,
        findData
    );
}
#endif