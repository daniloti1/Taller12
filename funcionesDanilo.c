#include <stdio.h>
#include <miLista.h>

int Lista_Inicializar(ListaEnlazada *lista){
	if (lista->ancla != NULL) {
		return FALSE;
	}
	lista->numeroElementos = 0;
	ElementoLista* inicio = (Elementolista*) malloc(sizeof(ElementoLista*)); 
	inicio->objeto = &lista->numeroElementos;
	inicio->anterior = NULL;
	inicio->siguiente = NULL;
	lista->ancla = inicio;
	return TRUE;
}

int Lista_Vacia(ListaEnlazada *lista){
	if (lista->numeroElementos == 0) {
		return TRUE;
	}
	return FALSE;
}


int Lista_Conteo(ListaEnlazada *lista){
	return lista->numeroElementos;
}
