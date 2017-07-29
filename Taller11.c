#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>


int aleatorio(int min, int max){

	return (rand() % (max-min+1)) + min;

}

double obtenerTiempoActual(){

	struct timespec tsp;

	clock_gettime( CLOCK_REALTIME, &tsp);

	double secs = (double)tsp.tv_sec;
	double nano = (double)tsp.tv_nsec / 1000000000.0;

	return secs + nano;

}

typedef struct _apy {
	int * arreglo;
	//int tamano;
	int inicio;
	int fin;
} apy;

void * funcion(void* estructura) {
	//int tamano = estructura->tamano;
	apy * estructura2 = (apy*) estructura;
	int inicio = (int)estructura2->inicio;
	int fin = (int)estructura2->fin;

	int * arreglo = (int *)estructura2->arreglo;

	int suma = 0;

	for (int i = inicio; i < fin; i++) {
		suma += arreglo[i];
	}

	return (void *)suma;
}


int main(int argc, char **argv) {

	srand(time(0));
	
	if (argc < 3) {
		printf("./Taller11 <tamaño_arreglo> <numero_hilos>");
		exit(1);
	}

	double tiempo_0 = obtenerTiempoActual();

	int tamano = atoi(argv[1]);

	int hilos = atoi(argv[2]);

	int * arreglo = (int *) malloc(sizeof(int)*tamano);
	for (int i = 0; i < tamano; i++) {
		*(arreglo+i) = aleatorio(50,200);
	}
	
	int numHilos = tamano/hilos;
	
	int sumaFinal = 0;
	
	
	for (int j = 0; j < tamano; j += numHilos) {
		pthread_t id;
		

		apy  est;
		est.inicio = j;
		est.fin = j + numHilos;
		//estructura->tamano = ;
		est.arreglo = arreglo;
		apy * estructura = &est;

		int statusHilo = pthread_create(&id, NULL, funcion, (void *)estructura);

		if (statusHilo < 0) {
			fprintf(stderr, "Error al crear el hilo\n");
			exit(-1);	
		}
		//funcion(&estructura);

		void * retorno = NULL;

		int status = pthread_join(id, &retorno);
		
		if (status < 0) {
			fprintf(stderr, "Error al crear el hilo\n");
			exit(-1);	
		}

		printf("Valor de Retorno: %lu\n",(long)retorno);
		sumaFinal += (int) retorno;

	}

	

	double tiempo_1 = obtenerTiempoActual();
	double tiempoTotal = tiempo_1 - tiempo_0;
	printf("Suma Total: %d\n",sumaFinal);

	printf("Tiempo de ejecucion: %9f\n",tiempoTotal);
}






