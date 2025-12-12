
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
    Participant(int id, const string &n);

    int getid() const;
    const string &getName() const;
    const vector<int> &getRegisteredEvents() const;

    void addEvent(int eventID) {
        registeredEvents.push_back(eventID);
    }

    bool isRegisteredTo(int eventID) const {
        for (int e : registeredEvents) if (e == eventID) return true;
        return false;
    }

    friend ostream &operator<<(ostream &os, const Participant &p) {
        os << "Participant[ID=" << p.id << ", Name='" << p.name << "', Events=" << p.registeredEvents.size() << "]";
        return os;
    }
};





