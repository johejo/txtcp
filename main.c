#include "defs.h"

int main(int argc, char *argv[]) {
    int opt = 0;
    char *buf = NULL;
    int optcheck = 0;

    opterr = 0; //getopt()のエラーメッセージを無効にする。

    while ((opt = getopt(argc, argv, "hi:r:")) != -1) {
        //コマンドライン引数のオプションがなくなるまで繰り返す

        switch (opt) {
            case 'h':
                optcheck = 1;
                print_help();
                break;

            case 'i':
                buf = fileopen(optarg, opt);
                write_file(argv[optind], buf);
                break;

            case 'r':
                optcheck = 1;
                buf = fileopen(optarg, opt);
                write_file(argv[optind], buf);
                break;

            default: /* '?' */
                //指定していないオプションが渡された場合
                print_help();
                break;
        }
    }

    return 0;
}