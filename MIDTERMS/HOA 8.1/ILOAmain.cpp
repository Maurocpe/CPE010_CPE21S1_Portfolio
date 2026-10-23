#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

using namespace std;

const int SIZE = 100;

void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";

        if ((i + 1) % 10 == 0)
        {
            cout << endl;
        }
    }
}

void copyArray(int source[], int destination[], int size)
{
    for (int i = 0; i < size; i++)
    {
        destination[i] = source[i];
    }
}

int main()
{
    int original[SIZE];
    int shellArray[SIZE];
    int mergeArray[SIZE];
    int quickArray[SIZE];

    srand(time(0));

    for (int i = 0; i < SIZE; i++)
    {
        original[i] = rand() % 1000 + 1;
    }

    copyArray(original, shellArray, SIZE);
    copyArray(original, mergeArray, SIZE);
    copyArray(original, quickArray, SIZE);

    cout << "Original Unsorted Array:" << endl;
    displayArray(original, SIZE);

    shellSort(shellArray, SIZE);

    mergeSort(mergeArray, 0, SIZE - 1);

    quickSort(quickArray, 0, SIZE - 1);

    cout << endl;
    cout << "Shell Sort:" << endl;
    displayArray(shellArray, SIZE);

    cout << endl;
    cout << "Merge Sort:" << endl;
    displayArray(mergeArray, SIZE);

    cout << endl;
    cout << "Quick Sort:" << endl;
    displayArray(quickArray, SIZE);

    return 0;
}