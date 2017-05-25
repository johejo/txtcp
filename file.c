#include "defs.h"

//Open file
char *fileopen(char *filename, int optr){
    int fd;
    char *c = (char *)calloc(1, sizeof(char));
    char *tmp;
    int next;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Cannot open file");
        return NULL;
    }

    //Check size
    off_t size = lseek(fd, 0, SEEK_END);
    char *out = (char *)calloc((size_t)size, sizeof(char));

    if (optr == 1) {    //From END
        next = -2;
        lseek(fd, -1, SEEK_END);
    } else {    //From BEGIN
        next = 0;
        lseek(fd, 0, SEEK_SET);
    }

    int i = 0, n;
    //Read all
    while(i < size) {
        char *buf = (char *)calloc(1, sizeof(char));
        n = 1;
        //Read line
        while (1) {
            //Extend mem
            tmp = (char *) realloc(buf, n * sizeof(char));
            if (!tmp) {
                free(buf);
                perror("realloc error\n");
                return NULL;
            }
            buf = tmp;

            if (read(fd, c, 1) == -1) {
                perror("read error\n");
                return NULL;
            }

            lseek(fd, next, SEEK_CUR);

            i++;
            if (*c == '\n') {
                break;
            }

            //Connect buf
            sprintf(buf, "%s%s", buf, c);

            if (i >= size) {
                break;
            }
            n++;
        }

        if (next == -2) {
            strrev(buf);
        }
        //Connect lines
        sprintf(out, "%s\n%s", out, buf);
    }

    //Remove first '\n'
    strrev(out);
    out[strlen(out) - 1] = '\0';
    strrev(out);
    return out;
}

//Write file
int write_file(char *filename, char *out, int opti){
    //Check output file
    int fcheck = open(filename, O_RDONLY);

    if(opti == 1 && fcheck != -1){
        //Overwrite check
        while(1) {
            printf("Would you like to overwrite the file?(y/n)\n");
            int c = fgetc(stdin);
            fgetc(stdin);//Remove '\n'
            if (c == 'y') {
                break;
            } else if (c == 'n') {
                return ERROR;
            }
        }
    }

    //Write
    int fd = open(filename, O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    if (fd == -1) {
        return ERROR;
    }
    if (write(fd, out, strlen(out)) == -1){
        return ERROR;
    }

    return SUCCESS;
}

//print help
void print_help(){
    char *command = "cat help.txt";
    if(system(command) == -1){
        perror("help error");
    }
    return;
}

//Reverse String
void strrev(char s[]){
    char temp;
    char *first = s;
    char *last = s;

    if(*first == '\0'){ return; }

    while( *(last+1) != '\0'){ last++; }

    while(first < last){
        temp = *first;
        *first = *last;
        *last = temp;

        first++;
        last--;
    }
    return;
}