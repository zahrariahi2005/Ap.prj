
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Participant {
private:
    string name;
    int i;
    vector<int> registeredEvents;

public:
    Participant() = default;
    Participant(int id, const string &n) : name(n), id(id) {}

    int getid() const { return participantID; }
    const string &getName() const { return name; }
    const vector<int> &getRegisteredEvents() const { return registeredEvents; }

    void addEvent(int eventID) {
        registeredEvents.push_back(eventID);
    }

    bool isRegisteredTo(int eventID) const {
        for (int e : registeredEvents) if (e == eventID) return true;
        return false;
    }

    friend ostream &operator<<(ostream &os, const Participant &p) {
        os << "Participant[ID=" << p.participantID << ", Name='" << p.name << "', Events=" << p.registeredEvents.size() << "]";
        return os;
    }
};



