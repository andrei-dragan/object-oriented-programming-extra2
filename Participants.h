#pragma once
#include "Participant.h"
#include <vector>

class Participants {
private:
	std::vector<Participant>participants;
public:
	Participants();
	std::vector<std::string> tokenize(std::string str, char delimiter);
	std::vector<Participant>getParticipants() { return this->participants; }
};