#include "servidor.h"
#include <iostream>

Servidor::Servidor() {
    head = new User;
    head->caixa = NULL;
    head->next = NULL;
}

Servidor::~Servidor() {}

User *Servidor::encontrarUsuario(int id) {
    User *aux = head;

    while (aux->next != NULL) {
        if (aux->caixa->getId() == id)
            return aux;
        aux = aux->next;
    }
    return NULL;
}

void Servidor::printaCaixas() {
    User *aux = head;
    while (aux->next != NULL) {
        std::cout << aux->caixa->getId() << " ";
        aux = aux->next;
    }

    std::cout << std::endl;
}

bool Servidor::criarUsuario(int id) {
    if (encontrarUsuario(id) != NULL)
        return false;

    CaixaDeEntrada *cx = new CaixaDeEntrada;
    cx->setId(id);

    User *user = new User;
    user->caixa = cx;
    user->next = head;

    head = user;
    return true;
}

bool Servidor::excluirUsuario(int id) {
    User *user = encontrarUsuario(id);
    if (user == NULL)
        return false;

    User *aux = head;
    if (head == user) {
        head = head->next;
    } else {
        while (aux->next != NULL && aux->next != user)
            aux = aux->next;

        aux->next = user->next;
    }
    delete user->caixa;
    delete user;

    return true;
}

void Servidor::limpaServidor() {
    User *aux;
    while (head->next) {
        aux = head;
        head = head->next;
        delete aux->caixa;
        delete aux;
    }
}

bool Servidor::enviarEmail(int id, std::string msg, int prio) {
    User *user = encontrarUsuario(id);
    if (user == NULL)
        return false;

    user->caixa->recebeEmail(msg, prio);
    return true;
}

std::string Servidor::consultarEmail(int id) {
    User *user = encontrarUsuario(id);
    if (user == NULL)
        return "ERRO: CONTA " + std::to_string(id) + " NAO EXISTE";

    return "CONSULTA " + std::to_string(id) + ": " +
           user->caixa->consultaEmail();
}