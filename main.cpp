#include <iostream>
#include "Manager.h"
using namespace std;
int main() {
    Manager mgr;

    mgr.addEvent(Event(1, "C++ Workshop", "Workshop", 2));
    mgr.addEvent(Event(2, "AI Seminar", "Seminar", 3));
    mgr.addEvent(Event(3, "Music Night", "Entertainment", 1));

    mgr.addParticipant(Participant(100, "Alice"));
    mgr.addParticipant(Participant(101, "Bob"));
    mgr.addParticipant(Participant(102, "Charlie"));

    try {
        mgr.registerParticipantToEvent(100, 1); 
        mgr.registerParticipantToEvent(101, 1); 

        mgr.registerParticipantToEvent(102, 1);
    } catch (const exception &ex) {
        cout << "Registration error: " << ex.what() << "\n";
    }

    try {
        mgr.registerParticipantToEvent(100, 999);
    } catch (const exception &ex) {
        cout << "Registration error: " << ex.what() << "\n";
    }

    try {
        mgr.registerParticipantToEvent(999, 2);
    } catch (const exception &ex) {
        cout << "Registration error: " << ex.what() << "\n";
    }

    try {
        mgr.registerParticipantToEvent(102, 2); 
        mgr.registerParticipantToEvent(100, 2); 
    } catch (const exception &ex) {
        cout << "Registration error: " << ex.what() << "\n";
    }

    cout << "\nAll events (unsorted):\n";
    mgr.printAllEvents();

    cout << "\nEvents sorted by type:\n";
    auto byType = mgr.listEventsSortedByType();
    for (const auto &e : byType) cout << e << "\n";

    cout << "\nEvents sorted by participant count (descending):\n";
    auto byCount = mgr.listEventsSortedByParticipantCount();
    for (const auto &e : byCount) cout << e << "\n";

    cout << "\nAll participants:\n";
    mgr.printAllParticipants();

    return 0;
}