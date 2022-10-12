#include "servidor.h"
#include <iostream>

Servidor::Servidor() {
    head = new User;
    head->caixa = NULL;
    head->next = NULL;
}

Servidor::~Servidor() {}

User *Servidor::encontrarCaixa(int id) {
    User *aux = head;

    while (aux->next != NULL) {
        if (aux->caixa->getId() == id)
            return aux;
        aux = aux->next;
    }
    return NULL;
}

void Servidor::printaCaixas() {}

bool Servidor::criarCaixa(int id) {
    if (encontrarCaixa(id) != NULL)
        return false;

    CaixaDeEntrada *cx = new CaixaDeEntrada;
    cx->setId(id);

    User *user = new User;
    user->caixa = cx;
    user->next = head;

    head = user;
    return true;
}

bool Servidor::excluirCaixa(int id) {}

void Servidor::limpaServidor() {}