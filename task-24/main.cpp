// Task 24. Tabulate f(x) = sin^3(x) on [0, pi/2] with step h = 0.1.
// Find and print the maximum and minimum values.
// Write the results to "output.txt".

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    ofstream outFile("output.txt");
    if (!outFile.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    double a = 0.0;
    double b = acos(-1.0) / 2.0;
    double h = 0.1;

    cout    << "     x       f(x)\n" << "--------------------\n";
    outFile << "     x       f(x)\n" << "--------------------\n";

    double x = a;
    double maxF = pow(sin(a), 3);
    double minF = maxF;

    while (x <= b + 0.0001) {
        double fx = pow(sin(x), 3);

        if (fx > maxF) maxF = fx;
        if (fx < minF) minF = fx;

        cout    << "   " << x << "    " << fx << "\n";
        outFile << "   " << x << "    " << fx << "\n";

        x += h;
    }

    cout    << "--------------------\n" << "MAX = " << maxF << "   MIN = " << minF << "\n";
    outFile << "--------------------\n" << "MAX = " << maxF << "   MIN = " << minF << "\n";

    outFile.close();
    return 0;
}
