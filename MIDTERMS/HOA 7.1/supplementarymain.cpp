#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgoB.h"

const int size = 101;

void displayArr(int array[]);

int main(){

    int arr[size];

    srand(time(0));

    // Generate 101 votes from 1 to 5
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 5 + 1;
    }

    std::cout << "Original Array:\n";
    displayArr(arr);

    // Bubble Sort
    bubbleSort(arr, size);

    std::cout << "\nSorted Array:\n";
    displayArr(arr);

    // Count votes
    countVotes(arr, size);

    return 0;
}

void displayArr(int array[]){

    for(int i = 0; i < size; i++){
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
}