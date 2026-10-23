
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "sortingAlgoA.h"

void displayTime(const char* algorithm, const char* testCase,
                 int arrSize, double elapsed) {
    std::cout << algorithm << " | "
              << testCase << " | n = " << arrSize
              << " | Time: " << elapsed << " microseconds\n";
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int sizes[] = {100, 1000, 10000};

    for (int s = 0; s < 3; s++) {
        int n = sizes[s];

        int* original = new int[n];
        int* arr = new int[n];

        for (int i = 0; i < n; i++) {
            original[i] = rand() % 100000;
        }

        for (int test = 0; test < 3; test++) {
            for (int i = 0; i < n; i++) {
                if (test == 0)
                    arr[i] = i;
                else if (test == 1)
                    arr[i] = original[i];
                else
                    arr[i] = n - i;
            }

            const char* cases[] = {
                "Best (Sorted)",
                "Average (Random)",
                "Worst (Reverse)"
            };

            auto start = std::chrono::high_resolution_clock::now();
            bubbleSort(arr, n);
            auto end = std::chrono::high_resolution_clock::now();

            double elapsed =
                std::chrono::duration<double, std::micro>(end - start).count();

            displayTime("Bubble Sort", cases[test], n, elapsed);

            for (int i = 0; i < n; i++) {
                if (test == 0)
                    arr[i] = i;
                else if (test == 1)
                    arr[i] = original[i];
                else
                    arr[i] = n - i;
            }

            start = std::chrono::high_resolution_clock::now();
            selectionSort(arr, n);
            end = std::chrono::high_resolution_clock::now();

            elapsed =
                std::chrono::duration<double, std::micro>(end - start).count();

            displayTime("Selection Sort", cases[test], n, elapsed);
        }

        delete[] original;
        delete[] arr;

        std::cout << "-----------------------------\n";
    }

    return 0;
}
