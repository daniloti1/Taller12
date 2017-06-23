#include <stdio.h>
#include "miLista.h"

int Lista_InsertarAntes(ListaEnlazada *lista, void *objeto, ElementoLista *elemento){
	ElementoLista* elem = Lista_Buscar(lista, elemento->objeto);
	if (elem == NULL) {
		return FALSE;
	}
	elemento->anterior = elem->anterior;
	elemento->siguiente = elem;
	elem->anterior->siguiente = elemento;
	elem->anterior = elemento;
	lista->numeroElementos += 1;
	lista->ancla.objeto = &lista->numeroElementos;
	return TRUE;

}
