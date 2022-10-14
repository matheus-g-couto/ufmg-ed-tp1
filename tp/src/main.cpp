#include "caixa_de_entrada.h"
#include "email.h"
#include "memlog.h"
#include "msgassert.h"
#include "servidor.h"
#include <fstream>
#include <getopt.h>
#include <iostream>
#include <sstream>
#include <string>

/* struct Flags {
    std::string input_file;
    std::string output_file;
    char log_file[100];
    bool regmem;

    Flags()
        : input_file("assets/in/mineirao.ppm"),
          output_file("assets/out/output.pgm"), log_file("bin/log.out"),
          regmem(false) {}
};
*/

/* void parse_args(int argc, char **argv, Flags *f) {
    int opt;
    bool has_in = false, has_out = false, has_log = false;
    while ((opt = getopt(argc, argv, "i:o:p:l")) != -1) {
        switch (opt) {
        case 'i':
            has_in = true;
            f->input_file = optarg;
            break;
        case 'o':
            has_out = true;
            f->output_file = optarg;
            break;
        case 'p':
            has_log = true;
            strcpy(f->log_file, optarg);
            break;
        case 'l':
            f->regmem = true;
            break;
        case '?':
            erroAssert(false, "Opcao de linha de comando invalida");
            break;
        }
    }

    avisoAssert(has_in, "Usando o arquivo .ppm padrao: assets/in/mineirao.ppm");
    avisoAssert(has_out, "Usando o arquivo .pgm padrao: assets/out/output.pgm");
    avisoAssert(has_log, "Usando o arquivo de log padrao: bin/log.out");
}
*/

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
    Servidor *server = new Servidor();

    std::string input;
    std::stringstream ss;

    while (std::getline(std::cin, input)) {
        ss = std::stringstream();
        ss << input;
        std::string op;
        ss >> op;

        int id = -1;
        ss >> id;

        std::string email_msg = "", email_word = "";
        int email_prio = 0;

        switch (resolveOption(op)) {
            case CADASTRA:
                if (server->criarUsuario(id))
                    std::cout << "OK: CONTA " << id << " CADASTRADA"
                              << std::endl;
                else
                    std::cout << "ERRO: CONTA " << id << " JA EXISTENTE"
                              << std::endl;
                break;
            case REMOVE:
                if (server->excluirUsuario(id))
                    std::cout << "OK: CONTA " << id << " REMOVIDA" << std::endl;
                else
                    std::cout << "ERRO: CONTA " << id << " NAO EXISTE"
                              << std::endl;
                break;
            case ENTREGA:
                ss >> email_prio;
                while (ss >> email_word) {
                    if (!email_word.compare("FIM"))
                        break;
                    email_msg += email_word;
                    email_msg += " ";
                }
                if (server->enviarEmail(id, email_msg, email_prio))
                    std::cout << "OK: MENSAGEM PARA " << id << " ENTREGUE"
                              << std::endl;
                else
                    std::cout << "ERRO: CONTA " << id << " NAO EXISTE"
                              << std::endl;
                break;
            case CONSULTA:
                std::cout << server->consultarEmail(id) << std::endl;
                break;

            default:
                break;
        }
    }

    delete server;
    return 0;
}
