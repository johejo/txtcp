#include "defs.h"

int fileopen(char *filename, int opt){
    int fd;
    int offset =0;
    off_t pos;

    fd = open(filename, O_CREAT|O_RDWR|O_TRUNC,S_IRWXU);
    if (fd == -1) {
        perror("Cannot open file");
    }

    if (opt == 'r') {
        pos = lseek(fd, offset, SEEK_END);
    } else {
        pos = lseek(fd, offset, SEEK_SET);
    }

    return fd;
}


