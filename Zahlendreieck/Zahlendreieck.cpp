//um (std::cout) zu verwenden
#include <iostream>

void print_triangle(int size) {
    if (size < 0) {
        size = 0;
    } else if (size > 9) {
        size = 9;
    }

    // Ausgabe des Dreiecks
    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << j;
        }
    //neuen Linie
        // std::cout << std::endl;
        std::cout << "\n";

    }
}

int main() {
    print_triangle(9);
    print_triangle(8);
    print_triangle(3);
    return 0;
}