#include <iostream>
#include <string>
#include <algorithm>

bool ist_palindrom(const std::string& text) {
    // Vergleicht den Text mit seiner Umkehrung
    return text == std::string(text.rbegin(), text.rend());
}

int main() {
    // Lese die Eingabe aus der Standardeingabe
    std::string zeichenkette;
    std::cout << "Geben Sie eine Zeichenkette ein: ";
    std::cin >> zeichenkette;

    // Prüfen, ob die Eingabe ein Palindrom ist
    if (ist_palindrom(zeichenkette)) {
        std::cout << "Palindrom" << std::endl;
    } else {
        std::cout << "Kein Palindrom" << std::endl;
    }
    return 0;
} 
