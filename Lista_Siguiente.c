#include <stdio.h>
#include "miLista.h"

ElementoLista *Lista_Siguiente(ListaEnlazada *lista, ElementoLista *elemento){	
	ElementoLista* elem = Lista_Buscar(lista, elemento->objeto);
	if (elem == NULL) {
		return NULL;
	}
	return elem->siguiente;
}

