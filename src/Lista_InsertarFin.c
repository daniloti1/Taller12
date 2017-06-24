#include <stdio.h>
#include <stdlib.h>
#include "miLista.h"

extern int Lista_InsertarFin(ListaEnlazada *lista, void *objeto){
	ElementoLista *elemento = (ElementoLista*) malloc(sizeof(ElementoLista));	
	if(lista->numeroElementos==0){	
		elemento->objeto=objeto;
		elemento->siguiente = &(lista->ancla);//.siguiente;
		elemento->anterior = &(lista->ancla);//.anterior;
		(lista->ancla).siguiente = elemento;
		(lista->ancla).anterior = elemento;
		lista->numeroElementos++;
		//free(lista);
		return TRUE;
	}else{
		elemento->siguiente = &(lista->ancla);//.siguiente;
		elemento->anterior = lista->ancla.anterior;
		//elemento->siguiente = &lista->ancla;
		//elemento->anterior = lista->ancla.anterior;
		(lista->ancla).anterior = elemento;
		lista->numeroElementos++;
		//free(lista);
		return TRUE;
	}
	return FALSE;
	
}

