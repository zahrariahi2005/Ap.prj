#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <string>
#include <vector>
#include <iostream>

class Participant {
private:
    std::string name;
    int participantID;
    std::vector<int> registeredEvents;

public:
    Participant() = default;
    Participant(int id, const std::string &n) : name(n), participantID(id) {}

    int getID() const { return participantID; }
    const std::string &getName() const { return name; }
    const std::vector<int> &getRegisteredEvents() const { return registeredEvents; }

    void addEvent(int eventID) {
        registeredEvents.push_back(eventID);
    }

    bool isRegisteredTo(int eventID) const {
        for (int id : registeredEvents) if (id == eventID) return true;
        return false;
    }

    friend std::ostream &operator<<(std::ostream &os, const Participant &p) {
        os << "Participant[ID=" << p.participantID << ", Name='" << p.name << "', Events=" << p.registeredEvents.size() << "]";
        return os;
    }
};

#endif // PARTICIPANT_H