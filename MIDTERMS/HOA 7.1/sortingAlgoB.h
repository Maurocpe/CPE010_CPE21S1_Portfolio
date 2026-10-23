#ifndef SORTING_H
#define SORTING_H

#include <iostream>

template <typename T>
void bubbleSort(T arr[], int arrSize){

    for(int i = 0; i < arrSize; i++){

        for(int j = 0; j < arrSize - 1; j++){

            if(arr[j] > arr[j + 1]){
                std::swap(arr[j], arr[j + 1]);
            }

        }

    }

}

// Counts the votes from 1 to 5
template <typename T>
void countVotes(T arr[], int arrSize){

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;

    for(int i = 0; i < arrSize; i++){

        if(arr[i] == 1){
            count1++;
        }
        else if(arr[i] == 2){
            count2++;
        }
        else if(arr[i] == 3){
            count3++;
        }
        else if(arr[i] == 4){
            count4++;
        }
        else if(arr[i] == 5){
            count5++;
        }

    }

    std::cout << "\nCount Result of Algorithm:\n";
    std::cout << "Candidate 1 - Bo Dalton Capistrano: "
              << count1 << " votes\n";

    std::cout << "Candidate 2 - Cornelius Raymon Agustin: "
              << count2 << " votes\n";

    std::cout << "Candidate 3 - Deja Jayla Banaga: "
              << count3 << " votes\n";

    std::cout << "Candidate 4 - Laila Brielle Yabut: "
              << count4 << " votes\n";

    std::cout << "Candidate 5 - Franklin Relano Castro: "
              << count5 << " votes\n";
}

#endif