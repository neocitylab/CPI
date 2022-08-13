#include "ejercicios_lib.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void operacionMult(){
	int a, b, ans;
	printf("Ingrese el valor del primer entero: ");
	scanf("%d", &a);
	printf("\nIngrese el valor del segundo entero: ");
	scanf("%d", &b);
	ans=a*b;
	printf("El producto entre los enteros %d y %d es de: %d\n ", a, b, ans);
	
}
void conversorFecha(){
	int dias, anio, semana, resp;
	printf("Ingrese el numero de dias a convertir: ");
	scanf("%d", &dias);
	
	anio=dias/365;
	semana=(dias%365)/7;
	resp=(dias%365)%7;
	
	printf("Años: %d \nSemanas: %d \nDias: %d ",anio, semana, resp);
}

void distanciaPuntos(){
	int x1, x2, y1, y2;
	float DISTANCIA;
	
	printf("Ingrese las coordenadas del primer punto (x,y): ");
	scanf("%d %d", &x1, &y1);
	printf("\nIngrese las coordenadas del segundo punto (x,y): ");
	scanf("%d %d", &x2, &y2);
	printf("Punto 1: %d %d \nPunto 2: %d %d", x1, y1, x2, y2);
	DISTANCIA=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	printf("\nLa distancia entre los dos puntos es de : %f", DISTANCIA);
	
}

void numNatural(){
	int i;
	printf("Primeros 10 numeros naturales: ");
	for(i=1; i<=10; i++){
		printf("%d ", i);
	}
}

void dibTriangulo(){
	int linea, i, a;
	printf("Ingrese el numero de filas que desea dibuaar (recuerde que el valor maximo es 14): ");
	scanf("%d",&linea);
	while(linea<1 || linea>14 ){
		printf("Por favor ingrese un numero valido!");
		printf("\nNumero: ");
		scanf("%d",&linea);
	}
	for(i=0; i<linea; i++){
		for(a=1; a<=(i+1); a++){
			printf("*");
		}
		printf("\n");
	}

}

void matrizUno(int tamanio){
	int i, a;
	int onex[tamanio][tamanio];		
	
	for(i=0; i<tamanio; i++){
		for(a=0; a<tamanio; a++){
			onex[i][a]=1;
		}
	}
	
	for(i=0; i<tamanio; i++){
		for(a=0; a<tamanio; a++){
			printf("%d ", onex[i][a]);
		}
		printf("\n");
	}
}


void matrizRandom(int random[], int size){
	int i, a, temp;		
	srand(time(NULL));
	for(i=0; i<size; i++){
		for(a=0; a<size; a++){
			temp=rand()%10;
			random[i+a*size]=temp;

		}
	}
	for(i=0; i<size; i++){
		for(a=0; a<size; a++){
			printf("%d ", random[i+a*size]);
		}
		printf("\n");
	}
	temp=0;
}
void matrizRandom2(int random[], int random2[], int size){
	int i, a;		
	srand(time(NULL));
	for(i=0; i<size; i++){
		for(a=0; a<size; a++){
			random[i+a*size]=rand()%10;
			random2[i+a*size]=rand()%10;

		}
	}
	printf("Matriz 1: \n");
	for(i=0; i<size; i++){
		for(a=0; a<size; a++){
			printf("%d ", random[i+a*size]);
		}
		printf("\n");
	}
	printf("Matriz 2: \n");
	for(i=0; i<size; i++){
		for(a=0; a<size; a++){
			printf("%d ", random2[i+a*size]);
		}
		printf("\n");
	}

}
int valorMat(){
	int size;
	printf("Ingrese el tamaño N de la matriz (maximo 7): ");
	scanf("%d", &size);

	while(size<1 || size>7 ){
	printf("Por favor ingrese un tamaño valido!");
	printf("\nTamaño: ");
	scanf("%d",&size);
	}
	
	return size;
}


void sumaMatriz(int matrizA[],int matrizB[],int matrizC[], int size){

	int i, a;		
	printf("Resultado de la suma: \n");
	for(i = 0; i <size;i++){
		for(a = 0; a<size; a++){
			printf(" %d", matrizC[i+a*size]= matrizA[i+a*size]+matrizB[i+a*size]);
		}
		printf("\n");
	}
	
}

void restaMatriz(int matrizA[],int matrizB[],int matrizC[], int size){
	int i, a;		
	printf("Resultado de la resta: \n");
	for(i = 0; i <size;i++){
		for(a = 0; a<size; a++){
			printf(" %d", matrizC[i+a*size]= matrizA[i+a*size]-matrizB[i+a*size]);
		}
		printf("\n");
	}

}
void mm_clasica(int matrizA[],int matrizB[],int matrizC[], int N){
	int suma, i, j, k, a;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			suma=0;
			for(k=0; k<N;k++){
				suma+=matrizA[j+k*N]*matrizB[k+i*N];
			}
			matrizC[j+i*N]=suma;
		}
	}
	
	printf("Resultado de la multiplicacion: \n");
	for(i=0; i<N; i++){
		for(a=0; a<N; a++){
			printf("%d ", matrizC[i+a*N]);
		}
		printf("\n");
	}
	
}

	
	
void Menu(){
	bool seguir=true;
	int op;
	
	do{
		
		printf("\t\t========================================================\n");
		printf("\t\t=                                                      =\n");
		printf("\t\t=                                                      =\n");
		printf("\t\t=                 PROGRAMAS VARIOS                     =\n");
		printf("\t\t=                                                      =\n");
		printf("\t\t=                                                      =\n");
		printf("\t\t========================================================\n");
		printf("Bienvenido al Sistema: \n");
		printf("1. Producto entre dos enteros\n2. Conversor de fechas(Dias->anios, semanas y dias)\n3. Distancia entre dos puntos\n4. Impresion 10 primeros numeros naturales\n5. Patron triangulo\n");
		printf("6. Matriz de unos\n7. Matriz numero aleatorios\n8. Suma de dos matrices\n9. Resta de dos matrices\n10. Mutiplicacion de dos matrices\n");
		printf("11. Salir\n");
		printf("Ingrese la opcion: ");		
		scanf("%d", &op);
				
														
			switch(op){
				case 1: system("clear");
						operacionMult();						
						break;	
				case 2: system("clear");
						conversorFecha();						
						break;	
				case 3: system("clear");
						distanciaPuntos();
						
						break;
				case 4: system("clear");
						numNatural();
						
						break;	
				case 5: system("clear");
						dibTriangulo();
						
						break;	
				case 6: system("clear");
						matrizUno(valorMat());
						
						break;	
				case 7: {
						system("clear");
						int valor, total;
						valor=valorMat();
						total=valor*valor;
						int matrizR[total];						
						matrizRandom(matrizR, valor);					
						
						break;	}
				case 8: {
						system("clear");
						int valor, total;
						valor=valorMat();
						total=valor*valor;
						int ac[total], b[total], c[total];					
						matrizRandom2(ac,b,valor);
						sumaMatriz(ac, b, c, valor);										
						
						break;	}				
				case 9: {
						system("clear");
						int valor, total;
						valor=valorMat();
						total=valor*valor;
						int ac[total], b[total], c[total];					
						matrizRandom2(ac,b,valor);
						restaMatriz(ac, b, c, valor);										
						
						break;	}	
				case 10: {
						system("clear");
						int valor, total;
						valor=valorMat();
						total=valor*valor;
						int ac[total], b[total], c[total];					
						matrizRandom2(ac,b,valor);
						mm_clasica(ac, b, c, valor);										
						
						break;	}	
				case 11: 
						printf("Gracias por usar el programa!\n");
						seguir=false;

						break;
				default: 
						printf("Ingreso no valido. Saliendo del programa....\n");
						seguir=false;

				break;		
			}
	}while(seguir==true);

}


