// Task 21. Read all words from "f.txt" and write to "q.txt" only those words
// that appear exactly once (no duplicates).

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream inFile("f.txt");
    if (!inFile.is_open()) {
        cout << "Error opening f.txt!" << endl;
        return 1;
    }

    vector<string> allWords;
    string word;

    while (inFile >> word)
        allWords.push_back(word);
    inFile.close();

    ofstream outFile("q.txt");

    for (size_t i = 0; i < allWords.size(); i++) {
        int count = 0;
        for (size_t j = 0; j < allWords.size(); j++)
            if (allWords[i] == allWords[j]) count++;

        if (count == 1)
            outFile << allWords[i] << " ";
    }
    outFile.close();

    cout << "Done!" << endl;
    return 0;
}
