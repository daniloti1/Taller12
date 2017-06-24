#include <stdio.h>
#include <stdlib.h>
#include "miLista.h"

extern int Lista_Inicializar(ListaEnlazada *lista){
	if (lista->ancla.objeto != NULL) {
		return FALSE;
	}
	lista->numeroElementos = 0;
	ElementoLista* inicio = (ElementoLista*) malloc(sizeof(ElementoLista)); 
	inicio->objeto = &lista->numeroElementos;
	inicio->anterior = NULL;
	inicio->siguiente = NULL;
	lista->ancla = *inicio;
	return TRUE;
}

