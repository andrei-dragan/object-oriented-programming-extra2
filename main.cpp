#include "Quiz.h"
#include "Presenter.h"
#include "ParticipantUI.h"
#include <QtWidgets/QApplication>
#include "Questions.h"
#include "Participants.h"
#include "Service.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));

    Participants p{};
    Questions q{};
    Service serv{ q, p };

    QApplication a(argc, argv);

    // The presenter 
    Presenter presenter{ serv };
    presenter.setWindowTitle("Presenter");
    presenter.show();
    
    // The participants
    int nrParticipants = serv.getParticipants().size();
    ParticipantUI** participantsUI = (ParticipantUI**)malloc(sizeof(ParticipantUI*) * nrParticipants);
    int idx = 0;
    for (auto participant : serv.getParticipants()) {
        ParticipantUI* participantUI = new ParticipantUI{serv};
        participantsUI[idx] = participantUI;
        idx++;
    }

    idx = 0;
    for (auto participant : serv.getParticipants()) {
        participantsUI[idx]->setWindowTitle(QString::fromStdString(participant.getName()));
        participantsUI[idx]->show();
        idx++;
    }

    return a.exec();


    for (int i = 0; i < nrParticipants; i++) {
        delete participantsUI[idx];
    }
    free(participantsUI);
}
