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
    // Servidor *server = new Servidor();

    // std::string input;
    // std::stringstream ss;

    // std::ofstream output("bin/out.txt");
    // while (std::getline(std::cin, input)) {
    //     ss = std::stringstream();
    //     ss << input;
    //     std::string op;
    //     ss >> op;

    //     int id = -1;
    //     ss >> id;

    //     switch (resolveOption(op)) {
    //         case CADASTRA:
    //             if (server->criarCaixa(id))
    //                 output << "CONTA " << id << " CADASTRADA" << std::endl;
    //             else
    //                 output << "CONTA " << id << " JA EXISTENTE" << std::endl;
    //             break;
    //         case REMOVE:
    //             server->excluirCaixa(id);
    //             break;
    //         case ENTREGA:
    //             break;
    //         case CONSULTA:
    //             break;

    //         default:
    //             break;
    //     }

    //     // std::cout << op << std::endl;
    // }

    // CaixaDeEntrada *c = new CaixaDeEntrada;
    // std::cout << c->consultaEmail() << std::endl;
    // c->recebeEmail("galo", 8);
    // c->recebeEmail("vasco", 4);
    // c->recebeEmail("eu", 5);
    // std::cout << c->consultaEmail() << std::endl;
    // c->recebeEmail("safoa", 9);
    // std::cout << c->consultaEmail() << std::endl;
    // c->limpaCaixa();
    // std::cout << c->consultaEmail() << std::endl;

    // delete c;

    Servidor *s = new Servidor;
    // s->criarCaixa(345);
    // s->criarCaixa(32);
    // s->criarCaixa(76);

    std::cout << s->criarCaixa(345) << std::endl;
    std::cout << s->criarCaixa(63) << std::endl;
    std::cout << s->criarCaixa(990) << std::endl;
    std::cout << s->criarCaixa(345) << std::endl;

    return 0;
}
