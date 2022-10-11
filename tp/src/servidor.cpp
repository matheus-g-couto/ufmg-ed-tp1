#include "servidor.h"

Servidor::Servidor() { head = new No(); }

Servidor::~Servidor() {}

No *Servidor::encontrarCaixa(int id) {
    No *aux = head;
    while (aux->next != NULL) {
        aux = aux->next;
        if (aux->caixa->getId() == id)
            return aux;
    }

    return NULL;
}

void Servidor::criarCaixa(int id) {
    if (encontrarCaixa(id) != NULL)
        throw("Caixa já existe");
    else {
        No *novo = new No();
        novo->caixa = new CaixaDeEntrada();
        novo->caixa->setId(id);

        head->ant = novo;
        novo->next = head;
        head = novo;
    }
}

void Servidor::excluirCaixa(int id) {
    No *item = encontrarCaixa(id);
    if (item == NULL)
        throw("Caixa não existe");
    else {
        No *aux = item;
        item->next->ant = aux->ant;
        item->ant->next = aux->next;
        delete item->caixa;
        delete item;
    }
}