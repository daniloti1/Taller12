#include <stdio.h>
#include "miLista.h"

extern ElementoLista *Lista_Buscar(ListaEnlazada *lista, void *objeto){
	ElementoLista* elem = &(lista->ancla);
	for (int i = 0; i < lista->numeroElementos + 1; i++) {
		if (i != 0) {			 
			if (objeto == elem->objeto) {
				return elem;
			}
		}
		elem = elem->siguiente;
	}
	return NULL;
}
