#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

struct Log_entry {
    std::int64_t timestamp;
    std::string source;
    std::string message;
};

// Entfernt alle Einträge mit Zeitstempeln kleiner als `timestamp`
void remove_old_entries(std::vector<Log_entry>& logs, std::int64_t timestamp) {
    logs.erase(
        std::remove_if(
            logs.begin(), logs.end(),
            [timestamp](const Log_entry& entry) {
                return entry.timestamp < timestamp;
            }),
        logs.end());
}

// Gibt die Anzahl der Einträge zurück, deren `source` == "SYSTEM"
std::size_t count_system_entries(const std::vector<Log_entry>& logs) {
    return std::count_if(
        logs.begin(), logs.end(),
        [](const Log_entry& entry) {
            return entry.source == "SYSTEM";
        });
}

// Prüft, ob mindestens ein Eintrag `message` enthält, der den String `keyword` beinhaltet
bool contains(const std::vector<Log_entry>& logs, const std::string& keyword) {
    return std::any_of(
        logs.begin(), logs.end(),
        [&keyword](const Log_entry& entry) {
            return entry.message.find(keyword) != std::string::npos;
        });
}

int main() {
    auto logs = std::vector<Log_entry>{
        {1, "SYSTEM", "System startet"},
        {2, "APP", "Received request"},
        {3, "UI", "Button pressed"},
        {3, "SYSTEM", "Please do not press this button again"},
        {6, "SYSTEM", "Terminated"}
    };

    std::cout << "System? : " << count_system_entries(logs) << "\n";
    std::cout << "Requests? : " << contains(logs, "request") << "\n";

    remove_old_entries(logs, 3);
    std::cout << "Requests? : " << contains(logs, "request") << "\n\n";

    for (const auto& entry : logs) {
        std::cout << entry.timestamp << " [" << entry.source << "] "
                  << entry.message << "\n";
    }

    return 0;
}
