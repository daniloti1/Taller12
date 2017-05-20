#include <stdio.h>

int main(int argc, char **argv){
	printf("Cifrado ciclico\n");
	printf("Ingrese el mensaje a cifrar: \n");
	char cadena[10]="mensaje";
	scanf("%s", cadena);
	printf("Ingrese la clave numerica: \n");
	int i=0;
	scanf("%d", &i);
	
	printf("Mensaje cifrado: %s \n", cadena);

	return 0;
}
