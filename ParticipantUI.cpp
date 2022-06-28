#include "ParticipantUI.h"
#include <sstream>

using namespace std;

ParticipantUI::ParticipantUI(Service& _serv, QWidget *parent)
	: serv{ _serv }, QWidget(parent)
{
	this->serv.registerObserver(this);
	ui.setupUi(this);
	this->ui.score->setText("0");
	this->populateList();

	connect(this->ui.questionsList, &QListWidget::itemClicked, this, &ParticipantUI::checkSelectedItem);
	connect(this->ui.answerButton, &QPushButton::clicked, this, &ParticipantUI::answerQuestion);
}

ParticipantUI::~ParticipantUI()
{
}

void ParticipantUI::populateList() {
	this->ui.questionsList->clear();
	for (auto q : this->serv.getSortedQuestionsByScore()) {
		string question;
		question = to_string(q.getId()) + " | " + to_string(q.getScore()) + " | " + q.getTxt();
		this->ui.questionsList->addItem(QString::fromStdString(question));
	}
}

void ParticipantUI::update() {
	this->populateList();
}

vector<string> tokenizeItem(string str, char delimiter) {
	string token;
	vector<string>tokens;
	stringstream ss(str);
	while (getline(ss, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

void ParticipantUI::checkSelectedItem() {
	this->ui.answerButton->setDisabled(false);
	if (this->ui.questionsList->selectedItems().size() > 0) {
		string itemString = this->ui.questionsList->selectedItems()[0]->text().toStdString();
		int selectedId = stoi(tokenizeItem(itemString, '|')[0]);	
		for (auto id : this->answeredQ) {
			if (id == selectedId) {
				this->ui.answerButton->setDisabled(true);
			}
		}
	}
}

void ParticipantUI::answerQuestion() {
	if (this->ui.questionsList->selectedItems().size() > 0) {
		string itemString = this->ui.questionsList->selectedItems()[0]->text().toStdString();
		int selectedId = stoi(tokenizeItem(itemString, '|')[0]);
		int score = stoi(tokenizeItem(itemString, '|')[1]);
		string answer = this->ui.answer->text().toStdString();
		
		if (this->serv.checkAnswer(selectedId, answer)) {
			int currentScore = stoi(this->ui.score->text().toStdString());
			currentScore += score;
			this->ui.score->setText(QString::fromStdString(to_string(currentScore)));
		}

		this->ui.questionsList->selectedItems()[0]->setBackground(QBrush(Qt::green));
		this->ui.answerButton->setDisabled(true);
		this->answeredQ.push_back(selectedId);
	}
}