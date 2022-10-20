#include "servidor.h"
#include <iostream>

Servidor::Servidor() {
    head = new User;
    head->caixa = NULL;
    head->next = NULL;
}

Servidor::~Servidor() {
    limpaServidor();
    delete head;
}

User *Servidor::encontrarUsuario(int id) {
    User *aux = head;

    while (aux->next != NULL) {
        if (aux->caixa->getId() == id) {
            LEMEMLOG((long int)(&(aux)), sizeof(User), aux->caixa->getId());
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}

void Servidor::criarUsuario(int id) {
    if (encontrarUsuario(id) != NULL) {
        std::cout << "ERRO: CONTA " << id << " JA EXISTENTE" << std::endl;
        return;
    }

    CaixaDeEntrada *cx = new CaixaDeEntrada;
    cx->setId(id);

    User *user = new User;
    user->caixa = cx;
    user->next = head;
    ESCREVEMEMLOG((long int)(&(user)), sizeof(User), cx->getId());

    head = user;
    std::cout << "OK: CONTA " << id << " CADASTRADA" << std::endl;
}

void Servidor::excluirUsuario(int id) {
    User *user = encontrarUsuario(id);
    if (user == NULL) {
        std::cout << "ERRO: CONTA " << id << " NAO EXISTE" << std::endl;
        return;
    }

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

    std::cout << "OK: CONTA " << id << " REMOVIDA" << std::endl;
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

void Servidor::enviarEmail(int id, std::string msg, int prio) {
    User *user = encontrarUsuario(id);
    if (user == NULL) {
        std::cout << "ERRO: CONTA " << id << " NAO EXISTE" << std::endl;
        return;
    }

    user->caixa->recebeEmail(msg, prio);
    std::cout << "OK: MENSAGEM PARA " << id << " ENTREGUE" << std::endl;
}

void Servidor::consultarEmail(int id) {
    User *user = encontrarUsuario(id);
    if (user == NULL) {
        std::cout << "ERRO: CONTA " + std::to_string(id) + " NAO EXISTE"
                  << std::endl;
        return;
    }

    std::cout << "CONSULTA " << std::to_string(id) << ": "
              << user->caixa->consultaEmail() << std::endl;
}