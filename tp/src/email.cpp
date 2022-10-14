#include "email.h"

int handlePriorityRange(int prio) {
    if (prio < 0)
        return 0;
    if (prio > 9)
        return 9;

    return prio;
}

Email::Email() {
    this->msg = "";
    this->priority = 0;
    this->next = NULL;
}

Email::Email(std::string msg, int prio) {
    this->msg = msg;
    this->priority = handlePriorityRange(prio);
    this->next = NULL;
}

Email::~Email() {
    this->msg = "";
    this->priority = -1;
    this->next = NULL;
}

void Email::setMessage(std::string msg) { this->msg = msg; }

std::string Email::getMessage() { return this->msg; }

void Email::setPrio(int prio) { this->priority = handlePriorityRange(prio); }

int Email::getPrio() { return this->priority; }