#include "caixa_de_entrada.h"

struct No {
    CaixaDeEntrada *caixa;
    No *ant;
    No *next;
    No() : caixa(new CaixaDeEntrada()), ant(NULL), next(NULL){};
};

class Servidor {
  private:
    No *head;
    No *encontrarCaixa(int id);

  public:
    Servidor();
    ~Servidor();
    void criarCaixa(int id);
    void excluirCaixa(int id);
};