#pragma once
#include<iostream>
using namespace std;
#include<vector>
class Participant;
class Events {
	string name;
	int id;
	string type;
	int capacity;
	vector<Participant*>Pr;
public:
    Events() = default;
	Events(string name, int id, string type, int capacity);
	string getname();
	int getid()const;
	string gettype();
	int getcapacity();
	int getParticipantCount() ;
	void addParticipant(Participant* participant);
	const vector<Participant*>& getParticipants() const;
};
