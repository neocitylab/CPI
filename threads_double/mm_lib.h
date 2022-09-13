/**************************************************************************
 * Fecha: 08 - Septiembre - 2022
 * Autor: Paula Sofia Godoy Salamanca
 * Materia: Parallel and distributed Computing
 * Tema: Multiplicacion de matrices con hilos
**************************************************************************/

/****
 * Proyecto para 
 * Archivo: INTERFAZ  
****/

#ifndef MM_LIB_H_INCLUDED
#define MM_LIB_H_INCLUDED

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>


void inicializacion_double(double *a, double *b, double *c, int N);
void multiplicacion_mm_double(double *a, double *b, double *c, int N);
void punto_prueba_inicial();
void punto_prueba_final();
void impresion_double(double *matriz, int N);
void inicializacion_double_rnd(double *a, double *b, double *c, int N);
void *mm_clasica(void *argHILO);
double random_double();

#endif
