#include "caixa_de_entrada.h"

// struct Arvore {
//     CaixaDeEntrada *caixa;
//     Arvore *esquerda;
//     Arvore *direita;
//     Arvore(int id)
//         : caixa(new CaixaDeEntrada(id)), esquerda(NULL), direita(NULL) {}
// };

struct No {
    CaixaDeEntrada *caixa;
    No *left;
    No *right;
    No() : caixa(NULL), left(NULL), right(NULL) {}
};

class Arvore {
  private:
    No *raiz;
    void insereCaixaNaArvore(No *&no, int id);
    CaixaDeEntrada *buscaCaixaRecursivo(No *&no, int id);
    void removeCaixaDaArvore(No *&no, int id);

  public:
    Arvore();
    ~Arvore();
    void criarCaixaDeEntrada(int id);
    CaixaDeEntrada *buscaCaixaDeEntrada(int id);
    void removeCaixaDeEntrada(int id);
};