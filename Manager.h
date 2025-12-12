#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include"Events.h"

class Manager {
	vector<Events> events;        
	vector<Participant> participants;
public:
     void printAllEvents() const;
    void printAllParticipants() const;
	void addEvent(const Events& event);
	void addParticipant(const Participant& participant);
	Events* findEvent(int eventID);
	Participant* findParticipant(int participantID);
	void registerParticipantToEvent(int participantID, int eventID);
	void listEventsSortedByType() const;
	void listEventsSortedByParticipantCount() const;

};
