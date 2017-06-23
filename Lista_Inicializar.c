#include <stdio.h>
#include "miLista.h"

int Lista_Inicializar(ListaEnlazada *lista){
	if (lista->ancla.objeto != NULL) {
		return FALSE;
	}
	lista->numeroElementos = 0;
	ElementoLista* inicio;// = (Elementolista*) malloc(sizeof(ElementoLista*)); 
	inicio->objeto = &lista->numeroElementos;
	inicio->anterior = NULL;
	inicio->siguiente = NULL;
	lista->ancla = *inicio;
	return TRUE;
}

