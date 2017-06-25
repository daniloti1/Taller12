#include <stdio.h>
#include <stdlib.h>
#include "miLista.h"

extern int Lista_InsertarFin(ListaEnlazada *lista, void *objeto){
	ElementoLista *elemento = (ElementoLista*) malloc(sizeof(ElementoLista));	
	
	printf("%lu\n", (long)objeto);
	
	if(lista->numeroElementos==0){	
		elemento->objeto=objeto;
		elemento->siguiente = &(lista->ancla);//.siguiente;
		elemento->anterior = &(lista->ancla);//.anterior;
		(lista->ancla).siguiente = elemento;
		(lista->ancla).anterior = elemento;
		lista->numeroElementos++;
		//free(objeto);
		printf("Entro vacio \n");
		printf("elemento %lu\n", (long)elemento->objeto);
		return 1;
	}else{
		elemento->objeto=objeto;
		elemento->siguiente = &(lista->ancla);//.siguiente;
		elemento->anterior = (lista->ancla).anterior;
		//elemento->siguiente = &lista->ancla;
		//elemento->anterior = lista->ancla.anterior;
		(lista->ancla).anterior = elemento;
		lista->numeroElementos++;
		//free(objeto);
		printf("Entro lleno \n");
		printf("elemento %lu\n", (long)elemento->objeto);
		return 1;
	}
	return 0;
	
}

