#pragma once
#include "Question.h"
#include <vector>
#include <string>

class Questions {
private:
	std::vector<Question> questions;
public:
	Questions();

	std::vector<std::string> tokenize(std::string str, char delimiter);
	void addQuestion(Question q);
	void write();

	std::vector<Question>getSortedQuestionsById();
	std::vector<Question>getSortedQuestionsByScore();
	bool searchQuestion(Question q); 
	bool checkAnswer(int id, std::string ans);
};