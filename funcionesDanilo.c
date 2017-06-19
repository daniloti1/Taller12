#include <stdio.h>
#include <miLista.h>

int Lista_Inicializar(ListaEnlazada *lista){
	if (lista->ancla != NULL) {
		return FALSE;
	}
	lista->numeroElementos = 0;
	ElementoLista inicio = (Elementolista) malloc(sizeof(ElementoLista)); 
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

ElementoLista *Lista_Buscar(ListaEnlazada *lista, void *objeto){
	ElementoLista* elem = &lista->ancla;
	for (int i = 0; i<lista->numeroElementos; i++) {
		if (*objeto == *elem->objeto) {
			return elem;
		}
		elem = elem->siguiente;
	}
	return NULL;
}

void Lista_Sacar(ListaEnlazada *lista, ElementoLista *elemento){
	ElementoLista* elem = Lista_Buscar(lista, elemento->objeto);
	if (elem == NULL) {
		return;
	}
	elem->siguiente->anterior = ele->anterior;
	elem->anterior->siguiente = elem->siguiente;
	elem->siguiente = NULL;
	elem->anterior = NULL;
	lista->numeroElementos -= 1;
	lista->ancla->objeto = &lista->numeroElementos;
	//free(elem); de esta liena no estoy seguro
}

void Lista_SacarTodos(ListaEnlazada *lista){
	lista->ancla-siguiente = NULL;
	lista->numeroElementos = 0;
	lista->ancla->objeto = &lista->numeroElementos;
}

int Lista_InsertarDespues(ListaEnlazada *lista, void *objeto, ElementoLista *elemento){
	if (lista->ancla == NULL) {
		return FALSE;
	}
	ElementoLista* elem = Lista_Buscar(lista, elemento->objeto);
	if (elem == NULL) {
		return FALSE;
	}
	elemento->anterior = elem;
	elemento->siguietne = elem->siguiente;
	elem-siguiente->anterior = elemento;
	elem-siguiente = elemento;
	lista->numeroElementos += 1;
	lista->ancla->objeto = &lista->numeroElementos;
	return TRUE;	
}

int Lista_InsertarAntes(ListaEnlazada *lista, void *objeto, ElementoLista *elemento){
	if (lista->ancla == NULL) {
		return FALSE;
	}
	ElementoLista* elem = Lista_Buscar(lista, elemento->objeto);
	if (elem == NULL) {
		return FALSE;
	}
	elemento->anterior = elem->anterior;
	elemento->siguietne = elem;
	elem->anterior->siguiente = elemento;
	elem->anterior = elemento;
	lista->numeroElementos += 1;
	lista->ancla->objeto = &lista->numeroElementos;
	return TRUE;

}

ElementoLista *Lista_Siguiente(ListaEnlazada *lista, ElementoLista *elemento){	
	ElementoLista* elem = Lista_Buscar(lista, elemento->objeto);
	if (elem == NULL) {
		return NULL;
	}
	return elem->siguiente;
}

ElementoLista *Lista_Anterior(ListaEnlazada *lista, ElementoLista *elemento){
	ElementoLista* elem = Lista_Buscar(lista, elemento->objeto);
	if (elem == NULL) {
		return NULL;
	}
	return elem->anterior;
}
