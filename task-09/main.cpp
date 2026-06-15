// Task 9. Given a 2x2 matrix, find the minimum and maximum elements,
// swap them, and print the result.

#include <iostream>
using namespace std;

int main() {
    int X[2][2] = {
        {  5, -3 },
        { 10,  2 }
    };

    int minVal = X[0][0], maxVal = X[0][0];
    int minI = 0, minJ = 0;
    int maxI = 0, maxJ = 0;

    // Find min and max
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (X[i][j] < minVal) {
                minVal = X[i][j];
                minI = i; minJ = j;
            }
            if (X[i][j] > maxVal) {
                maxVal = X[i][j];
                maxI = i; maxJ = j;
            }
        }
    }

    // Swap min and max
    int temp = X[minI][minJ];
    X[minI][minJ] = X[maxI][maxJ];
    X[maxI][maxJ] = temp;

    cout << "Result:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << X[i][j] << " ";
        cout << endl;
    }

    return 0;
}
