#include <iostream>
#include <string>

struct Contact {
    std::string last_name;  // Nachname des Kontakts
    std::string first_name; // Vorname des Kontakts

    // Vergleichsoperator == für Gleichheit
    bool operator==(const Contact& other) const {
        // Überprüft, ob beide Objekte denselben Nachnamen und Vornamen haben
        return  last_name == other.last_name && first_name == other.first_name;
    }

    // Vergleichsoperator != für Ungleichheit
    bool operator!=(const Contact& other) const {
        // Prüft das Gegenteil von operator==, um festzustellen, ob die Objekte ungleich sind
        return !(*this == other);
    }

    // Vergleichsoperator < für "kleiner als"
    bool operator<(const Contact& other) const {
        // Zuerst wird der Nachname verglichen
        if (last_name < other.last_name) return true;   
        if (last_name > other.last_name) return false;  
        // Wenn die Nachnamen gleich sind, wird der Vorname verglichen
        return first_name < other.first_name;
    }

    // Vergleichsoperator <= für "kleiner oder gleich"
    bool operator<=(const Contact& other) const {
        // true, wenn das Objekt entweder kleiner ist oder gleich
        return *this < other || *this == other;
    }

    // Vergleichsoperator > für "größer als"
    bool operator>(const Contact& other) const {
        // true, wenn das Objekt nicht kleiner oder gleich ist
        return !(*this <= other);
    }

    // Vergleichsoperator >= für "größer oder gleich"
    bool operator>=(const Contact& other) const {
        // true, wenn das Objekt nicht kleiner ist
        return !(*this < other);
    }
};

int main() {
    // Initialisiert drei Kontaktobjekte zur Demonstration der Vergleichsoperatoren
    const auto mycroft = Contact{"Holmes", "Mycroft"};
    const auto sherlock = Contact{"Holmes", "Sherlock"};
    const auto james = Contact{"Moriarty", "James"};

    // Vergleiche der Kontakte und Ausgabe der Ergebnisse
    std::cout << "A: " << (sherlock == sherlock) << "\n";  
    std::cout << "B: " << (sherlock != mycroft) << "\n";  
    std::cout << "C: " << (sherlock > mycroft) << "\n";     
    std::cout << "D: " << (sherlock >= mycroft) << "\n";   
    std::cout << "E: " << (sherlock <= sherlock) << "\n";   
    std::cout << "F: " << (sherlock >= sherlock) << "\n";   
    std::cout << "G: " << (sherlock < james) << "\n";       

    return 0;
}
