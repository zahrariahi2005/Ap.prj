#include "Participant.h"
using namespace std;
// Constructor
Participant::Participant(string n, int i) {
    name = n;
    id = i;
}

// Getters
string Participant::getName() const {
    return name;
}

int Participant::getID() const {
    return id;
}

// Add event
void Participant::addEvent(int eventID) {
    registeredEvents.push_back(eventID);
}

// Get all registered events
const vector<int>& Participant::getRegisteredEvents() const {
    return registeredEvents;
}