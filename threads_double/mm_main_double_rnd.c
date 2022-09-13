/**************************************************************************
 * Fecha: 16 - Agosto - 2022
 * Autor: Brayan Stiven Castañeda Cruz
 * Materia: Parallel and distributed Computing
 * Tema: Construcción Benckmark Multiplicación de matrices
 * Objetivo: Tomas de tiempo de ejecución de la multiplicación de matrices 
**************************************************************************/

/****
 * Proyecto para 
 * Archivo: PRINCIPAL  
****/
#include "mm_lib.h"
#include <stdio.h>
#include <stdlib.h>

/****
 * Se requiere reservar un espacio de memporia 
****/
#define DATA_SIZE (1024 * 1024 * 64 * 3)
static int MEM_CHUNK[DATA_SIZE];

/****
 * Función principal de la aplicación 
****/
int main(int argc, char **argv){

    int N; 
    N = (int) atof(argv[1]);
    

    /****
     * Declaración de matrices con apuntadores a memoria
    ****/
    int *a, *b, *c;
    a = MEM_CHUNK;
    b =  a + N*N;
    c =  b + N*N;


    inicializacion_int_rnd(a, b, c, N);
    impresion_int(a, N);
    printf("\n");
    impresion_int(b, N);
    printf("\n");
    

    punto_prueba_inicial();
    multiplicacion_mm_int(a, b, c, N);
    punto_prueba_final();
    
    printf("\n");
    impresion_int(c, N);
    

    return 0;
}
