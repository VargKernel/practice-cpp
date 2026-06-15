// Task 4. Search for a given element in an array using linear search.
// Output its 1-based position, or a "not found" message.

#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int arr[N] = { 2, 5, 7, 10, 12, 15, 18, 20, 25, 30 };
    int key;
    bool found = false;

    cout << "Enter element to search: ";
    cin >> key;

    for (int i = 0; i < N; i++) {
        if (arr[i] == key) {
            cout << "Element found at position: " << i + 1 << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Element not found." << endl;

    return 0;
}
