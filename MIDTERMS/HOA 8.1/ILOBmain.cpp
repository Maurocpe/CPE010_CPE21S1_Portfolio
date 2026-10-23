#include <iostream>
#include "sortingAlgoB.h"

int main()
{
    // PROBLEM 1
    std::cout << "PROBLEM 1" << std::endl;

    int arr1[] = {40, 20, 60, 10, 50, 30, 70};
    int size1 = 7;

    std::cout << "Original array: ";
    printArray(arr1, size1);

    // Partition the array
    int pivot = partition(arr1, 0, size1 - 1);

    std::cout << "After partition: ";
    printArray(arr1, size1);

    // using Insertion Sort
    insertionSort(arr1, 0, pivot - 1);
    insertionSort(arr1, pivot + 1, size1 - 1);

    std::cout << "After sorting sublists using Insertion Sort: ";
    printArray(arr1, size1);

    // PROBLEM 2
    std::cout << std::endl;
    std::cout << "PROBLEM 2" << std::endl;

    int arr2[] = {
        4, 34, 29, 48, 53,
        87, 12, 30, 44, 25,
        93, 67, 43, 19, 74
    };

    int size2 = 15;

    std::cout << "Original array: ";
    printArray(arr2, size2);

    // Sort the array using Merge Sort
    mergeSort(arr2, 0, size2 - 1);

    std::cout << "Sorted array using Merge Sort: ";
    printArray(arr2, size2);

    return 0;
}