#pragma once
#include <string>

class Question {
private:
	int id, score;
	std::string txt, ans;
public:
	Question(int _id, int _score, std::string _txt, std::string _ans) : id{ _id }, score{ _score }, txt{ _txt }, ans{ _ans } {};
	int getId() { return this->id; }
	int getScore() { return this->score; }
	std::string getTxt() { return this->txt; }
	std::string getAns() { return this->ans; }
};