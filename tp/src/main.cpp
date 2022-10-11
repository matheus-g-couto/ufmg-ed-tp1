#include "caixa_de_entrada.h"
#include "memlog.h"
#include "msgassert.h"
#include <getopt.h>
#include <iostream>
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

struct ListaCaixas {
    CaixaDeEntrada caixa;
    CaixaDeEntrada *prox;
};

struct Servidor {
    ListaCaixas l;
};

int main(int argc, char **argv) { return 0; }
