
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

// Checks if the array contains duplicate elements
bool Unique(vector<int> A) {
    int n = A.size();

    // Picks one element to compare with the others
    for (int i = 0; i < n; i++) {

        // Compares it with the elements after it
        for (int j = i + 1; j < n; j++) {

            // If two elements are equal, a duplicate is found
            if (A[i] == A[j]) {
                return false;
            }
        }
    }

    // If no duplicates are found, all elements are unique
    return true;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive array size." << endl;
        return 0;
    }

    vector<int> A(n);

    // Fills the array with different numbers for testing
    for (int i = 0; i < n; i++) {
        A[i] = i;
    }

    auto start = high_resolution_clock::now();

    bool result = Unique(A);

    auto end = high_resolution_clock::now();

    // Calculates how long the algorithm took
    double runtime = duration<double, milli>(end - start).count();

    cout << "All elements are unique: "
         << (result ? "True" : "False") << endl;
    cout << "Runtime: " << runtime << " milliseconds" << endl;

    return 0;
}
