#include "Service.h"

using namespace std;

vector<Question> Service::getSortedQuestionsById() {
	return this->q.getSortedQuestionsById();
}

vector<Question> Service::getSortedQuestionsByScore() {
	return this->q.getSortedQuestionsByScore();
}

bool Service::addQuestion(Question q) {
	if (this->q.searchQuestion(q))
		return false;

	this->q.addQuestion(q);
	this->notify();
	return true;
}

vector<Participant> Service::getParticipants() {
	return this->p.getParticipants();
}

bool Service::checkAnswer(int id, string answer) {
	return this->q.checkAnswer(id, answer);
}