#include "Participant.h"
using namespace std;
#unclude<vector>
Participant::Participant() : id(0) {}
Participant::Participant(const string&name, int id) : name(name), id(id) {}

string Participant::getName() const {
    return name;
}

int Participant::getid() const {
    return id;
}
void Participant::addevent(int eventID) {
    registeredEvents.push_back(eventID);
}

const vector<int>& Participant::getRegisteredEvents() const {
    return registeredEvents;

}

bool Participant::isRegisteredTo(int eventID) const {
    for (int e : registeredEvents) {
        if (e == eventID)
            return true;
    }
    return false;
}
ostream& operator<<(ostream& os, const Participant& p) { os << "Participant[ID=" << p.id << ", Name='" << p.name << "', Events=" << p.registeredEvents.size() << "]"; return os; }
