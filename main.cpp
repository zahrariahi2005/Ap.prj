#include <iostream>
#include "Manager.h"
using namespace std;
int main() {
    void printAllEvents() const {
    for (const auto &e : events) {
        cout <<"Event id: "<< e.getid() <<endl;
        cout<<"Event name"<< e.getname() <<endl;
        cout<<"Event type"<< e.gettype() <<endl;
        cout<< "Participants: " << e.getParticipantCount()
             << endl;
    }
}
    void printAllParticipants() const {
    for (const auto &p : participants) {
        cout << p << endl;   
    }
}
    Manager mgr;

    mgr.addEvent(Event(1, "C++ Workshop", "Workshop", 2));
    mgr.addEvent(Event(2, "AI Seminar", "Seminar", 3));
    mgr.addEvent(Event(3, "Music Night", "Entertainment", 1));

    mgr.addParticipant(Participant(100, "Ali"));
    mgr.addParticipant(Participant(101, "Zahra"));
    mgr.addParticipant(Participant(102, "Saba"));

    try {
        mgr.registerParticipantToEvent(100, 1); 
        mgr.registerParticipantToEvent(101, 1); 

        mgr.registerParticipantToEvent(102, 1);
    } catch (const exception &ex) {
        cout << "Registration error: " << ex.what() <<endl;
    }

    try {
        mgr.registerParticipantToEvent(100, 999);
    } catch (const exception &ex) {
        cout << "Registration error: " << ex.what() <<endl;
    }

    try {
        mgr.registerParticipantToEvent(999, 2);
    } catch (const exception &ex) {
        cout << "Registration error: "<< ex.what() <<endl;
    }

    try {
        mgr.registerParticipantToEvent(102, 2); 
        mgr.registerParticipantToEvent(100, 2); 
    } catch (const exception &ex) {
        cout << "Registration error: " << ex.what() <<endl;
    }

    cout << "All events (unsorted):"<<endl;
    mgr.printAllEvents();

    cout << "Events sorted by type:"<<endl;
    auto byType = mgr.listEventsSortedByType();
    for (const auto &e : byType) cout << e <<endl;

    cout << "Events sorted by participant count (descending)"<<endl;
    auto byCount = mgr.listEventsSortedByParticipantCount();
    for (const auto &e : byCount) cout << e <<endl";

    cout << "All participants:"<<endl;
    mgr.printAllParticipants();

    return 0;

}
