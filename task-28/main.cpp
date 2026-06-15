// Task 28: Given a list of 10 products (name, price, count), search for a product
// by name and apply a random discount of 5-30%. Display the result.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Product {
    string name;
    double price;
    int count;
};

Product storage[10] = {
    { "Laptop",       24500.0, 12 },
    { "Router",        1450.5, 30 },
    { "Switch",        3200.0,  8 },
    { "SSD Drive",     1850.0, 25 },
    { "RAM Module",    2100.0, 40 },
    { "Monitor",       6800.0, 15 },
    { "Keyboard",       950.0, 50 },
    { "Mouse",          450.5, 65 },
    { "Server Case",   4100.0,  5 },
    { "Power Supply",  2300.0, 18 }
};

void showData(Product s) {
    cout << "NAME: "  << s.name
         << " | PRICE: " << s.price << " $"
         << " | COUNT: " << s.count << endl;
}

int main() {
    srand(time(0));

    for (int i = 0; i < 10; i++)
        showData(storage[i]);

    bool found = false;
    string searchName;

    cout << "\nEnter product name to search: ";
    getline(cin, searchName);

    for (int i = 0; i < 10; i++) {
        if (storage[i].name == searchName) {
            found = true;
            int discountPercent = rand() % (30 - 5 + 1) + 5;
            double discountAmount = storage[i].price * discountPercent / 100.0;
            double newPrice = storage[i].price - discountAmount;

            cout << "\n--- RESULT ---\n";
            cout << "NAME:             " << storage[i].name  << "\n";
            cout << "COUNT:            " << storage[i].count << "\n";
            cout << "PRICE:            " << storage[i].price << " $\n";
            cout << "DISCOUNT:         " << discountPercent  << "%\n";
            cout << "DISCOUNTED PRICE: " << newPrice         << " $\n";
            break;
        }
    }

    if (!found)
        cout << searchName << " -> Not found.\n";

    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}
