#include <stdio.h>
#include "miLista.h"

extern void Lista_Sacar(ListaEnlazada *lista, ElementoLista *elemento){
	ElementoLista* elem = Lista_Buscar(lista, elemento->objeto);
	if (elemento == NULL) {
		return;
	}
	elem->siguiente->anterior = elem->anterior;
	elem->anterior->siguiente = elem->siguiente;
	elem->siguiente = NULL;
	elem->anterior = NULL;
	lista->numeroElementos -= 1;
	lista->ancla.objeto = &lista->numeroElementos;
	printf("saca");
	//free(elem); de esta liena no estoy seguro
	return;
}

