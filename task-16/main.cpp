// Task 16. Write a program that tabulates a function and writes the results to a file.
// Tabulates f(x) = sin(x) for x in [0, 5] with step h = 0.5.

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    ofstream out("tabulation.txt");
    float x, h = 0.5f;

    for (x = 0; x <= 5; x += h)
        out << x << "\t" << sin(x) << endl;

    out.close();
    return 0;
}
