#include "caixa_de_entrada.h"

CaixaDeEntrada::CaixaDeEntrada() {
    id = -1;
    email_head = new Email;
}

CaixaDeEntrada::~CaixaDeEntrada() {
    limpaCaixa();
    id = -1;
    delete email_head;
}

void CaixaDeEntrada::setId(int id) {
    this->id = id;

    ESCREVEMEMLOG((long int)(&(this->id)), sizeof(int), this->id);
}

int CaixaDeEntrada::getId() {
    LEMEMLOG((long int)(&(this->id)), sizeof(int), this->id);
    return this->id;
}

std::string CaixaDeEntrada::consultaEmail() {
    if (email_head->next == NULL)
        return "CAIXA DE ENTRADA VAZIA";

    Email *aux = email_head->next;
    std::string msg = aux->getMessage();

    LEMEMLOG((long int)(&(aux->msg)), sizeof(std::string), this->id);
    email_head->next = aux->next;
    delete aux;

    return msg;
}

void CaixaDeEntrada::recebeEmail(std::string msg, int prio) {
    Email *incoming = new Email(msg, prio);
    ESCREVEMEMLOG((long int)(&(incoming->msg)), sizeof(std::string), this->id);
    ESCREVEMEMLOG((long int)(&(incoming->priority)), sizeof(int), this->id);

    if (email_head->next == NULL)
        email_head->next = incoming;
    else {
        Email *aux = email_head;
        while (aux->next != NULL && aux->next->priority >= prio)
            aux = aux->next;

        incoming->next = aux->next;
        aux->next = incoming;
    }
}

void CaixaDeEntrada::limpaCaixa() {
    Email *aux = email_head->next;
    while (aux != NULL) {
        email_head->next = aux->next;
        delete aux;
        aux = email_head->next;
    }
}