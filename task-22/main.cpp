// Task 22. Read words from "f.txt" and write to "result.txt" only those words
// that contain a given substring entered by the user.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("f.txt");
    ofstream outFile("result.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Error opening files!" << endl;
        return 1;
    }

    string p;
    cout << "Enter substring: ";
    cin >> p;

    string word;
    while (inFile >> word)
        if (word.find(p) != string::npos)
            outFile << word << " ";

    inFile.close();
    outFile.close();

    cout << "Done!" << endl;
    return 0;
}
