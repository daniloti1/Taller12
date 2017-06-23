#include <stdio.h>
#include "miLista.h"


int Lista_Vacia(ListaEnlazada *lista){
	if (lista->numeroElementos == 0) {
		return TRUE;
	}
	return FALSE;
}
