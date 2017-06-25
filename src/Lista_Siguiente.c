#include <stdio.h>
#include "miLista.h"

extern ElementoLista *Lista_Siguiente(ListaEnlazada *lista, ElementoLista *elemento){	
	if (elemento == NULL) {
		return NULL;
	}
	ElementoLista* elem = Lista_Buscar(lista, elemento->objeto);
	printf("Entro en siguiente \n");
	printf("%lu\n", (long)elem->objeto);
	if (elem == NULL) {
		return NULL;
	}
	if (elem->siguiente == &lista->ancla) {
		return NULL;
	}
	//printf("siguiente");
	return elem->siguiente;
}

