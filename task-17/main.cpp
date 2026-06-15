// Task 18. A text file "group.txt" has lines with the following structure:
// the first 10 characters are the student's name, followed by the
// birth year and group number.
// Write to "out.txt" the records of students born in 2009.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream in("group.txt");
    ofstream out("out.txt");

    if (!in) {
        cout << "Error while opening group.txt\n";
        return 1;
    }

    if (!out) {
        cout << "Error while creating out.txt\n";
        return 1;
    }

    char name[11];
    int year, group;

    while (in.read(name, 10)) {
        name[10] = '\0';
        in >> year >> group;
        in.ignore();

        if (year == 2009)
            out << name << " " << year << " " << group << endl;
    }

    in.close();
    out.close();
    cout << "out.txt has been generated." << endl;
    return 0;
}
