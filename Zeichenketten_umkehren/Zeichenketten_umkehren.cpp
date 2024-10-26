#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cout << "Bitte geben Sie eine Zeichenkette ein: ";
    std::cin >> input;

    // Zeichenkette in umgekehrter Reihenfolge ausgeben
    for (int i = std::size(input) - 1; i >= 0; --i) {
        std::cout << input[i];
    }
    std::cout << std::endl;

    return 0;
}
