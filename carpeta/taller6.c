#include <stdio.h>

void desglosar(char* fecha) {
	printf("Dia:%c%c\n",*(fecha+8),*(fecha+9));
	printf("Mes:%c%c\n",*(fecha+5),*(fecha+6));
	printf("Año:%c%c%c%c\n",*(fecha),*(fecha+1),*(fecha+2),*(fecha+3));
}

int* busqueda(int* arreglo, int buscar, int tamano) {
	for (int i=0;i<tamano;i++) {
		if (buscar==*(arreglo+i)) {
			printf("Direccion del elemento %x\n",(arreglo+i));
			return (arreglo+i);
		}
	}
	return 0;
}

void intercambiar(int* a, int* b){
	int* temp;
	temp = a;
	a = b;
	b = temp;
	printf("%d\n",a);
	printf("%d\n",b);
}

int main(){
	desglosar("2017-06-06");
	int arreglo[5]={1,4,58,36,2};
	int* arr=&arreglo[0];	
	busqueda(arr,2,5);
	int a=2;int b=3;
	intercambiar(a,b);
	return 0;
}


