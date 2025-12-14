#include<iostream>
using namespace std;
#include"Events.h"

Events::Events(string n, int i, string t, int c)
{
	name = n;
	id = i;
	type = t;
	capacity = c;
}
string Events::getname()const{
	return name;
}
int Events::getid()const{
	return id;
}
string Events::gettype()const{
	return type;
}
int Events::getcapacity()const{
	return capacity;
}
int Events::getParticipantCount()const{
	return Pr.size();
}
void Events::addParticipant(Participant* participant) {
	if (Pr.size() > capacity) {
		throw std::runtime_error("Event capacity full.");
    }
	Pr.push_back(participant);
}
const std::vector<Participant*>& Events::getParticipants() const {
	return Pr;
}

