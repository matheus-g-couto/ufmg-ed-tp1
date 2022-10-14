#ifndef SERVIDOR_H
#define SERVIDOR_H

#include "caixa_de_entrada.h"
#include <string>

// Cada usuário tem uma caixa de entrada e aponta para um outro usuário
struct User {
    CaixaDeEntrada *caixa;
    User *next;
};

// Implementa uma pilha de usuários, com inserção no topo e remoção de qualquer
// lugar
class Servidor {
  private:
    User *head;
    User *encontrarUsuario(int id);
    void printaCaixas();

  public:
    Servidor();
    ~Servidor();
    bool criarUsuario(int id);
    bool excluirUsuario(int id);
    void limpaServidor();
    bool enviarEmail(int id, std::string msg, int prio);
    std::string consultarEmail(int id);
};

#endif