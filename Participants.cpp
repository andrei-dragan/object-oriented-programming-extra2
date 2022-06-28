#include "Participants.h"
#include <fstream>
#include <sstream>

using namespace std;

vector<string> Participants::tokenize(string str, char delimiter) {
	string token;
	vector<string>tokens;
	stringstream ss(str);
	while (getline(ss, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

Participants::Participants() {
	ifstream f("participants.txt");
	string line;
	while (getline(f, line)) {
		vector<string> tokens = this->tokenize(line, ',');
		Participant p{ tokens[0], stoi(tokens[1])};
		this->participants.push_back(p);
	}
}