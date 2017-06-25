#include <stdio.h>
#include <stdlib.h>
#include "miLista.h"

extern int Lista_InsertarDespues(ListaEnlazada *lista, void *objeto, ElementoLista *elemento){
	if (Lista_Buscar(lista, elemento->objeto) == NULL) {
		return FALSE;
	}
	ElementoLista* aInsertar = (ElementoLista*) malloc(sizeof(ElementoLista));
	aInsertar->objeto = objeto;	
	aInsertar->anterior = elemento;
	aInsertar->siguiente = elemento->siguiente;
	elemento->siguiente->anterior = aInsertar;
	elemento->siguiente = aInsertar;
	lista->numeroElementos += 1;
	lista->ancla.objeto = &lista->numeroElementos;
	return TRUE;	
}

