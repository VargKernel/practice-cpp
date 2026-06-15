// Task 3. Given an array of 10 integers, find the arithmetic mean
// of all elements divisible by 3.

#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int arr[N] = { 3, 5, 9, 12, 7, 8, 6, 4, 15, 2 };

    int sum = 0;
    int count = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i] % 3 == 0) {
            sum += arr[i];
            count++;
        }
    }

    if (count > 0) {
        double average = (double)sum / count;
        cout << "Average of elements divisible by 3: " << average << endl;
    } else {
        cout << "No elements divisible by 3." << endl;
    }

    return 0;
}
