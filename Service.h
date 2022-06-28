#pragma once
#include "Questions.h"
#include "Participants.h"
#include "Subject.h"

class Service : public Subject  {
private:
	Questions& q;
	Participants& p;
public:
	Service(Questions& _q, Participants& _p) : q{ _q }, p{ _p } {};
	bool addQuestion(Question q);
	std::vector<Question>getSortedQuestionsById();
	std::vector<Question>getSortedQuestionsByScore();
	std::vector<Participant>getParticipants();

	bool checkAnswer(int id, std::string ans);
};