#include <iostream>
#include <string>

// encrypt
std::string encrypt(const std::string& input, int offset) {
    std::string result = input;
    offset = offset % 26; // Reduzieren des Offsets auf den Bereich [0, 25]
    
    for (char& c : result) {
        if (std::isalpha(c)) {
            char base = std::isupper(c) ? 'A' : 'a';
            c = static_cast<char>(base + (c - base + offset + 26) % 26);
        }
    }
    return result;
}

// decrypt
std::string decrypt(const std::string& input, int offset) {
    return encrypt(input, -offset);
}

void test(const std::string& message,
          const std::string& actual,
          const std::string& expected) {
    std::cout << message;

    if (actual == expected) {
        std::cout << "Korrekt: " << actual << "\n";
    } else {
        std::cout << "Falsch!\n"
                  << " Erwartet: " << expected << "\n"
                  << " Wert: " << actual << "\n";
    }
}

int main() {
    const auto input = std::string("Test Nachricht 1");
    const auto result_4 = encrypt(input, 4);
    test("encrypt(... , 4): ", result_4, "Xiwx Reglvmglx 1");
    test("decrypt(... , 4): ", decrypt(result_4, 4), input);

    const auto result_42 = encrypt(input, -42);
    test("encrypt(... , -42): ", result_42, "Docd Xkmrbsmrd 1");
    test("decrypt(... , -42): ", decrypt(result_42, -42), input);

    return 0;
} 
