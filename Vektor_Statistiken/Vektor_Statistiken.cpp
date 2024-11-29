#include <iostream>
#include <vector>
#include <limits>
#include <numeric>

// Enum für die Wertebereiche
enum class Number_range {
    positive,
    negative,
    mixed
};

// Struct für die Statistiken
struct Statistics {
    float min;
    float max;
    float avg;
    Number_range range;
};

// Funktion zur Berechnung der Statistiken
Statistics statistics(const std::vector<float>& data) {
    if (data.empty()) {
        throw std::invalid_argument("Vector is empty");
    }//Liefert den größten darstellbaren Wert des Typs float (z. B. 3.40282e+38 für float).
    float min = std::numeric_limits<float>::max();
    //Liefert den kleinsten darstellbaren Wert des Typs float, d. h. den negativsten Wert (z. B. -3.40282e+38 für float).
    float max = std::numeric_limits<float>::lowest();
    float sum = 0.0f;
    bool has_positive = false;
    bool has_negative = false;

    for (float value : data) {
        if (value < min) min = value;
        if (value > max) max = value;
        sum += value;
        
        if (value >= 0) has_positive = true;
        if (value < 0) has_negative = true;
    }

    Number_range range;
    if (has_positive && has_negative) {
        range = Number_range::mixed;
    } else if (has_positive) {
        range = Number_range::positive;
    } else {
        range = Number_range::negative;
    }

    float avg = sum / data.size();
    return {min, max, avg, range};
}

int main() {
    const auto data = std::vector<float>{-20.f, 14.1f, 9.f, 9.f, 200.f};
    const auto stats = statistics(data);

    std::cout << "min : " << stats.min << "\n"
              << "max : " << stats.max << "\n"
              << "avg : " << stats.avg << "\n"
              << "range : ";

    switch (stats.range) {
        case Number_range::positive:
            std::cout << "positive\n";
            break;
        case Number_range::negative:
            std::cout << "negative\n";
            break;
        case Number_range::mixed:
            std::cout << "mixed\n";
            break;
    }

    return 0;
}
