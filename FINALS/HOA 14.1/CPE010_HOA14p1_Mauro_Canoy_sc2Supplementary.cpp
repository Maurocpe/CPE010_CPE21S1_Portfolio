#include <iostream>
#include <chrono>

// Linear Search implementation from searchingAlgo.h
template <typename T>
void linearSearchArr(T data[], int arrSize, T dataFind){
    int i = 0;
    while(i < arrSize){
        if(dataFind == data[i]){
            return;
        }
        i++;
    }
}

// Helper function for Binary Search
template <typename T>
int getMiddle(T data[], int first, int last){
    return first + (last - first) / 2;
}

// Binary Search implementation from searchingAlgo.h
template <typename T>
void binarySearchArr(T data[], int arrSize, T findData){
    int first = 0;
    int last = arrSize - 1;

    while(first <= last){
        int middle = getMiddle(data, first, last);

        if(data[middle] == findData){
            return;
        }
        if(data[middle] < findData){
            first = middle + 1;
        } else {
            last = middle - 1;
        }
    }
}

// Benchmark function for worst-case scenario
void benchmarkSearch(int n) {
    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        arr[i] = i; // Populating sorted dataset
    }

    // Worst-case target: A value larger than any element in the array 
    // forces both searches to traverse/examine the maximum possible steps.
    int target = n + 1;

    // Benchmark Binary Search (Worst-Case)
    auto start = std::chrono::high_resolution_clock::now();
    binarySearchArr(arr, n, target);
    auto end = std::chrono::high_resolution_clock::now();
    double binTime = std::chrono::duration<double, std::milli>(end - start).count();

    // Benchmark Linear Search (Worst-Case)
    start = std::chrono::high_resolution_clock::now();
    linearSearchArr(arr, n, target);
    end = std::chrono::high_resolution_clock::now();
    double linTime = std::chrono::duration<double, std::milli>(end - start).count();

    std::cout << "Input Size (N) = " << n << "\n";
    std::cout << "  -> Binary Search (Worst-Case): " << binTime << " ms\n";
    std::cout << "  -> Linear Search (Worst-Case): " << linTime << " ms\n\n";

    delete[] arr;
}

int main() {
    int sizes[] = {1000, 10000, 100000};

    std::cout << "=== EMPIRICAL SEARCH ANALYSIS (WORST-CASE) ===\n\n";
    for(int n : sizes) {
        benchmarkSearch(n);
    }

    return 0;
}
