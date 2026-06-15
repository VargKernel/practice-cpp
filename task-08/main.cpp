// Task 8. Fill a 5x5 matrix with 1s on the anti-diagonal
// and 0s elsewhere. Print the matrix.

#include <iostream>
using namespace std;

void printMatrix(int A[][5], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int A[5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            A[i][j] = (j == 4 - i) ? 1 : 0;

    printMatrix(A, 5, 5);
    return 0;
}
