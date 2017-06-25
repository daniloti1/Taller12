#include <stdio.h>
#include "miLista.h"

extern ElementoLista *Lista_Anterior(ListaEnlazada *lista, ElementoLista *elemento){
	if (elemento == NULL) {
		return NULL;
	}
	if (elemento->anterior == NULL) {			
		return NULL;
	}
	if (elemento->anterior == &lista->ancla) {
		return NULL;
	}
	return elemento->anterior;
}
