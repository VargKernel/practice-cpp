// Task 11. Read a string and count the occurrences of each character.
// Print the frequency table.

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    int cnt[256] = { 0 };

    for (int i = 0; i < (int)s.length(); i++)
        cnt[(unsigned char)s[i]]++;

    cout << "Character occurrence counts:" << endl;
    for (int i = 0; i < 256; i++)
        if (cnt[i] > 0)
            cout << (char)i << " : " << cnt[i] << endl;

    return 0;
}
