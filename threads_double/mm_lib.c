/**************************************************************************
 * Fecha: 08 - Septiembre - 2022
 * Autor: Paula Sofia Godoy Salamanca
 * Materia: Parallel and distributed Computing
 * Tema: Multiplicacion de matrices con hilos
**************************************************************************/

/****
 * Proyecto para 
 * Archivo: BIBLIOTECA  
****/

#include "mm_lib.h"
#include <time.h>
#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

struct timespec inicio_cuenta, fin_cuenta;

typedef struct argumentos_hilos{
	double *arg_matA;
	double *arg_matB;
	double *arg_matC; //Matrices de doubles
	int arg_Num_Hilos;	//Cantidad de hilos
	int arg_N; //Dimension de la matriz
	int arg_ID_hilo;//identificador del hilo
} arg_threads; 


void *mm_clasica(void *argHILO){
    //Se castea el puntero vacio argHILO como puntero arg_threads de la estructura de datos diseñada.
    double *a =  ((arg_threads *)argHILO)->arg_matA;
    double *b =  ((arg_threads *)argHILO)->arg_matB;
    double *c =  ((arg_threads *)argHILO)->arg_matC;
    int num_Hilos_mm = ((arg_threads *)argHILO)->arg_Num_Hilos;
    int ID_Hilo = ((arg_threads *)argHILO)->arg_ID_hilo;
    int N_mm = ((arg_threads *)argHILO)->arg_N;

	int porcion=N_mm/num_Hilos_mm;
	int ini_porcion, fin_porcion;
	 //Identificacion del hilo, el * despues del int significa el acceso a memoria de una funcion
	ini_porcion=porcion*ID_Hilo;
	fin_porcion=porcion*(ID_Hilo+1);
		
	    for (int i = ini_porcion; i < fin_porcion; i++){
		for(int j = 0; j < N_mm; j++){
		    double suma = 0;
		    /* Punteros auxiliares */
		    double *pA, *pB;
		    pA = a + (i*N_mm);
		    pB = b + j;

		    for (int k = 0; k < N_mm; k++, pA++, pB+=N_mm) {
		        /* Multiplicación y suma de resultados */ 
		        suma += (*pA * *pB);
		    }
		    c[j+i*N_mm] = suma;
		}
	    }
	    return 0;

}
/***FUncion para crear aleatorios INT***/
double random_double(){

    double min=0.001, max=9.999;
    static int flag=-1;
    if((flag=(flag<0)))
    	srand(time(NULL)+getpid());
    if(min > max)
    	return errno= EDOM, NAN;
    return min+(double)rand()/((double)RAND_MAX/(max-min));

}
/*** Funcion inicializadora aleatoria***/

void inicializacion_double_rnd(double *a, double *b, double *c, int N){
    int i, j;
    for (i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            a[i+j*N] = random_double();
            b[i+j*N] = random_double();
            c[i+j*N] = 0;
        }
    }
}

/**** 
 * Funcion evaluación inicio de tiempo  
****/
void punto_prueba_inicial(){
    clock_gettime(CLOCK_MONOTONIC, &inicio_cuenta);
}

/**** 
 * Funcion evaluación final de tiempo e impresión de resultado  
****/
void punto_prueba_final(){
    double total_time;
    clock_gettime(CLOCK_MONOTONIC, &fin_cuenta);
    total_time = (fin_cuenta.tv_sec - inicio_cuenta.tv_sec) * 1e9;
    total_time = (total_time + fin_cuenta.tv_nsec - inicio_cuenta.tv_nsec)* 1e-9;
    printf("Total time: [%f]\n", total_time);
}

/****
 * Inicialización de matrices
****/
void inicializacion_double(double *a, double *b, double *c, int N){
    int i, j;
    for (i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            a[i+j*N] = 2.0*(i+j);
            b[i+j*N] = 2.0*i+3.0+j;
            c[i+j*N] = 0;
        }
    }
}

/****
 * Impresión de matrices
****/
void impresion_double(double *matriz, int N){
	if(N<5){
	    int i, j;
	    for (i = 0; i < N; i++){
		for(j = 0; j < N; j++){
		    printf("%f  ", matriz[i+j*N]);
		}
		printf("\n");
	    }
	}
}


/****
 * Método para multiplicar las 2 matrices por punteros
****/
void multiplicacion_mm_double(double *a, double *b, double *c, int N){
    int i, j, k;
    for (i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            double suma = 0;
            /* Punteros auxiliare */
            double *pA, *pB;
            pA = a + (j*N);
            pB = b + i;

            for (k = 0; k < N; k++, pA++, pB+=N) {
                /* Multiplicación y suma de resultados */ 
                suma += (*pA * *pB);
            }
            c[j+i*N] = suma;
        }
    }
}
