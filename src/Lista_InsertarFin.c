#include <stdio.h>
#include <stdlib.h>
#include "miLista.h"

extern int Lista_InsertarFin(ListaEnlazada *lista, void *objeto){
	printf("Lista_InsertarFin\n");
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
		return 1;
	}else{
		elemento->objeto=objeto;
		elemento->siguiente = &(lista->ancla);//.siguiente;
		elemento->anterior = (lista->ancla).anterior;
		//elemento->siguiente = &lista->ancla;
		//elemento->anterior = lista->ancla.anterior;
		lista->ancla.anterior->siguiente = elemento;
		(lista->ancla).anterior = elemento;
		lista->numeroElementos++;
		//free(objeto);
		return 1;
	}
	return 0;
	
}

