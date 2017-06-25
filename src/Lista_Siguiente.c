#include <stdio.h>
#include "miLista.h"

extern ElementoLista *Lista_Siguiente(ListaEnlazada *lista, ElementoLista *elemento){	
	ElementoLista* elem = Lista_Buscar(lista, elemento->objeto);
	printf("Entro en siguiente \n");
	printf("%lu\n", (long)elem->objeto);
	if (elem == NULL) {
		return NULL;
	}
	//printf("siguiente");
	return elem->siguiente;
}

