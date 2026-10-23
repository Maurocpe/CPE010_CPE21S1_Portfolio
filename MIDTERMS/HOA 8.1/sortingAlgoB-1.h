#ifndef SORTING_H
#define SORTING_H

#include <iostream>

// Insertion Sort
template <typename T>
void insertionSort(T arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        T key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Partition Method for Quick Sort
template <typename T>
int partition(T arr[], int left, int right)
{
    T pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;

            T temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    T temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1;
}

// Quick Sort
template <typename T>
void quickSort(T arr[], int left, int right)
{
    if (left < right)
    {
        int pivot = partition(arr, left, right);

        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

// Merge Function
template <typename T>
void merge(T arr[], int left, int mid, int right)
{
    int size = right - left + 1;
    T* temp = new T[size];

    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int x = 0; x < size; x++)
    {
        arr[left + x] = temp[x];
    }

    delete[] temp;
}

// Merge Sort
template <typename T>
void mergeSort(T arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Display Array
template <typename T>
void printArray(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

#endif