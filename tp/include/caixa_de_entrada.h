#include "email.h"

class CaixaDeEntrada {
  private:
    int id;
    Email *email_head;

  public:
    CaixaDeEntrada() : id(-1), email_head(NULL){};
    ~CaixaDeEntrada();
    void setId(int id);
    int getId();
    std::string consultaEmail();
    void recebeEmail(Email e);

    friend class Arvore;
};