#include <iostream>
#include <string>

class Customer {


public:
    // Konstruktor: Erstellt ein Customer-Objekt mit Vorname und Nachname
    Customer(const std::string& first_name, const std::string& last_name)
        : first_name_(first_name), last_name_(last_name) {}

    // Getter für den Vornamen
    std::string first_name() const {
        // `const` macht die Methode lesend, sie verändert keine Membervariablen
        return first_name_;
    }

    // Getter für den Nachnamen
    std::string last_name() const {
        // `const` ist sinnvoll, da die Methode nur den Nachnamen zurückgibt und keine Änderungen vornimmt
        return last_name_;
    }

    // Getter für den Kontostand
    int account_balance() const {
        // `const` ist sinnvoll, da die Methode nur den Kontostand zurückgibt, ohne ihn zu verändern
        return account_balance_;
    }

    // Methode zum Einzahlen eines Betrags auf das Konto
    void deposit(int amount) {
        account_balance_ += amount;
    }

    // Methode zum Abheben eines Betrags vom Konto
    void withdraw(int amount) {
        account_balance_ -= amount;
    }

    // Methode zum Ausgeben der Kundendaten und des Kontostands
    void print() const {
        std::cout << last_name_ << ", " << first_name_ << "\n";
        std::cout << "Balance: " << account_balance_ << "\n";
    }
    private:
    std::string first_name_;       // Vorname des Kunden
    std::string last_name_;        // Nachname des Kunden
    int account_balance_ = 0;      // Kontostand, initialisiert mit 0
};

int main() {
    auto customer = Customer{"John", "Dow"};
    customer.deposit(15);
    customer.withdraw(5);
    customer.print();

    customer = Customer{"Jon", "Dow"};
    customer.withdraw(5);
    customer.print();

    return 0;
}
