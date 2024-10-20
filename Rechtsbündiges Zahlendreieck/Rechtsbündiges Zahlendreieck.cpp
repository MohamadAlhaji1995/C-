#include <iostream>
////um (setw und setfill) zu verwenden
#include <iomanip>
using namespace std;

void print_triangle(int n, bool right_align = false) {
    for (int i = 1; i <= n; ++i) {
        if (right_align) {
            //setw(n): Legt die Breite des nächsten Ausgabebereichs auf n Zeichen fest.
            //Füllt den verbleibenden Raum links vom Text mit Leerzeichen auf.
            cout << setw(n - i +1) << setfill(' ');
        }
        for (int j = 1; j <= i; ++j) {
            cout << j;
        }
        //cout << endl;
        std::cout << "\n";

    }
}

int main() {
    cout << "Standardausgabe:" << endl;
    print_triangle(9);

    cout << "\nRechtsbündig ausgerichtet:" << endl;
    print_triangle(9, true);
    //print_triangle(8, true);
    return 0;
}
