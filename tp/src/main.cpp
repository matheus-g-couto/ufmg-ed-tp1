#include "memlog.h"
#include "msgassert.h"
#include "servidor.h"
#include <fstream>
#include <getopt.h>
#include <iostream>
#include <sstream>
#include <string>

enum Options { CADASTRA, REMOVE, ENTREGA, CONSULTA, INVALIDO };

Options resolveOption(std::string input) {
    if (input == "CADASTRA")
        return CADASTRA;
    if (input == "REMOVE")
        return REMOVE;
    if (input == "ENTREGA")
        return ENTREGA;
    if (input == "CONSULTA")
        return CONSULTA;

    return INVALIDO;
}

int main(int argc, char **argv) {
    char log_name[12] = "bin/log.out";
    iniciaMemLog(log_name);
    // desativaMemLog();
    ativaMemLog();

    Servidor *server = new Servidor();

    std::string input;
    std::stringstream ss;

    int num_ops = -1;

    while (std::getline(std::cin, input)) {
        ss = std::stringstream();
        ss << input;
        std::string op;
        ss >> op;

        int id = -1;
        ss >> id;
        erroAssert(id >= 0, "Id do usuário deve ser um número positivo");
        erroAssert(id <= 1000000, "Id do usuário deve ser menor que 1 milhão");

        std::string email_msg = "", email_word = "";
        int email_prio = 0;

        defineFaseMemLog(num_ops);
        switch (resolveOption(op)) {
            case CADASTRA:
                server->criarUsuario(id);
                break;
            case REMOVE:
                server->excluirUsuario(id);
                break;
            case ENTREGA:
                ss >> email_prio;
                while (ss >> email_word) {
                    if (!email_word.compare("FIM"))
                        break;
                    email_msg += email_word;
                    email_msg += " ";
                }
                server->enviarEmail(id, email_msg, email_prio);
                break;
            case CONSULTA:
                server->consultarEmail(id);
                break;

            case INVALIDO:
                erroAssert(false, "COMANDO DESCONHECIDO");
        }

        num_ops++;
    }

    defineFaseMemLog(num_ops);
    delete server;
    return finalizaMemLog();
}
