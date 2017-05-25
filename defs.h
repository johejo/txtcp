//
// Created by heijo on 17/05/22.
//

#ifndef TXTCP_DEFS_H
#define TXTCP_DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define ERROR -1
#define SUCCESS 0

void print_help();
char *fileopen(char *filename, int optr);
void strrev(char s[]);
int write_file(char *filename, char *out, int opti);

#endif //TXTCP_DEFS_H