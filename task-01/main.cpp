// Task 1. Find and output the first 4 perfect numbers.
// A perfect number equals the sum of its proper divisors.

#include <iostream>
using namespace std;

int main() {
    const int N = 4;
    int perfectNumbers[N];
    int count = 0;
    int num = 2;

    while (count < N) {
        int sum = 0;
        for (int i = 1; i <= num / 2; i++)
            if (num % i == 0) sum += i;
        if (sum == num)
            perfectNumbers[count++] = num;
        num++;
    }

    cout << "Perfect numbers: ";
    for (int i = 0; i < N; i++)
        cout << perfectNumbers[i] << " ";
    cout << endl;

    return 0;
}
