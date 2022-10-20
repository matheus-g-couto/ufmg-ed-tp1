#ifndef SERVIDOR_H
#define SERVIDOR_H

#include "caixa_de_entrada.h"
#include "memlog.h"
#include <string>

// Cada usuário tem uma caixa de entrada e aponta para um outro usuário
struct User {
    CaixaDeEntrada *caixa;
    User *next;
};

class Servidor {
  private:
    User *head;
    User *encontrarUsuario(int id);

  public:
    Servidor();
    ~Servidor();
    void criarUsuario(int id);
    void excluirUsuario(int id);
    void limpaServidor();
    void enviarEmail(int id, std::string msg, int prio);
    void consultarEmail(int id);
};

#endif