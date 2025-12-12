#include "Participant.h"
using namespace std;
Participant::Participant(string n, int i) {
    name = n;
    id = i;
}

string Participant::getName() const {
    return name;
}

int Participant::getid() const {
    return id;
}

void Participant::addEvent(int eventID) {
    registeredEvents.push_back(eventID);
}

const vector<int>& Participant::getRegisteredEvents() const {
    return registeredEvents;

}

