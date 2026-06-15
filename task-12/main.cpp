// Task 12.
// Part 1: Read a numeric string and a digit, compute and output their product.
// Part 2: Read 3 words and sort them alphabetically.

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int d, num = 0;

    cout << "Enter numeric string: ";
    cin >> s;

    cout << "Enter digit: ";
    cin >> d;

    for (int i = 0; i < (int)s.length(); i++)
        num = num * 10 + (s[i] - '0');

    cout << "Product: " << num * d << endl;

    cin.ignore();
    string a, b, c;

    cout << "Enter 3 words: ";
    cin >> a >> b >> c;

    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);

    cout << "Sorted: " << a << " " << b << " " << c << endl;

    return 0;
}
