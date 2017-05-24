#include "defs.h"

char *fileopen(char *filename, int opt){
    int fd;
    char *c = (char *)calloc(1, sizeof(char));
    char *tmp;

    fd = open(filename, O_RDONLY|O_CREAT, S_IRUSR|S_IWUSR);
    if (fd == -1) {
        perror("Cannot open file");
        exit(1);
    }

    off_t size = lseek(fd, 0, SEEK_END);
    char *out = (char *)calloc((size_t)size, sizeof(char));

    if (opt == 'r') {
        lseek(fd, -1, SEEK_END);
    } else {
        lseek(fd, 0, SEEK_SET);
    }

    int i = 0, n;
    while(i < size) {
        char *buf = (char *)calloc(1, sizeof(char));
        n = 1;
        while (1) {
            tmp = (char *) realloc(buf, n * sizeof(char));
            if (!tmp) {
                free(buf);
                perror("realloc error\n");
            }
            buf = tmp;

            if (read(fd, c, 1) == -1) {
                perror("read error\n");
            }

            lseek(fd, -2, SEEK_CUR);

            sprintf(buf, "%s%s", buf, c);
            i++;
            if (*c == '\n') {
                break;
            }

            if (i >= size) {
                break;
            }
            n++;
        }

        sprintf(out, "%s%s", out, buf);
        strrev(buf);
    }

    return out;
}

void write_file(char *filename, char *out){
    int fd = open(filename, O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    if (fd == -1) {
        perror("Cannot open write");
        exit(1);
    }

    if (write(fd, out, strlen(out)) == -1){
        perror("write error");
        exit(1);
    }
    return;
}


void print_help(){
    char *command = "cat help.txt";
    if(system(command) == -1){
        perror("help error");
    }
    return;
}

void strrev(char s[]){
    char temp = '\0';
    char *first = s;
    char *last = s;

    // 長さ0の文字列なら操作せず返す
    if(*first == '\0'){ return; }

    // 文字列の最後の文字のポインタを取得する
    while( *(last+1) != '\0'){ last++; }

    // 外側から逆にする
    while(first < last){
        temp = *first;
        *first = *last;
        *last = temp;

        // 一つずつ範囲を小さくする
        first++;
        last--;
    }
    return;
}