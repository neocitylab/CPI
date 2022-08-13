GCC = gcc
GFLAGS= -ansi -pedantic -Wall -std=c99 -D_POSIX_C_SOURCE=199309L
MFLAGS = -lm
PROGRAMAS = ejercicios_main

all: $(PROGRAMAS)
ejercicios_main:
	$(GCC) $(GFLAGS) -c $@.c
	$(GCC) $(GFLAGS) -c ejercicios_lib.c -c
	$(GCC) $(GFLAGS) -o $@ $@.o ejercicios_lib.o $(MFLAGS)
clean:  		
	$(RM) *.o $(PROGRAMAS)
