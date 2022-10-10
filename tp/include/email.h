#include <string>

class Email {
  private:
    std::string msg;
    int priority;
    Email *prox;

  public:
    Email(){};
    Email(std::string m, int p) : msg(m), priority(p) {}
    std::string getMessage();
    int getPrio();

    friend class CaixaDeEntrada;
};