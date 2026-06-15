/*
Task 23. Append information about 3 new universities (name, student count, faculty count) to "universities.txt".
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct University {
    string name;
    int students;
    int faculties;
};

int main() {
    ofstream outFile("universities.txt", ios::app);

    if (!outFile.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    cout << "Enter information for 3 new universities:\n";

    for (int i = 0; i < 3; i++) {
        University u;
        cout << "\nUniversity #" << i + 1 << "\n";
        cout << "Name: ";               cin >> u.name;
        cout << "Number of students: "; cin >> u.students;
        cout << "Number of faculties: "; cin >> u.faculties;

        outFile << u.name << " " << u.students << " " << u.faculties << endl;
    }

    outFile.close();
    cout << "\nSuccessfully added 3 universities to the file.\n";
    return 0;
}
