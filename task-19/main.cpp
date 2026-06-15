// Task 19. Read real numbers from a file and produce a new file where
// adjacent elements are swapped.

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    if (!in) {
        cout << "Error while opening input.txt\n";
        return 1;
    }

    if (!out) {
        cout << "Error while creating output.txt\n";
        return 1;
    }

    double a, b;

    cout << "Result:\n";

    while (in >> a) {
        if (in >> b) {
            out << b << " " << a << " ";
            cout << b << " " << a << " ";
        } else {
            out << a << " ";
            cout << a << " ";
        }
    }

    in.close();
    out.close();
    return 0;
}
