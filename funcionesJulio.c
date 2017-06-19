extern int Lista_Vacia(ListaEnlazada *lista){
	if(lista->numeroElementos==0){
		return TRUE;
	}else{
		return FALSE;
	}
}
extern int Lista_Conteo(ListaEnlazada *lista){
	int contador;
	contador =lista->numeroElementos;
	return contador;

}


extern int Lista_InsertarFin(ListaEnlazada *lista, void *objeto){
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
extern int Lista_InsertarInicio(ListaEnlazada *lista, void *objeto){
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
		elemento->siguiente = lista->ancla->siguiente;
		elemento->anterior = lista->ancla;
		lista->ancla->siguiente = elemento;
		lista->ancla->numeroElementos++;	
		return TRUE;
	}
	return FALSE;
}


extern ElementoLista *Lista_Primero(ListaEnlazada *lista){
	if(lista->numeroElementos==0){
		return NULL;
	}else{
		ElementoLista *elemento;
		elemento=lista->ancla->siguiente;
		return elemento;
	}
}


extern ElementoLista *Lista_Ultimo(ListaEnlazada *lista){}
	if(lista->numeroElementos==0){
		return NULL;
	}else{
		ElementoLista *elemento;
		elemento=lista->ancla->anterior;
		return elemento;
	}
}






