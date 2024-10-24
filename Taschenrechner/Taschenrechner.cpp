#include <iostream>

int main() {
    double num1, num2;
    char op;

    // Eingabe von Benutzer
    std::cout << "Geben Sie die erste Zahl ein: ";
    std::cin >> num1;
    std::cout << "Geben Sie die Operation (+, -, *, /) ein: ";
    std::cin >> op;
    std::cout << "Geben Sie die zweite Zahl ein: ";
    std::cin >> num2;

    std::cout << "= ";
    switch(op) {
        case '+':
            std::cout << (num1 + num2) << std::endl;
            break;
        case '-':
            std::cout << (num1 - num2) << std::endl;
            break;
        case '*':
            std::cout << (num1 * num2) << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                std::cout << (num1 / num2) << std::endl;
            } else {
                std::cout << "Fehler: Division durch Null ist nicht erlaubt." << std::endl;
            }
            break;
        default:
            std::cout << "Ungültige Operation" << std::endl;
    }

    return 0;
}
