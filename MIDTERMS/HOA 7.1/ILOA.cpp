#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgoA.h"

const int size = 100;

void displayArr(int array[]);

int main(){

    int arr[size];

    srand(time(0));

    // Generate random values
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 100;
    }

    // Display original array
    std::cout << "Original Array:\n";
    displayArr(arr);

    // BUBBLE SORT
    int bubbleArr[size];

    for(int i = 0; i < size; i++){
        bubbleArr[i] = arr[i];
    }

    std::cout << "\nBubble Sort:\n";
    bubbleSort(bubbleArr, size);
    displayArr(bubbleArr);

    // SELECTION SORT
    int selectionArr[size];

    for(int i = 0; i < size; i++){
        selectionArr[i] = arr[i];
    }

    std::cout << "\nSelection Sort:\n";
    selectionSort(selectionArr, size);
    displayArr(selectionArr);

    // INSERTION SORT
    int insertionArr[size];

    for(int i = 0; i < size; i++){
        insertionArr[i] = arr[i];
    }

    std::cout << "\nInsertion Sort:\n";
    insertionSort(insertionArr, size);
    displayArr(insertionArr);


    return 0;
}

void displayArr(int array[]){

    for(int i = 0; i < size; i++){
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
}