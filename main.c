#include "defs.h"

int main(int argc, char *argv[]) {
    int i, opt;

    opterr = 0; //getopt()のエラーメッセージを無効にする。

    while ((opt = getopt(argc, argv, "hi:r:")) != -1) {
        //コマンドライン引数のオプションがなくなるまで繰り返す
        switch (opt) {
            case 'h':
                print_help();
                break;

            case 'i':
//                printf("-iがオプションとして渡されました%s\n", optarg);
                fileopen(optarg, opt);
                break;

            case 'r':
//                printf("-rがオプションとして渡されました%s\n", optarg);
                fileopen(optarg, opt);
                break;

            default: /* '?' */
                //指定していないオプションが渡された場合
//                printf("Usage: %s [-f] [-g] [-h argment] arg1 ...\n", argv[0]);
                break;
        }
    }

    //オプション以外の引数を出力する
    for (i = optind; i < argc; i++) {
        printf("arg = %s\n", argv[i]);
    }



    return 0;
}