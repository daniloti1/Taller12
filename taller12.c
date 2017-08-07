#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <string.h>


#define MAX 1000000;


int numero_lineas(char*ruta,int*tam_lineas){
	if(ruta!=NULL){
		FILE*ar=fopen(ruta,"r");
		int lineas=0;
		int tam_linea;
		while(!feof(ar)){
			tam_linea++;
			char c=getc(ar);
			if(c=='\n'){
				if(tam_lineas!=NULL){
					tam_lineas[lineas]=tam_linea;
				}
				lineas++;
				tam_linea=0;
			}
		}
		fclose(ar);
		return lineas;
	}
	return -1;
}

typedef struct _apy {

	char ** palabras;

	int * numpalabras;

	char * parrafo;

	int tamano;

} apy;


void * funcion(void* estructura) {
	pthread_mutex_t mutex;

	pthread_mutex_lock(&mutex);
	apy * estructura2 = (apy*) estructura;
	pthread_mutex_unlock(&mutex);

	char *str = (char *) estructura2->parrafo;
	char ** palabras = estructura2->palabras;
	int * num_palabras = estructura2->numpalabras;
	int tamano = estructura2->tamano;
	
	char *token;
	token = strtok(str, " \"!·$%&/()=º|@#~½¬<>-_'ç`+*[]{}ḉç¿,.!?:;");

	while (token != NULL) {
		for (int i = 0; i < tamano; i++) {
			if (!strcmp(*(palabras+i), token)) {
		    		pthread_mutex_lock(&mutex);
				
				//puts(*(palabras+i));
				
				*(num_palabras + i) = *(num_palabras + i) + 1;
				pthread_mutex_unlock(&mutex);
			}
		}
		token = strtok(NULL, " \"!·$%&/()=º|@#~½¬<>-_'ç`+*[]{}ḉç¿,.!?:;");
	}

	printf("--*-Palabras encontradas-*-- \n");
	for (int i = 0; i < tamano; i++) {
		printf("Palabra: %s,  Cantidad: %d\n", *(palabras+i), *(num_palabras+i));
	}
	return (void *) 0;

}


int main(int argc, char ** argv){
	
	if (argc < 3) {

		printf("./taller12 <ruta> <numero_hilos> <palabra1> ...<palabra n> \n");

		exit(1);

	}
	
	char ** palabras = (char**)malloc(sizeof(char*)*(argc-3));
	int * numpalabras = (int*)malloc(sizeof(int)*(argc-3));
	char *ruta = argv[1];
	int numHilos = atoi(argv[2]);
	int numLineas = numero_lineas(ruta,0);
	int * numCaracteresXLinea = malloc(sizeof(int)*numLineas);

	numero_lineas(ruta,numCaracteresXLinea);
	int totPalabraas = 0;
	
	char **parrafos = malloc(numHilos*sizeof(char *));

	for (int i  = 0; i < argc-3; i++) {
		*(palabras+i) = argv[i+3];
	}
	
	for(int j = 1; j < numLineas ; j++){
        	totPalabraas  += *(numCaracteresXLinea+j);
    	}
	
	int divisionParaCadaHilo=totPalabraas/numHilos;

	int inicioParaElHilo=0;
	
	for(int k = 0; k < numHilos; k++){
		FILE* fp = fopen(ruta,"r");
		
		fseek(fp, inicioParaElHilo, SEEK_SET);
		 
		*(parrafos+k) = malloc(divisionParaCadaHilo*sizeof(char));

		for( int j = 0 ; j < divisionParaCadaHilo; j++){
			char c = getc(fp);
			*(*(parrafos+k)+j) = c; 
		}      
		inicioParaElHilo += divisionParaCadaHilo*sizeof(char);

	}
	//fclose(fp);

	pthread_t * listaIds = (pthread_t *) malloc(sizeof(pthread_t)*numHilos);
	
	
	
	//char*linea=fgets(fp,buf,);
	
	//Se crea los hilos necesarios
	for(int j=0; j < numHilos; j++){
		apy * estructura = (apy *)malloc(sizeof(apy));
		estructura->parrafo = parrafos[j];
		estructura->palabras = palabras;
		estructura->numpalabras = numpalabras;
		estructura->tamano = argc-3;

		int statusHilo = pthread_create(&listaIds[j], NULL, funcion, (void *) estructura);
		if (statusHilo < 0) {
			fprintf(stderr, "Error al crear el hilo\n");
			exit(-1);	
		}
		
		
	}

	for (int j = 0; j < numHilos; j++) {
        int statusHiloJoin = pthread_join(listaIds[j], NULL);
        if (statusHiloJoin < 0) {
            fprintf(stderr, "Error al esperar por el hilo\n");
            exit(-1);
        }
    }

	return (0);
		
	
	

}
