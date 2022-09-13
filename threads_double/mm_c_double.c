/**************************************************************************
 * Fecha: 08 - Septiembre - 2022
 * Autor: Paula Sofia Godoy Salamanca
 * Materia: Parallel and distributed Computing
 * Tema: Multiplicacion de matrices con hilos
**************************************************************************/
#include "mm_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <omp.h>


/*** Se declaran las variables globales, en una estructura de datos***/
typedef struct argumentos_hilos{
	double *arg_matA;
	double *arg_matB;
	double *arg_matC; //Matrices de doubles
	int arg_Num_Hilos;	//Cantidad de hilos
	int arg_N; //Dimension de la matriz
	int arg_ID_hilo;//identificador del hilo
} arg_threads; 

int main(int argc, char **argv){
    double *matA, *matB, *matC;
    int N = (int) atof(argv[1]);//Tamaño matriz
    int num_Hilos=(int) atof(argv[2]); //Cantidad de hilos   
    int MAX_NUM_HILOS = omp_get_max_threads();
    
    /**num_Hilos <= num max hilos disponibles**/    
    if(!(num_Hilos > 0 && num_Hilos <= MAX_NUM_HILOS) || (!(N % num_Hilos == 0))) {
    	printf("El numero de hilos debe ser <= %d\n", MAX_NUM_HILOS);
    	printf("NO es posible distribuir de forma entera el nuero de hilos\n");
    	exit(0);
    }

    printf("Numero de hilos: %d\n", MAX_NUM_HILOS);
     
    /** Declaracion tipo ihlos y argumento para estos**/
    pthread_t *hilos; //Vector de hilos
    arg_threads arg_hilos_array[num_Hilos]; //vector de ese tipo de dato 
    
    /*** Reserva de memoria con MALLOC ***/
    matA = (double *)malloc(N*N*sizeof(double));
    matB = (double *)malloc(N*N*sizeof(double));
    matC = (double *)malloc(N*N*sizeof(double));   


    inicializacion_double(matA, matB, matC, N);  
    impresion_double(matA, N);
    impresion_double(matB, N);

    //Se reserva la memoria para cada hilo    
    hilos = (pthread_t *)malloc(num_Hilos*sizeof(pthread_t));
    
    punto_prueba_inicial();
    /* Se ha de repartir cada problema con su correspondiente carga, en funcion de la cantidad de hilos*/    
    for(int i=0; i<num_Hilos; i++){
    //Se asigna vector de estructura por tipo para cada hilo
    	arg_hilos_array[i].arg_matA = matA;
    	arg_hilos_array[i].arg_matB = matB;
    	arg_hilos_array[i].arg_matC = matC;
    	arg_hilos_array[i].arg_Num_Hilos = num_Hilos;
    	arg_hilos_array[i].arg_N = N;
    	arg_hilos_array[i].arg_ID_hilo = i;
    	pthread_create(&hilos[i], NULL, mm_clasica, &arg_hilos_array[i]);
    }
    
    /*Se unen los hilos, se hace el JOIN*/
    for(int i=0; i<num_Hilos; i++){
    	pthread_join(hilos[i], NULL);
    }    

    /****
     * Inicio de toma de tiempo
     * Mulplticación de matrices
     * Fin de toma de tiempo 
    ****/
    punto_prueba_final();  

    impresion_double(matC, N);  
    //Liberacion de reserva de memoria con MALLOC
    free(hilos);
    free(matA);
    free(matB);
    free(matC);
    

    return 0;
}
