#include "email.h"

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
    void recebeEmail(Email *e);
};