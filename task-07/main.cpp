// Task 7. Given winning lottery ticket numbers and their prize amounts (USD),
// check a set of user-provided ticket numbers and output the total winnings.

#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int A[N] = { 1, 2, 5, 6, 7, 8, 9, 10 };                        // winning numbers
    int C[N] = { 50, 100, 75, 200, 150, 80, 120, 60, 90, 300 };    // prize amounts (USD)

    int t;
    cout << "Enter number of tickets to check: ";
    cin >> t;

    int sum = 0;

    for (int j = 0; j < t; j++) {
        int number;
        cout << "Enter ticket number: ";
        cin >> number;

        for (int i = 0; i < N; i++) {
            if (A[i] == number) {
                sum += C[i];
                break;
            }
        }
    }

    cout << "Total winnings: " << sum << " USD" << endl;

    return 0;
}
