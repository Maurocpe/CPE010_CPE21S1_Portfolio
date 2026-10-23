#ifndef SORTING_H
#define SORTING_H 

#include <iostream>

template <typename T>
void bubbleSort(T arr[], int arrSize){
     for(int i = 0; i < arrSize; i++){
      for(int j = i+1; j < arrSize; j++){

          if(arr[j] < arr [i]){
            std::swap(arr[j], arr[i]);
          }

      }


     }


}

template <typename T>
void insertionSort(T arr[], int arrSize){
      int k = 1, j;
      T temp;


      while(k < arrSize){
        temp = arr[k]; //1 this is the sort (which sort?)
        j = k-1;
        while(j>= 0 && temp <= arr[j]){
            arr[j+1] = arr[j]; //2 this is the sort(which sort?)
            j--;
        }
        arr[j+1] = temp; //3 this is the sort (which sort?)
        k++; 
      }


}


template <typename T>
int routine_smallest(T A[], int arrSize, int k){

    int position = k , j;
    T smallestElem = A[k];

    for(int j = k+1; j < arrSize; j++){
        if(A[j] < smallestElem){
            smallestElem = A[j];
            position = j;
        }
    }
    return position;
}


template <typename T>
void selectionSort(T arr[], int arrSize){
     int pos, temp; //returns the value of min
     
     for(int i = 0; i < arrSize; i++){

         pos = routine_smallest(arr, arrSize, i); //returns the index of the smallest value;
         
         temp = arr[i];
         arr[i] = arr[pos];
         arr[pos] = temp;


     }




}

#endif