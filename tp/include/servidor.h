#ifndef SERVIDOR_H
#define SERVIDOR_H

#include "caixa_de_entrada.h"

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
    User *encontrarCaixa(int id);
    void printaCaixas();

  public:
    Servidor();
    ~Servidor();
    bool criarCaixa(int id);
    bool excluirCaixa(int id);
    void limpaServidor();
};

#endif