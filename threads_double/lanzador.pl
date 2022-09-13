#!/usr/bin/perl

=begin comment
Fecha: 08 - Septiembre - 2022
Autor: Paula Sofia Godoy Salamanca
Materia: Parallel and distributed Computing
Tema: Ejecucion automatizacion de Benchmark
=cut

#Vector para los benchmarks 
@benchmarks=("mm_main", "mm_main_int_rnd");  #Nombre del ejecutable
#Vector para las cargas
@carga= ("100", "200","300");
#Numero de repeticiones
$n = 2;
$Path="/home/sofia/Documentos/CPD/Benchmark_2/Clase_08/Bench_Pthreads";

=begin comment
La cantidad de ejecutables
La cantidad de cargas
La cantidad de repeticiones
=cut

foreach $exes(@benchmarks){
	foreach $cargas(@carga){
		#Se crea un fichero para almacenar los datos
		$file ="Soluciones/".$exes."-size-".$carga.".txt";
		for($i=0;$i<$n;$i++){
			printf("$Path$exes $carga");
			system("$Path$exes $carga >> $file");
		}
		close($file);
		
	}
}

