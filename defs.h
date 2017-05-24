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

void print_help();
char *fileopen(char *filename, int opt);
void strrev(char s[]);
void write_file(char *filename, char *out);

#endif //TXTCP_DEFS_H