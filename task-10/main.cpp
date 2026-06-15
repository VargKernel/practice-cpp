// Task 10. Given a 3x4 matrix, read its elements column by column,
// collect the negative ones into a vector, and print the vector.

#include <iostream>
using namespace std;

int main() {
    const int R = 3;
    const int C = 4;

    int A[R][C] = {
        {  5, -2,  7, -1 },
        { -3,  4, -6,  8 },
        {  9, -5,  2, -4 }
    };

    int V[12]; // vector for negative elements
    int k = 0; // element counter

    // Collect negative elements column by column
    for (int j = 0; j < C; j++)
        for (int i = 0; i < R; i++)
            if (A[i][j] < 0)
                V[k++] = A[i][j];

    cout << "Vector of negative elements: ";
    for (int i = 0; i < k; i++)
        cout << V[i] << " ";
    cout << endl;

    return 0;
}
