/*
Task 20. Perform operations on data read from a file.
A matrix of integers is read from "test.in", various statistical
operations are applied, and results are written to "test.out".

Requirements: refactor into separate functions and add at least 5 custom
functions covering all possible matrix operations (each new function = 1 pt).
 */

#include <iostream>
#include <fstream>
using namespace std;

// Base functions:

bool openInputFile(ifstream& in) { // Open file for reading only
    in.open("test.in");
    if (!in) {
        cout << "Cannot open input file!";
        return false;
    }
    return true;
}

void allocateMatrix(int**& mat, int n, int m) { // Dynamically allocate memory for the matrix
    mat = new int*[n];
    for (int i = 0; i < n; ++i)
        mat[i] = new int[m];
}

void readMatrix(ifstream& in, int** mat, int n, int m) { // Read matrix from file
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            in >> mat[i][j];
}

double calculateSum(int** mat, int n, int m) { // Calculate sum of all elements
    double sum = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            sum += mat[i][j];
    return sum;
}

bool openOutputFile(ofstream& out) { // Open file for writing
    out.open("test.out");
    if (!out) {
        cout << "Cannot open output file!";
        return false;
    }
    return true;
}

void writeResult(ofstream& out, int** mat, int n, int m, double sum) { // Write matrix with each element divided by the total sum
    for (int i = 0; i < n; ++i, out << endl)
        for (int j = 0; j < m; ++j)
            out << '\t' << mat[i][j] / sum;
}

void freeMemory(int** mat, int n) { // Free dynamically allocated memory
    for (int i = 0; i < n; ++i)
        delete[] mat[i];
    delete[] mat;
}

// Custom functions:

int findMax(int** mat, int n, int m) { // Find the maximum element in the matrix
    int maxVal = mat[0][0];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (mat[i][j] > maxVal) maxVal = mat[i][j];
    return maxVal;
}

int findMin(int** mat, int n, int m) { // Find the minimum element in the matrix
    int minVal = mat[0][0];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (mat[i][j] < minVal) minVal = mat[i][j];
    return minVal;
}

int countEvenElements(int** mat, int n, int m) { // Count even elements
    int count = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (mat[i][j] % 2 == 0) count++;
    return count;
}

int countOddElements(int** mat, int n, int m) {  // Count odd elements
    int count = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (mat[i][j] % 2 != 0) count++;
    return count;
}

double calculateAverage(int** mat, int n, int m) { // Calculate arithmetic mean of all elements
    if (n == 0 || m == 0) return 0;
    return calculateSum(mat, n, m) / (n * m);
}

void printMatrixToConsole(int** mat, int n, int m) { // Print the matrix to the console
    cout << n << "x" << m << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << mat[i][j] << "\t";
        cout << endl;
    }
}

int countPositiveElements(int** mat, int n, int m) { // Count positive elements
    int count = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (mat[i][j] > 0) count++;
    return count;
}

int countNegativeElements(int** mat, int n, int m) { // Count negative elements
    int count = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (mat[i][j] < 0) count++;
    return count;
}

void printStatisticsToFile(ofstream& out, int** mat, int n, int m, double sum) {
    out << "Max element:    " << findMax(mat, n, m)               << endl;
    out << "Min element:    " << findMin(mat, n, m)               << endl;
    out << "Even count:     " << countEvenElements(mat, n, m)     << endl;
    out << "Odd count:      " << countOddElements(mat, n, m)      << endl;
    out << "Average:        " << calculateAverage(mat, n, m)      << endl;
    out << "Positive count: " << countPositiveElements(mat, n, m) << endl;
    out << "Negative count: " << countNegativeElements(mat, n, m) << endl;
    out << "Total sum:      " << sum                              << endl;
}

int main() {
    ifstream in;
    if (!openInputFile(in)) return 0;

    int n, m;
    in >> n >> m;

    int** mat;
    allocateMatrix(mat, n, m);
    readMatrix(in, mat, n, m);

    printMatrixToConsole(mat, n, m);

    double sum = calculateSum(mat, n, m);

    ofstream out;
    if (openOutputFile(out)) {
        printStatisticsToFile(out, mat, n, m, sum);
        writeResult(out, mat, n, m, sum);
        out.close();
    }

    freeMemory(mat, n);
    return 0;
}
