#include "Questions.h"
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

vector<string> Questions::tokenize(string str, char delimiter) {
	string token;
	vector<string>tokens;
	stringstream ss(str);
	while (getline(ss, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

Questions::Questions() {
	ifstream f("questions.txt");
	string line;
	while (getline(f, line)) {
		vector<string> tokens = this->tokenize(line, ',');
		Question q{ stoi(tokens[0]), stoi(tokens[1]), tokens[2], tokens[3] };
		this->addQuestion(q);
	}
}

void Questions::addQuestion(Question q) {
	this->questions.push_back(q);
	this->write();
}

void Questions::write() {
	ofstream g("questions.txt");
	for (auto q : this->questions) {
		g << to_string(q.getId()) << "," << to_string(q.getScore()) << "," << q.getTxt() << "," << q.getAns() << '\n';
	}
	g.close();
}

vector<Question> Questions::getSortedQuestionsById() {
	vector<Question> qs = this->questions;
	sort(qs.begin(), qs.end(), [](Question A, Question B) {
		return (A.getId() < B.getId());
		});
	return qs;
}

bool Questions::searchQuestion(Question q) {
	for (auto question : this->questions) {
		if (question.getId() == q.getId())
			return true;
	}
	return false;
}

vector<Question> Questions::getSortedQuestionsByScore() {
	vector<Question> qs = this->questions;
	sort(qs.begin(), qs.end(), [](Question A, Question B) {
		return (A.getScore() > B.getScore());
		});
	return qs;
}

bool Questions::checkAnswer(int id, string ans) {
	for (auto q : this->questions) {
		if (q.getId() == id && q.getAns() == ans)
			return true;
	}
	return false;
}