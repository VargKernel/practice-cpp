// Task 18. A file contains coordinates of vertices of 20 rectangles on a plane.
// Write to a new file the coordinates of the largest and smallest rectangles
// by area, along with their index in the source file.

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int x1, y1, x2, y2;
    double s, sMax = -1.0, sMin = 1e18;
    int xMax1, yMax1, xMax2, yMax2;
    int xMin1, yMin1, xMin2, yMin2;

    for (int i = 1; i <= 20; ++i) {
        in >> x1 >> y1 >> x2 >> y2;

        s = fabs(x2 - x1) * fabs(y2 - y1);

        if (s > sMax) {
            sMax = s;
            xMax1 = x1; yMax1 = y1; xMax2 = x2; yMax2 = y2;
        }
        if (s < sMin) {
            sMin = s;
            xMin1 = x1; yMin1 = y1; xMin2 = x2; yMin2 = y2;
        }
    }

    out << "Largest:  " << xMax1 << " " << yMax1 << " " << xMax2 << " " << yMax2
        << ", S = " << sMax << "\n";
    out << "Smallest: " << xMin1 << " " << yMin1 << " " << xMin2 << " " << yMin2
        << ", S = " << sMin << "\n";

    return 0;
}
