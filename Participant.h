
#include <string>
#include <vector>
#include <iostream>
#include"Events.h"
using namespace std;
class Participant {
private:
    string name;
    int id;
    vector<int> registeredEvents;
    vector<Events*>event;
public:
    Participant() = default;
    Participant(const string &name,int id);

    int getid() const;
    const string &getName() const;
    const vector<int>&getRegisteredEvents()const;

    void addevent(Events*e);
    bool isRegisteredTo(int eventID) const;

    friend ostream &operator<<(ostream &os, const Participant &p); 
};








