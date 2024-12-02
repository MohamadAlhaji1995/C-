#include <iostream>
#include <utility>
#include <map>
#include <unordered_map>
//repräsentiert den Namen eines Fachs
using Subject = std::string;
//repräsentiert eine Uhrzeit oder einen Zeitabschnitt.
using Time = std::string;
//repräsentiert den Namen eines Raums.
using Room = std::string;

using Class_schedule = std::unordered_map<Subject, std::unordered_map<Time, Room>>;
using Room_schedule = std::map<Room, std::map<Time, Subject>>;

Room_schedule to_room_schedule(const Class_schedule& class_schedule) {
    Room_schedule room_schedule;

    for (const auto& [subject, timeslots] : class_schedule) {
        for (const auto& [time, room] : timeslots) {
            room_schedule[room][time] = subject;
        }
    }
//rs[room][time] = Subject;
    return room_schedule;
}

int main() {
    const auto class_schedule = Class_schedule{
        {"C/C++", {
            {"Mo. 20:00", "3B"},
            {"Fr. 14:00", "L402"}
        }},
        {"Java", {
            {"Di. 06:15", "HS1"},
            {"Di. 08:00", "HS1"}
        }},
        {"The Mathematics of Quantum Neutrino Fields", {
            {"Mo. 17:30", "3B"}
        }}
    };

    const auto room_schedule = to_room_schedule(class_schedule);

    for (auto&& [room, timeslots] : room_schedule) {
        std::cout << room << ":\n";
        for (auto&& [time, subject] : timeslots) {
            std::cout << "\t" << time << " " << subject << "\n";
        }
    }
    return 0;
}
