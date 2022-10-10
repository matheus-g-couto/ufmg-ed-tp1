#include "arvore.h"

Arvore::Arvore() { this->raiz = NULL; }

Arvore::~Arvore() {}

void Arvore::insereCaixaNaArvore(No *&no, int id) {
    if (no == NULL) {
        no = new No();
        no->caixa = new CaixaDeEntrada();
        no->caixa->setId(id);
    } else {
        if (no->caixa->getId() > id)
            insereCaixaNaArvore(no->left, id);
        else if (no->caixa->getId() < id)
            insereCaixaNaArvore(no->right, id);
        else
            // lançar erro se id ja existir
            int x = 1;
    }
}

void Arvore::criarCaixaDeEntrada(int id) { insereCaixaNaArvore(raiz, id); }

CaixaDeEntrada *Arvore::buscaCaixaRecursivo(No *&no, int id) {
    if (no == NULL)
        return NULL;

    if (no->caixa->getId() > id)
        return buscaCaixaRecursivo(no->left, id);
    else if (no->caixa->getId() < id)
        return buscaCaixaRecursivo(no->right, id);

    return no->caixa;
}

CaixaDeEntrada *Arvore::buscaCaixaDeEntrada(int id) {
    return buscaCaixaRecursivo(raiz, id);
}

void Arvore::removeCaixaDaArvore(No *&no, int id) {
    // CaixaDeEntrada *toRemove = buscaCaixaDeEntrada(id);
    // if(toRemove == NULL)
    //     // lancar erro
    //     int y =32;
    // else {
    //     CaixaDeEntrada aux = *toRemove;

    // }
}

void Arvore::removeCaixaDeEntrada(int id) { removeCaixaDaArvore(raiz, id); }
