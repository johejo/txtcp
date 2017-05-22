CC = gcc
PROGRAM=txtcp
CFLAGS = -Wall -O
OBJS = main.o file.o
$(PROGRAM) : $(OBJS)
	$(CC) $(OBJS) -o $(PROGRAM)
main.o : main.c defs.h
	$(CC) -c $(CFLAGS) main.c

file.o : file.c defs.h
	$(CC) -c $(CFLAGS) file.c

clean:
	-rm -rf $(OBJS) $(PROGRAM)
