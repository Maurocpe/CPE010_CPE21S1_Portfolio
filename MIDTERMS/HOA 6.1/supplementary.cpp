#include <iostream>
#include "node.h"
#include "supplementary.h"

int main(){

    // PROBLEM 1
    int data[] = {
        15, 18, 2, 19, 18,
        0, 8, 14, 19, 14
    };

    int size = 10;
    int key = 18;
    std::cout << "PROBLEM 1\n";
    std::cout << "Array: ";

    for(int i = 0; i < size; i++){
        std::cout << data[i] << " ";
    }

    std::cout << "\nSearching for: " << key << std::endl;

    int arrayComparisons =
        linearSearchComparisonsArr(
            data,
            size,
            key
        );

    std::cout << "Array comparisons: "
              << arrayComparisons << std::endl;


    // Create linked list
    Node<int>* node1 = new_node(15);
    Node<int>* node2 = new_node(18);
    Node<int>* node3 = new_node(2);
    Node<int>* node4 = new_node(19);
    Node<int>* node5 = new_node(18);
    Node<int>* node6 = new_node(0);
    Node<int>* node7 = new_node(8);
    Node<int>* node8 = new_node(14);
    Node<int>* node9 = new_node(19);
    Node<int>* node10 = new_node(14);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;


    int linkedListComparisons =
        linearSearchComparisonsLL(
            node1,
            key
        );

    std::cout << "Linked list comparisons: "
              << linkedListComparisons << std::endl;

    // PROBLEM 2
    std::cout << "PROBLEM 2\n";
    int arrayCount =
        linearSearchCount(
            data,
            size,
            key
        );
    std::cout << "Number of occurrences of "
              << key << " in array: "
              << arrayCount << std::endl;
    int linkedListCount =
        linearSearchCountLL(
            node1,
            key
        );

    std::cout << "Number of occurrences of "
              << key << " in linked list: "
              << linkedListCount << std::endl;


    // PROBLEM 3
    std::cout << "PROBLEM 3\n";
    int sortedData[] = {
        3, 5, 6, 8, 11,
        12, 14, 15, 17, 18
    };

    int sortedSize = 10;
    int binaryKey = 8;
    std::cout << "Sorted array: ";
    for(int i = 0; i < sortedSize; i++){
        std::cout << sortedData[i] << " ";
    }
    std::cout << "\nSearching for: "
              << binaryKey << std::endl;
    std::cout << "\nBinary search iterations:\n";
    int binaryResult =
        binarySearchArr(
            sortedData,
            sortedSize,
            binaryKey
        );
    if(binaryResult != -1){
        std::cout << "The search was successful.\n";
        std::cout << binaryKey
                  << " was found at index "
                  << binaryResult << std::endl;
    }
    else{
        std::cout << "The search was unsuccessful.\n";
    }


    // PROBLEM 4
    std::cout << "PROBLEM 4\n";
    std::cout << "Sorted array: ";

    for(int i = 0; i < sortedSize; i++){
        std::cout << sortedData[i] << " ";
    }

    std::cout << "\nSearching for: "
              << binaryKey << std::endl;

    std::cout << "\nRecursive binary search iterations:\n";

    int recursiveResult =
        binarySearchRecursive(
            sortedData,
            0,
            sortedSize - 1,
            binaryKey
        );

    if(recursiveResult != -1){

        std::cout << "The search was successful.\n";
        std::cout << binaryKey
                  << " was found at index "
                  << recursiveResult << std::endl;
    }
    else{
        std::cout << "The search was unsuccessful.\n";
    }


    return 0;
}