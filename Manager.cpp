#include<iostream>
using namespace std;
#include"Manager.h"
#include"Events.h"
#include"Participant"
void Manager::addEvent(const Events& event) {
	for(const Events& e:events)
		if(e.getid()==event.getid())
			throw std::runtime_error("Event ID already exists.");
	events.push_back(event);
}
void Manager::addParticipant(const Participant& participant) {
	for(const Participant& p: participants)
		if(p.getid()== participant.getid())
			throw runtime_error("participant ID already exists.");
	participants.push_back(participant);
}
Events* Manager::findEvent(int eventID) {
	for (auto& e : events)
		if (e.getid() == eventID)
			return &e;
	return nullptr;
}
Participant* Manager::findParticipant(int participantID) {
	for (auto& p : participants)
		if (p.getid() == participantID)
			return& p;
	return nullptr;
}
void Manager::registerParticipantToEvent(int participantID, int eventID) {
	Participant* p = findParticipant(participantID);
	if (!p)
		throw runtime_error("participent not found");
	Events* e = findEvent(eventID);
	if (!e)
		throw runtime_error("event not found");

	if (e->getParticipantCount() >= e->getcapacity())
		throw runtime_error("event's capacity is full");

	e->addParticipant(p);
	p->registerEvent();
}
void Manager::listEventsSortedByType()const {
	std::vector<Events> sorted = events;
	for (int i = 0; i < sorted.size(); i++) {
		for (int j = i + 1; j < sorted.size(); j++) {
			if (sorted[j].gettype() > sorted[i].gettype()) {
				swap(sorted[i], sorted[j]);
			}
		}
	}

	for (auto& e : sorted) {
		cout << e.getid() << "-" << e.getname() << "-" << e.gettype() << "-" << endl;
	}
 }
void Manager::listEventsSortedByParticipantCount()const {
	std::vector<Events> sorted = events;
	for (int i = 0; i < sorted.size(); i++) {
		for (int j = i + 1; j < sorted.size(); j++) {
			if (sorted[j].getParticipantCount() > sorted[i].getParticipantCount()) {
				swap(sorted[i], sorted[j]);
			}
		}
	}

	for (auto& e : sorted) {
		cout << e.getid() << "-" << e.getname() << "-" << e.gettype() << "-" << "Participants: " << e.getParticipantCount() << endl;
	}
}
 void Manager::printAllEvents() const {
    for (const auto &e : events) {
        cout <<"Event id: "<< e.getid() <<endl;
        cout<<"Event name: "<< e.getname() <<endl;
        cout<<"Event type: "<< e.gettype() <<endl;
        cout<< "Participants: " << e.getParticipantCount()
             << endl;
    }
}
    void Manager::printAllParticipants() const {
    for (const auto &p : participants) {
        cout << p << endl;   
    }
	}


