#pragma once

#include <QWidget>
#include "ui_ParticipantUI.h"
#include "Service.h"
#include "Observer.h"

class ParticipantUI : public QWidget, public Observer
{
	Q_OBJECT

public:
	ParticipantUI(Service& _serv, QWidget *parent = Q_NULLPTR);
	~ParticipantUI();

private:
	Service& serv;
	Ui::ParticipantUI ui;
	std::vector<int>answeredQ;

public:
	void populateList();
	void update() override;
	void checkSelectedItem();
	void answerQuestion();
};
