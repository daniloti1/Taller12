#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

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

void * funcion(void* count) {
	pthread_mutex_t mutex;
	
}

main(int argc, char ** argv){
	char ** palabras = (char**)malloc(sizeof(char*)*(argc-3));
	int ** numpalabras = (int**)malloc(sizeof(int*)*(argc-3));
	char *ruta=argv[1];
	int numHilos=atoi(argv[2]);
	int numeroLineas=numero_lineas(ruta,0);
	int numCaraterXlinea*=malloc(sizeof(int)*numeroLineas);
	numero_lineas(ruta,numCaracteresLinea);
	int totPalabraas=0;
	
	for (int i  = 0; i < argc-3; i++) {
		*(palabras+i) = argv[i+3];
	}
	
	for(int j = 1; j < numLineas ; j++){
        totPalabraas  += *(numCaracterXlinea+j);
    }
	
	int divisionParaCadaHilo=totPalabraas/numHilos;
	
	int inicioParaElHilo=0;
	
	for(int k=0;k<numHilos;k++){
		FILE* fp=fopen(ruta,"r");//apertura de archivo
		
        fseek(fp, inicioParaElHilo,SEEK_SET); 
        *(palabras+k) = malloc(divisionParaCadaHilo*sizeof(char));

        for( int j = 0 ; j < divisionParaCadaHilo ; j++){
            char c = getc(file);
            *(*(parrafos+k)+j) = c; 
        }      
        seek = seek + bloque;

	}
	pthread_t * listaIds = (pthread_t *) malloc(sizeof(pthread_t)*hilos);
	
	
	
	char*linea=fgets(fp,buf,);
	
	//Se crea los hilos necesarios
	for(int j=0;j<sizeof(palabras);j++){
		int statusHilo = pthread_create(&listaIds[contador], NULL, funcion, NULL);
		if (statusHilo < 0) {
			fprintf(stderr, "Error al crear el hilo\n");
			exit(-1);	
		}
		
		
	}
		
	
	

}
