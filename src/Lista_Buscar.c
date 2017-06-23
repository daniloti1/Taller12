#include <stdio.h>
#include "miLista.h"

ElementoLista *Lista_Buscar(ListaEnlazada *lista, void *objeto){
	ElementoLista* elem = &lista->ancla;
	for (int i = 0; i<lista->numeroElementos; i++) {
		if (objeto == elem->objeto) {
			return elem;
		}
		elem = elem->siguiente;
	}
	return NULL;
}
