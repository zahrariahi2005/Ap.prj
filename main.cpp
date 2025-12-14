#include <iostream>
#include "Manager.h"
using namespace std;
int main() {
    Manager mgr;

    mgr.addEvent(Events("C++ Workshop",1,"Workshop",20));
    mgr.addEvent(Events("AI Seminar",2,"Seminar",30));
    mgr.addEvent(Events("Music Night",3,"Entertainment",100));

   mgr.addParticipant(Participant("Ali",100));
   mgr.addParticipant(Participant("Zahra",101));
   mgr.addParticipant(Participant("Saba",102));

    try {
        mgr.registerParticipantToEvent(100, 3); 
        mgr.registerParticipantToEvent(101, 2); 
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
    
    cout << "All participants:"<<endl;
    mgr.printAllParticipants();
    
    cout << "Events sorted by type:"<<endl;
    mgr.listEventsSortedByType();

    cout << "Events sorted by participant count (descending)"<<endl;
    mgr.listEventsSortedByParticipantCount();
    
    return 0;

}


