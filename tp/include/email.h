#include <string>

class Email {
  private:
    std::string msg;
    int priority;
    Email *next;

  public:
    Email();
    Email(std::string msg, int prio);
    ~Email();
    void setMessage(std::string msg);
    std::string getMessage();
    void setPrio(int prio);
    int getPrio();

    friend class CaixaDeEntrada;
};