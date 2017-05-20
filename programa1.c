#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* cifrar(char cadena[30], int n);
int buscar(char a, char texto[30]);

int main(int argc, char **argv){
	printf("Cifrado ciclico\n");
	printf("Ingrese el mensaje a cifrar: \n");
	char cadenaCode[30]="mensaje";
	scanf("%s", cadenaCode);
	printf("Ingrese la clave numerica: \n");
	int num=0;
	scanf("%d", &num);
	
	printf("Mensaje cifrado: %s \n", cifrar(cadenaCode,num));

	return 0;
}

char* cifrar(char cadena[30], int n){
	char* cifrado=malloc(sizeof(char)*30);
        char alfabeto[26]="abcdefghijklmnopqrstuvwxyz";
        int a=(int)strlen(cadena);

	for (int i=0;a;i++){
		int b=buscar(cadena[i],alfabeto);
		b=(b+n)%26;
                cifrado[i]=alfabeto[b];
	}
	return cifrado;
}

int buscar(char a, char texto[30]){
	int indice=-1;
	for (int i=0;strlen(texto);i++){
		if (a==texto[i]){
			indice=i;
			break;
		}
	}
	return indice;
}
