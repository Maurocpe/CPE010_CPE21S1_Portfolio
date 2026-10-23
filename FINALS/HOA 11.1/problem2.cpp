
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

// Regular method: reduces the exponent by one each time
double rpower(double x, int n) {
    if (n == 0)
        return 1;

    return x * rpower(x, n - 1);
}

// Faster method: divides the exponent to reduce the work
double brpower(double x, int n) {
    if (n == 0)
        return 1;

    // If n is odd, calculate half the exponent first
    if (n % 2 != 0) {
        double y = brpower(x, (n - 1) / 2);
        return x * y * y;
    }

    // If n is even, divide the exponent by two
    double y = brpower(x, n / 2);
    return y * y;
}

int main() {
    double x;
    int n;

    cout << "Enter base x: ";
    cin >> x;

    cout << "Enter exponent n: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a nonnegative exponent." << endl;
        return 0;
    }

    // Measures the runtime of the regular method
    auto start1 = high_resolution_clock::now();
    double result1 = rpower(x, n);
    auto end1 = high_resolution_clock::now();

    // Measures the runtime of the faster method
    auto start2 = high_resolution_clock::now();
    double result2 = brpower(x, n);
    auto end2 = high_resolution_clock::now();

    double time1 = duration<double, milli>(end1 - start1).count();
    double time2 = duration<double, milli>(end2 - start2).count();

    cout << "\nRegular Power (rpower)" << endl;
    cout << "Result: " << result1 << endl;
    cout << "Runtime: " << time1 << " milliseconds" << endl;

    cout << "\nFast Power (brpower)" << endl;
    cout << "Result: " << result2 << endl;
    cout << "Runtime: " << time2 << " milliseconds" << endl;

    return 0;
}
