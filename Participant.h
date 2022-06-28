#pragma once

#include <string>

class Participant {
private:
	std::string name;
	int score;
public:
	Participant(std::string _name, int _score) : name{ _name }, score{ _score } {};
	int getScore() { return this->score; }
	std::string getName() { return this->name; }
};