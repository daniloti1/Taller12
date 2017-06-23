#include <stdio.h>
#include "miLista.h"

int Lista_InsertarFin(ListaEnlazada *lista, void *objeto){
	ElementoLista *elemento;	
	if(lista->numeroElementos==0){	
		elemento->objeto=objeto;
		elemento->siguiente = lista->ancla
		elemento->anterior = lista->ancla;
		lista->ancla->siguiente = elemento;
		lista->ancla->anterior = elemento;
		lista->ancla->numeroElementos++;
		return TRUE;
	}else{
		elemento->objeto=objeto;
		elemento->siguiente = lista->ancla
		elemento->anterior = lista->anterior;
		lista->ancla->anterior = elemento;
		lista->ancla->numeroElementos++;	
		return TRUE;
	}
	return FALSE;
	
}

