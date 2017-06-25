#include <stdio.h>
#include <stdlib.h>
#include "miLista.h"

extern ElementoLista *Lista_Primero(ListaEnlazada *lista){
	if(lista->numeroElementos==0){
		printf("Holanulo");
		return NULL;
	}else{
		ElementoLista *elemento = (ElementoLista*) malloc(sizeof(ElementoLista));
		elemento=(lista->ancla).siguiente;
		printf("Holamucho");
		return elemento;
	}
}
