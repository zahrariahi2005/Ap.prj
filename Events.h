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
	string getname()const;
	int getid()const;
	string gettype()const;
	int getcapacity()const;
	int getParticipantCount()const;
	void addParticipant(Participant* participant);
	const vector<Participant*>& getParticipants() const;
};
