#include <stdio.h>
#include "miLista.h"

extern int Lista_InsertarDespues(ListaEnlazada *lista, void *objeto, ElementoLista *elemento){
	ElementoLista* elem = Lista_Buscar(lista, elemento->objeto);
	if (elem == NULL) {
		return FALSE;
	}
	elemento->anterior = elem;
	elemento->siguiente = elem->siguiente;
	elem->siguiente->anterior = elemento;
	elem->siguiente = elemento;
	lista->numeroElementos += 1;
	lista->ancla.objeto = &lista->numeroElementos;
	return TRUE;	
}

