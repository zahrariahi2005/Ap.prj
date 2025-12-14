
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Participant {
private:
    string name;
    int id;
    vector<int> registeredEvents;

public:
    Participant() = default;
    Participant(const string &name,int id);

    int getid() const;
    const string &getName() const;
    const vector<int>&getRegisteredEvents()const;

    void addEvent(int eventID);
    bool isRegisteredTo(int eventID) const;

    friend ostream &operator<<(ostream &os, const Participant &p); 
};






