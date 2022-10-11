#include "email.h"

Email::Email() {
    this->msg = "";
    this->priority = 0;
    this->next = NULL;
}

Email::Email(std::string msg, int prio) {
    this->msg = msg;
    this->priority = prio;
    this->next = NULL;
}

Email::~Email() {
    this->msg = "";
    this->priority = -1;
    this->next = NULL;
}

void Email::setMessage(std::string msg) { this->msg = msg; }

std::string Email::getMessage() { return this->msg; }

void Email::setPrio(int prio) { this->priority = prio; }

int Email::getPrio() { return this->priority; }