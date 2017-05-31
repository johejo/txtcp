#include "defs.h"

int main(int argc, char *argv[]) {
    int opt = 0;
    char *buf = NULL;
    int optr = 0;
    int opti = 0;

    opterr = 0;

    while ((opt = getopt(argc, argv, "hir")) != -1) {

        switch (opt) {
            case 'h':
                print_help();
                break;

            case 'i':
                opti = 1;
                break;

            case 'r':
                optr = 1;
                break;

            default: /* '?' */
                print_help();
                break;
        }
    }

    buf = fileopen(argv[argc - 2], optr);
    if (buf == NULL) {
        perror("open error");
        exit(1);
    }
    if (write_file(argv[argc - 1], buf, opti) == ERROR){
        perror("write error");
        exit(1);
    }



    return 0;
}