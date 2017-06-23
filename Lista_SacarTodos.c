#include <stdio.h>
#include "miLista.h"

void Lista_SacarTodos(ListaEnlazada *lista){
	lista->ancla.siguiente = NULL;
	lista->numeroElementos = 0;
	lista->ancla.objeto = &lista->numeroElementos;
}

