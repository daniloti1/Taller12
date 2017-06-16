
#define TAMANO 7
#define edadMin 10 
#define edadMax 65

#define pesoMin 50.0f
#define pesoMax 100.0f

char *nombres[TAMANO] = {"Jose Perez","Maria Garcia","Ana Andrade", "Julio Como", "Julia Rodriguez", "Antonio Aguilar", "Diana Marcel" };


typedef struct personaTDA{
	int edad;
	int peso;
	char *nombre;
	struct listaHijosTDA *hijos;
}Persona;

typedef struct listaHijosTDA{
	Persona *per;
	struct listaHijosTDA *siguiente;
}ListaHijos;




Persona *crearPersona(char *nombre, int edad, int peso){
	Persona *nuevo = (Persona*) malloc(sizeof(Persona*));//No se habia inicializado correctamente el puntero y el error era Segmentation fault

	nuevo->nombre = nombre;
	nuevo->edad = edad;
	nuevo->peso = peso;

	

	nuevo->hijos = (ListaHijos*) malloc(sizeof(ListaHijos*));//No se habia inicializado correctamente el puntero y el error era Segmentation fault

	return nuevo;					
}


int anadirHijo(Persona *padre, Persona *hijo){
	
	ListaHijos *lista_hijos = (ListaHijos*)malloc(sizeof(ListaHijos));//No se habia inicializado correctamente el puntero previa la asignacion y el error era Segmentation fault
	lista_hijos = padre->hijos;


	if(lista_hijos == NULL){
		ListaHijos *lista = (ListaHijos *)malloc(sizeof(ListaHijos));
		if(lista == NULL){
			free(lista);
			free(lista_hijos);
			return -1;		
		}
		lista->per = hijo;
		lista->siguiente = NULL;
		padre->hijos = lista;
		//Se libera ese espacio con free
		free(lista);
		free(lista_hijos);
		return 0;
	}

	else{
		while(lista_hijos != NULL){
		
			if(lista_hijos->siguiente == NULL){
				break;
			}
			lista_hijos = lista_hijos->siguiente;
		}

					
		ListaHijos *nuevo = (ListaHijos *)malloc(sizeof(ListaHijos));
		if(nuevo == NULL){
			free(lista_hijos);
			return -1;		
		}
		nuevo->per = hijo;
		nuevo->siguiente = NULL;//El siguiente se le asignaba otra vez la lista al momento de imprimir se creaba un bucle
		lista_hijos->siguiente = nuevo;
		//Faltaba la asignacion nuevamente a padre la asignacion de la lista_hijos
		padre->hijos = lista_hijos;
		
		return 0;	
		
	}
	free(lista_hijos);
	return -1;
}

void mostrarInfoPersona(Persona *persona){
	if(persona != NULL){
		printf("Nombre: %s\nPeso: %d kg\nEdad: %d\n",persona->nombre, persona->peso, persona->edad);
		if(persona->hijos->siguiente == NULL){//Se valida que el primer hijo no sea null
			printf("Hijos: esta persona no tiene hijos\n");
			return;
		}
		else{
			ListaHijos *lista_hijos = persona->hijos;
			printf("Los hijos de %s son:\n", persona->nombre);
			while(lista_hijos != NULL){//Se agrego un condicional para validar que la persona no sea Null e imprimir caso contrario se modifica la lista para su siguiente hijo
				if(lista_hijos->per != NULL){	 
					printf("- %s\n", lista_hijos->per->nombre);
				}	
				lista_hijos = lista_hijos->siguiente;
			}
		}
	}
}


int main(void){

	Persona *listaPersona[TAMANO]={0};

	int i = 0;

	for(i = 0; i < TAMANO; i++){//lanzaba el stackkmashing y no imprimia la ultima persona		

		int edad = edadMin + rand() / (RAND_MAX / (edadMax - edadMin + 1) + 1);
		int peso = pesoMin + rand() / (RAND_MAX / (pesoMax - pesoMin + 1) + 1);

		listaPersona[i] = crearPersona(nombres[i],  edad, peso);//Faltaba la asignacion a la listaPersona
		

	}

	anadirHijo(listaPersona[0], listaPersona[1]);
	anadirHijo(listaPersona[3], listaPersona[2]);
	anadirHijo(listaPersona[3], listaPersona[6]);
	anadirHijo(listaPersona[4], listaPersona[5]);

	

	
	for(i = 0; i < TAMANO; i++){			

		mostrarInfoPersona(listaPersona[i]);
		printf("\n");

	}

	

}





