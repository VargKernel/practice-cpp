// Task 2. Read a string of characters and print all possible
// ordered pairs of those characters.

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;

    cout << "Enter characters: ";
    cin >> s;

    cout << "All possible character pairs:" << endl;
    for (int i = 0; i < (int)s.length(); i++) {
        for (int j = 0; j < (int)s.length(); j++)
            cout << s[i] << s[j] << " ";
        cout << endl;
    }

    return 0;
}
