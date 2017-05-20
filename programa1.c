#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* cifrar(char cadena[30], int n);
int buscar(char a, char texto[30]);

int main(int argc, char **argv){
	printf("Cifrado ciclico\n");
	printf("Ingrese el mensaje a cifrar: \n");
	char cadenaCode[30];
	scanf("%[a-z 0-9!#$%&\"\\/()={}]", cadenaCode);
	printf("Ingrese la clave numerica: \n");
	int num;
	scanf("%d", &num);
	char* mensajeCifrado;
	mensajeCifrado=cifrar(cadenaCode,num);
	printf("Mensaje cifrado: %s \n", mensajeCifrado);

	return 0;
}

char* cifrar(char cadena[30], int n){
	char* cifradoFinal=malloc(sizeof(char)*30);
        char cifrado[30];
	strcpy(cifrado,cadena);
	char alfabeto[26]="abcdefghijklmnopqrstuvwxyz";
        int a=(int)strlen(cadena);
	for (int i=0;i<a;i++){
		int b=buscar(cadena[i],alfabeto);
		if (b!=-1) {
			b=(b+n)%26;
                	cifrado[i]=alfabeto[b];
		}
	}
	strcpy(cifradoFinal,cifrado);
	return (char *)cifradoFinal;
}

int buscar(char a, char texto[30]){
	int indice=-1;
	for (int i=0;i<strlen(texto);i++){
		if (a==texto[i]){
			indice=i;
			break;
		}
	}
	if (indice>25){
		indice=-1;
	}
	return indice;
}
