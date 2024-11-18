#include <iostream>
#include <array>
#include <sstream>

struct Sudoku {
    std::array<std::array<int, 9>, 9> field = {};
};

std::ostream& operator<<(std::ostream& out, const Sudoku& s) {
    for (int y = 0; y < 9; y++) {
        if (y % 3 == 0 && y > 0) {
            out << "----------------------\n";
        }
        for (int x = 0; x < 9; x++) {
            if (x % 3 == 0 && x > 0) {
                out << " |";
            }
            out << " " << s.field[x][y];
        }
        out << "\n";
    }
    return out;
}

std::istream& operator>>(std::istream& in, Sudoku& s) {
    auto ignore = std::string();
    for (int y = 0; y < 9; y++) {
        if (y % 3 == 0 && y > 0) {
            in >> ignore;
        }
        for (int x = 0; x < 9; x++) {
            if (x % 3 == 0 && x > 0) {
                in >> ignore;
            }
            in >> s.field[x][y];
        }
    }
    return in;
}

// Prüft, ob die Zahl an Position (x, y) gesetzt werden kann
bool valid_move(const Sudoku& sudoku, int x, int y, int number) {
    // Zeile prüfen
    for (int i = 0; i < 9; i++) {
        if (sudoku.field[i][y] == number) {
            return false;
        }
    }

    // Spalte prüfen
    for (int i = 0; i < 9; i++) {
        if (sudoku.field[x][i] == number) {
            return false;
        }
    }

    // 3x3 Block prüfen
    int start_x = (x / 3) * 3;
    int start_y = (y / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku.field[start_x + i][start_y + j] == number) {
                return false;
            }
        }
    }

    return true;
}

// Rekursive Lösung des Sudoku-Problems
bool solve(Sudoku& sudoku) {
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            if (sudoku.field[x][y] == 0) {  // Freies Feld gefunden
                for (int number = 1; number <= 9; number++) {
                    if (valid_move(sudoku, x, y, number)) {
                        sudoku.field[x][y] = number;
                        if (solve(sudoku)) {
                            return true;  // Lösung gefunden
                        }
                        sudoku.field[x][y] = 0;  // Zurücksetzen
                    }
                }
                return false;  // Keine Zahl passt
            }
        }
    }
    std::cout << sudoku;  // Lösung ausgeben
    return true;
}

int main() {
    auto sudoku = Sudoku{};

    std::cin >> sudoku;
    std::cout << sudoku << "\n";

    if (!solve(sudoku)) {
        std::cout << "Keine Loesung gefunden\n";
    }
}
