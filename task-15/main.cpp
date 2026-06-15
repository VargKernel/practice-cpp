/*
Task 15. Implement a Storage class for a warehouse inventory system.
Requirements:
- Default and parameterized constructors
- Add and remove objects
- Display information on screen
- Search by name
- Edit records
- Sort by different fields (price, name, ID)
*/

#include <iostream>
#include <string>
using namespace std;

class Storage {
private:
    int number;
    string name;
    float weight;
    float price;
    int count;

public:
    Storage() {
        number = 0;
        name = "none";
        weight = 0.0f;
        price = 0.0f;
        count = 0;
    }

    Storage(int num, string nm, float w, float p, int c) {
        number = num;
        name = nm;
        weight = w;
        price = p;
        count = c;
    }

    int getNumber() { return number; }
    string getName() { return name; }
    float getPrice() { return price; }

    void edit(string nm, float p, int c) {
        name = nm;
        price = p;
        count = c;
    }

    void display() {
        cout << "ID: " << number
             << " | Name: " << name
             << " | Weight: " << weight << " kg"
             << " | Price: " << price << " USD"
             << " | Count: " << count << endl;
    }
};

void menu() {
    cout << "========== MENU ==========\n";
    cout << "| 1. Add product         |\n";
    cout << "| 2. Remove product      |\n";
    cout << "| 3. Edit product        |\n";
    cout << "| 4. Search by name      |\n";
    cout << "| 5. Show all            |\n";
    cout << "| 6. Sort by price       |\n";
    cout << "| 7. Sort by name        |\n";
    cout << "| 8. Sort by ID          |\n";
    cout << "| 0. Exit                |\n";
    cout << "==========================\n";
    cout << "Choice: ";
}

int main() {
    Storage inventory[100];
    int total = 0;
    int choice;

    while (true) {
        menu();
        cin >> choice;

        if (choice == 0) {
            break;
        } else if (choice == 1) { // Add object
            if (total < 100) {
                int n, c;
                string nm;
                float w, p;

                cout << "ID: ";           cin >> n;
                cin.ignore();
                cout << "Name: ";         getline(cin, nm);
                cout << "Weight (kg): ";  cin >> w;
                cout << "Price (USD): ";  cin >> p;
                cout << "Count: ";        cin >> c;

                inventory[total++] = Storage(n, nm, w, p, c);
            } else {
                cout << "Inventory is full!\n";
            }
        } else if (choice == 2) { // Remove object
            int id;
            cout << "Enter ID to delete: "; cin >> id;
            for (int i = 0; i < total; i++) {
                if (inventory[i].getNumber() == id) {
                    for (int j = i; j < total - 1; j++)
                        inventory[j] = inventory[j + 1];
                    total--;
                    cout << "Deleted.\n";
                    break;
                }
            }
        } else if (choice == 3) { // Edit record
            int id;
            cout << "Enter ID to edit: "; cin >> id;
            for (int i = 0; i < total; i++) {
                if (inventory[i].getNumber() == id) {
                    string nm; float p; int c;
                    cin.ignore();
                    cout << "New Name: ";        getline(cin, nm);
                    cout << "New Price (USD): "; cin >> p;
                    cout << "New Count: ";       cin >> c;
                    inventory[i].edit(nm, p, c);
                    break;
                }
            }
        } else if (choice == 4) { // Search by name
            string searchName;
            cin.ignore();
            cout << "Name to search: "; getline(cin, searchName);
            for (int i = 0; i < total; i++)
                if (inventory[i].getName() == searchName)
                    inventory[i].display();
        } else if (choice == 5) {  // Display all
            for (int i = 0; i < total; i++)
                inventory[i].display();
        } else if (choice == 6) { // Sort by price
            for (int i = 0; i < total - 1; i++)
                for (int j = 0; j < total - i - 1; j++)
                    if (inventory[j].getPrice() > inventory[j + 1].getPrice()) {
                        Storage temp = inventory[j];
                        inventory[j] = inventory[j + 1];
                        inventory[j + 1] = temp;
                    }
            cout << "Sorted by price:\n";
            for (int i = 0; i < total; i++) inventory[i].display();
        } else if (choice == 7) { // Sort by name
            for (int i = 0; i < total - 1; i++)
                for (int j = 0; j < total - i - 1; j++)
                    if (inventory[j].getName() > inventory[j + 1].getName()) {
                        Storage temp = inventory[j];
                        inventory[j] = inventory[j + 1];
                        inventory[j + 1] = temp;
                    }
            cout << "Sorted by name:\n";
            for (int i = 0; i < total; i++) inventory[i].display();
        } else if (choice == 8) { // Sort by ID
            for (int i = 0; i < total - 1; i++)
                for (int j = 0; j < total - i - 1; j++)
                    if (inventory[j].getNumber() > inventory[j + 1].getNumber()) {
                        Storage temp = inventory[j];
                        inventory[j] = inventory[j + 1];
                        inventory[j + 1] = temp;
                    }
            cout << "Sorted by ID:\n";
            for (int i = 0; i < total; i++) inventory[i].display();
        }
    }
    return 0;
}
