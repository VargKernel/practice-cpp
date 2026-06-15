/*
Task 14. Create a Triangle class to represent a triangle.
Fields: sides (AB, BC, AC) and angles (ABC, BCA, CAB).
Operations: getters and setters, area calculation, perimeter calculation,
height calculation, triangle type determination.
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Triangle {
private:
    int AB, BC, AC;
    int ABC, BCA, CAB;

public:
    Triangle() {
        AB = 3; BC = 4; AC = 5;
        ABC = 90; BCA = 37; CAB = 53;
    }

    void setAB(int sideAB) { AB = sideAB; }
    void setBC(int sideBC) { BC = sideBC; }
    void setAC(int sideAC) { AC = sideAC; }

    void setABC(int angleABC) { ABC = angleABC; }
    void setBCA(int angleBCA) { BCA = angleBCA; }
    void setCAB(int angleCAB) { CAB = angleCAB; }

    int getAB() { return AB; }
    int getBC() { return BC; }
    int getAC() { return AC; }

    int getABC() { return ABC; }
    int getBCA() { return BCA; }
    int getCAB() { return CAB; }

    double getArea() {
        double p = getPerimeter() / 2.0;
        return sqrt(p * (p - AB) * (p - BC) * (p - AC));
    }

    int getPerimeter() {
        return AB + BC + AC;
    }

    void showHeights() {
        double s = getArea();
        cout << "Height to AB: " << (2.0 * s) / AB << endl;
        cout << "Height to BC: " << (2.0 * s) / BC << endl;
        cout << "Height to AC: " << (2.0 * s) / AC << endl;
    }

    string getType() {
        if (AB == BC && BC == AC) return "Equilateral";
        if (AB == BC || BC == AC || AB == AC) return "Isosceles";
        if (ABC == 90 || BCA == 90 || CAB == 90) return "Right-angled";
        return "Scalene";
    }

    void display() {
        cout << "Sides:  AB=" << AB  << ", BC=" << BC  << ", AC=" << AC  << endl;
        cout << "Angles: ABC=" << ABC << ", BCA=" << BCA << ", CAB=" << CAB << endl;
    }
};

void menu() {
    cout << "\n=============== MENU ===============\n";
    cout << "| 1. Show all                      |\n";
    cout << "| 2. Edit side                     |\n";
    cout << "| 3. Edit angle                    |\n";
    cout << "| 4. Calculate area                |\n";
    cout << "| 5. Calculate perimeter           |\n";
    cout << "| 6. Calculate heights             |\n";
    cout << "| 7. Determine type                |\n";
    cout << "| 0. Exit                          |\n";
    cout << "====================================\n";
    cout << "Choice: ";
}

int main() {
    Triangle tri;
    int choice;

    while (true) {
        menu();
        cin >> choice;

        if (choice == 0) {
            break;
        } else if (choice == 1) {
            tri.display();
        } else if (choice == 2) {
            string side; int value;
            cout << "Enter side (AB, BC, AC): "; cin >> side;
            cout << "Enter new value: "; cin >> value;
            if (side == "AB") tri.setAB(value);
            else if (side == "BC") tri.setBC(value);
            else if (side == "AC") tri.setAC(value);
            cout << "Value updated.\n";
        } else if (choice == 3) {
            string angle; int value;
            cout << "Enter angle (ABC, BCA, CAB): "; cin >> angle;
            cout << "Enter new value: "; cin >> value;
            if (angle == "ABC") tri.setABC(value);
            else if (angle == "BCA") tri.setBCA(value);
            else if (angle == "CAB") tri.setCAB(value);
            cout << "Value updated.\n";
        } else if (choice == 4) {
            cout << "Area: " << tri.getArea() << endl;
        } else if (choice == 5) {
            cout << "Perimeter: " << tri.getPerimeter() << endl;
        } else if (choice == 6) {
            tri.showHeights();
        } else if (choice == 7) {
            cout << "Type: " << tri.getType() << endl;
        }
    }
    return 0;
}
