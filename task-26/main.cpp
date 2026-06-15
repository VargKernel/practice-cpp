/*
Task 26. Read characters from "f.txt" and count the occurrences of vowel. Write a frequency table to "table.txt".
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("f.txt");
    ofstream outFile("table.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Error opening files!" << endl;
        return 1;
    }

    string vowels = "aeiouy";
    int counts[16] = { 0 };

    char ch;
    while (inFile >> ch) {
        ch = tolower(ch);
        for (size_t i = 0; i < vowels.length(); i++) {
            if (ch == vowels[i]) {
                counts[i]++;
                break;
            }
        }
    }

    outFile << "Letter\tCount\n" << "----------------\n";
    for (size_t i = 0; i < vowels.length(); i++)
        if (counts[i] > 0)
            outFile << vowels[i] << "\t" << counts[i] << "\n";

    inFile.close();
    outFile.close();

    cout << "Done!" << endl;
    return 0;
}
