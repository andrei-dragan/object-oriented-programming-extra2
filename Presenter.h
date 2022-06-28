#pragma once

#include <QWidget>
#include "ui_Presenter.h"
#include "Service.h"
#include "Observer.h"

class Presenter : public QWidget, public Observer
{
	Q_OBJECT

public:
	Presenter(Service& _serv, QWidget *parent = Q_NULLPTR);
	~Presenter();

private:
	Service& serv;
	Ui::Presenter ui;

public:
	void populateList();
	void addQuestion();
	void update() override;
};
