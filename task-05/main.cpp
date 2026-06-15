// Task 5. Fill an array of 50 random three-digit numbers [100, 999].
// Sort elements at indices 8-38 that are divisible by 5 using selection sort.
// Print the array before and after sorting.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int N = 50;
    int A[N];

    srand(time(0));

    // Fill array with random numbers in [100, 999]
    for (int i = 0; i < N; i++)
        A[i] = 100 + rand() % 900;

    // Print array before sorting
    cout << "Array before sorting: ";
    for (int i = 0; i < N; i++) cout << A[i] << " ";
    cout << endl;

    // Selection sort for multiples of 5 at indices 8-38
    for (int i = 7; i <= 37; i++) {
        if (A[i] % 5 != 0) continue;
        for (int j = i + 1; j <= 37; j++) {
            if (A[j] % 5 != 0) continue;
            if (A[j] < A[i]) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }

    // Print array after sorting
    cout << "Array after sorting:  ";
    for (int i = 0; i < N; i++) cout << A[i] << " ";
    cout << endl;

    return 0;
}
