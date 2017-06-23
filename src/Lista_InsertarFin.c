#include <stdio.h>
#include "miLista.h"

int Lista_InsertarFin(ListaEnlazada *lista, void *objeto){
	ElementoLista *elemento;	
	if(lista->numeroElementos==0){	
		elemento->objeto=objeto;
		elemento->siguiente = lista->ancla.objeto;
		elemento->anterior = lista->ancla.objeto;
		lista->ancla.siguiente = elemento;
		lista->ancla.anterior = elemento;
		lista->numeroElementos++;
		return TRUE;
	}else{
		elemento->objeto=objeto;
		elemento->siguiente = lista->ancla.objeto;
		elemento->anterior = lista->ancla.anterior;
		lista->ancla.anterior = elemento;
		lista->numeroElementos++;	
		return TRUE;
	}
	return FALSE;
	
}

