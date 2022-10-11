#include "caixa_de_entrada.h"

CaixaDeEntrada::CaixaDeEntrada() {
    id = -1;
    email_head = new Email();
}

CaixaDeEntrada::~CaixaDeEntrada() {}

void CaixaDeEntrada::setId(int id) { this->id = id; }

int CaixaDeEntrada::getId() { return this->id; }

std::string CaixaDeEntrada::consultaEmail() {
    Email *aux;
    std::string msg;

    if (email_head->next == NULL)
        throw("Nenhum email");

    msg = email_head->next->getMessage();
    aux = email_head;
    email_head = email_head->next;
    delete aux;

    return msg;
}

void CaixaDeEntrada::recebeEmail(Email *e) {
    if (email_head->next == NULL)
        email_head->next = e;
    else {
        Email *aux = email_head;
        while (aux->next->getPrio() >= e->getPrio())
            aux = aux->next;

        e->next = aux->next;
        aux->next = e;
    }
}