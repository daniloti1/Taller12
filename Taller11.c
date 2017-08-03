#include <stdio.h>

#include <time.h>

#include <stdlib.h>

#include <sys/time.h>

#include <pthread.h>



long aleatorio(int min, int max){


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

	long * arreglo;

	int inicio;

	int fin;

} apy;


void * funcion(void* estructura) {

	apy * estructura2 = (apy*) estructura;

	int inicio = (int)estructura2->inicio;

	int fin = (int)estructura2->fin;

	long * arreglo = (long *)estructura2->arreglo;


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


	int tamano = atoi(argv[1]);


	int hilos = atoi(argv[2]);


	long * arreglo = (long *) malloc(sizeof(long)*tamano);

	int numElementos = tamano/hilos;

	for (int i = 0; i < tamano; i++) {

		*(arreglo+i) = aleatorio(50,200);

	}

	int sumaFinal = 0;

    	pthread_t * listaIds = (pthread_t *) malloc(sizeof(pthread_t)*hilos);

	int contador = 0;

	double tiempo_0 = obtenerTiempoActual();

	for (int j = 0; j < tamano; j += numElementos) {		

		apy * estructura = (apy *)malloc(sizeof(apy));

		estructura->inicio = j;

		if (numElementos*hilos < tamano) {
			j++;
		}

		estructura->fin = j + numElementos;

		if (j + numElementos > tamano) {
			estructura->fin = tamano;
		}

		estructura->arreglo = arreglo;


		int statusHilo = pthread_create(&listaIds[contador], NULL, funcion, (void *)estructura);


		if (statusHilo < 0) {

			fprintf(stderr, "Error al crear el hilo\n");

			exit(-1);	

		}


		contador++;

	}

	for (int k = 0; k < hilos; k++) {

		void * retorno = NULL;

		int status = pthread_join(listaIds[k], &retorno);
	
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
