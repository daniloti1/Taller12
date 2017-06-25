#include <stdio.h>
#include "miLista.h"

extern ElementoLista *Lista_Buscar(ListaEnlazada *lista, void *objeto){
	printf("Iniciando Buscar\n");
	ElementoLista* elem = &(lista->ancla);
	for (int i = 0; i < lista->numeroElementos + 1; i++) {
		if (i != 0) {
			 
			if (objeto == elem->objeto) {
				printf("Se retorna un elem\n");
				return elem;
			}
		}
		elem = elem->siguiente;
	}
	printf("No se encontro elemento\n");
	return NULL;
}
