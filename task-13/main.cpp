// Task 13. Read a word, find its first vowel, and rearrange the word so it
// starts from that vowel, with the original prefix appended and "cyus" at the end.

#include <iostream>
#include <string>
using namespace std;

int main() {
    string w;
    cout << "Enter word: ";
    cin >> w;

    int i = 0;

    // Find first vowel
    while (i < (int)w.length() &&
           w[i] != 'a' && w[i] != 'e' && w[i] != 'i' &&
           w[i] != 'o' && w[i] != 'u')
        i++;

    if (i == (int)w.length()) {
        cout << "The word has no vowels." << endl;
    } else {
        cout << "Result: " << w.substr(i) << w.substr(0, i) << "cyus" << endl;
    }

    return 0;
}
