#include <stdio.h>
#include "miLista.h"

extern ElementoLista *Lista_Siguiente(ListaEnlazada *lista, ElementoLista *elemento){	
	if (elemento == NULL) {
		return NULL;
	}
	if (elemento->siguiente == NULL) {			
		return NULL;
	}
	if (elemento->siguiente == &lista->ancla) {
		return NULL;
	}
	return elemento->siguiente;
}

