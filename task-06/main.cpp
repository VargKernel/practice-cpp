// Task 6. Count the number of negative elements in an array of 10 integers.

#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int arr[N] = { -3, 5, -7, 12, 0, -1, 8, -4, 6, -9 };

    int count = 0;

    for (int i = 0; i < N; i++)
        if (arr[i] < 0) count++;

    cout << "Number of negative elements: " << count << endl;

    return 0;
}
