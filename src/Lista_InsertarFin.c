#include <stdio.h>
#include <stdlib.h>
#include "miLista.h"

extern int Lista_InsertarFin(ListaEnlazada *lista, void *objeto){
	ElementoLista *elemento = (ElementoLista*) malloc(sizeof(ElementoLista));	
	if(lista->numeroElementos==0){	
		elemento->objeto=objeto;
		elemento->siguiente = &(lista->ancla);
		elemento->anterior = &(lista->ancla);
		(lista->ancla).siguiente = elemento;
		(lista->ancla).anterior = elemento;
		lista->numeroElementos++;
		return 1;
	}else{
		elemento->objeto=objeto;
		elemento->siguiente = &(lista->ancla);
		elemento->anterior = (lista->ancla).anterior;
		lista->ancla.anterior->siguiente = elemento;
		(lista->ancla).anterior = elemento;
		lista->numeroElementos++;
		return 1;
	}
	return 0;
	
}

