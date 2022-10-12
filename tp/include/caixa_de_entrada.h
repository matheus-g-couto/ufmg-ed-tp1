#ifndef CAIXA_DE_ENTRADA_H
#define CAIXA_DE_ENTRADA_H

#include "email.h"
#include <string>

class CaixaDeEntrada {
  private:
    int id;
    Email *email_head;

  public:
    CaixaDeEntrada();
    ~CaixaDeEntrada();
    void setId(int id);
    int getId();
    std::string consultaEmail();
    void recebeEmail(std::string msg, int prio);
    void limpaCaixa();
};

#endif