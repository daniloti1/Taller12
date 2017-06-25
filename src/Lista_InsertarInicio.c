#include <stdio.h>
#include <stdlib.h>
#include "miLista.h"

extern int Lista_InsertarInicio(ListaEnlazada *lista, void *objeto){
	ElementoLista *elemento = (ElementoLista*) malloc(sizeof(ElementoLista));
	if(lista->numeroElementos==0){	
		elemento->objeto=objeto;
		elemento->siguiente = lista->ancla.objeto;
		elemento->anterior = lista->ancla.objeto;
		lista->ancla.siguiente = elemento;
		lista->ancla.anterior = elemento;
		lista->numeroElementos++;
		return TRUE;
	}else{
		elemento->objeto=objeto;
		elemento->siguiente = lista->ancla.siguiente;
		elemento->anterior = lista->ancla.objeto;
		lista->ancla.siguiente->anterior = elemento;
		lista->ancla.siguiente = elemento;
		lista->numeroElementos++;	
		return TRUE;
	}
	return FALSE;
}

