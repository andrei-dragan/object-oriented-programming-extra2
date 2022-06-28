#include "Subject.h"

void Subject::registerObserver(Observer* ob) {
	this->observers.push_back(ob);
}

void Subject::notify() {
	for (auto obs : this->observers) {
		obs->update();
	}
}