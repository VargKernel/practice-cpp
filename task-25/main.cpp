// Task 25. Read text from "f.txt". Format sentences:
// - the first letter of each sentence is capitalized, the rest are lowercase;
// - words within a sentence are separated by a single space;
// - '#' in the input marks the end of a sentence and becomes '.' in the output.
// Write the result to "q.txt".

#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    ifstream inFile("f.txt");
    ofstream outFile("q.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Error opening files!" << endl;
        return 1;
    }

    char ch;
    bool newSentence = true;    // next letter should be uppercase
    bool inWord = false;        // tracks spaces between words
    bool firstOutput = true;    // prevents leading space

    while (inFile.get(ch)) {
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            if (inWord) inWord = false;
        } else if (ch == '#') {
            outFile << '.';
            newSentence = true;
            inWord = false;
        } else {
            if (newSentence) {
                if (!firstOutput) outFile << ' ';
                outFile << (char)toupper(ch);
                newSentence = false;
                firstOutput = false;
            } else {
                if (!inWord) outFile << ' ';
                outFile << (char)tolower(ch);
            }
            inWord = true;
        }
    }

    inFile.close();
    outFile.close();

    cout << "File processed successfully." << endl;
    return 0;
}
