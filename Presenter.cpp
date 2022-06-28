#include "Presenter.h"
#include <QMessageBox>

using namespace std;

Presenter::Presenter(Service& _serv, QWidget *parent)
	: serv{ _serv }, QWidget(parent)
{
	ui.setupUi(this);
	this->serv.registerObserver(this);
	this->populateList();

	connect(ui.addQuestion, &QPushButton::clicked, this, &Presenter::addQuestion);
}

Presenter::~Presenter()
{
}

void Presenter::populateList() {
	this->ui.questionsList->clear();
	for (auto q : this->serv.getSortedQuestionsById()) {
		string question;
		question = to_string(q.getId()) + " | " + to_string(q.getScore()) + " | " + q.getTxt() + " | " + q.getAns();
		this->ui.questionsList->addItem(QString::fromStdString(question));
	}
}

void Presenter::update() {
	this->populateList();
}

void Presenter::addQuestion() {
	int id = 0;
	try {
		id = stoi(this->ui.questionId->text().toStdString());
	}
	catch (exception& e) {
		QMessageBox* error = new QMessageBox{};
		error->setText("Invalid question id number!");
		error->show();
		
		this->ui.questionId->clear();
		this->ui.questionTxt->clear();
		this->ui.questionAns->clear();
		return;
	}

	string txt = this->ui.questionTxt->text().toStdString();
	string ans = this->ui.questionAns->text().toStdString();

	if (txt == "" || ans == "") {
		QMessageBox* error = new QMessageBox{};
		error->setText("You need to fill al the fields!");
		error->show();

		this->ui.questionId->clear();
		this->ui.questionTxt->clear();
		this->ui.questionAns->clear();
		return;
	}

	int score = rand() % 100; 
	Question q{ id, score, txt, ans };
	bool feedback = this->serv.addQuestion(q);

	if (feedback == false) {
		QMessageBox* error = new QMessageBox{};
		error->setText("Question with this ID already exists!");
		error->show();
	}
	
	this->ui.questionId->clear();
	this->ui.questionTxt->clear();
	this->ui.questionAns->clear();
}

