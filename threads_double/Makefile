#/**************************************************************************
# * Fecha: 08 - Septiembre - 2022
# * Autor: Paula Sofia Godoy Salamanca
# * Materia: Parallel and distributed Computing
# * Tema: Multiplicacion de matrices con hilos
#**************************************************************************/

GCC = gcc
FLAGS = -ansi -std=c11 -pedantic -Wall -D_POSIX_C_SOURCE=199309L
MATHFLAG = -lm -lpthread -fopenmp

PROGRS = mm_c_double mm_main_double_rnd

all: $(PROGRS) 

mm_c_double: 
	$(GCC) $(FLAGS) -c $@.c
	$(GCC) $(FLAGS) -c mm_lib.c
	$(GCC) $(FLAGS) -o $@ $@.o mm_lib.o $(MATHFLAG)
	
mm_main_double_rnd:
	$(GCC) $(FLAGS) -c $@.c
	$(GCC) $(FLAGS) -c mm_lib.c
	$(GCC) $(FLAGS) -o $@ $@.o mm_lib.o $(MATHFLAG)

	
clean: 
	$(RM) *.o $(PROGRS)
	
