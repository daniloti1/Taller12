#include <stdio.h>

char cifrar(char cadena[30], int n);
int buscar(char a, cahr texto[30]);

int main(int argc, char **argv){
	printf("Cifrado ciclico\n");
	printf("Ingrese el mensaje a cifrar: \n");
	char cadena[30]="mensaje";
	scanf("%s", cadena);
	printf("Ingrese la clave numerica: \n");
	int num=0;
	scanf("%d", &num);
	
	printf("Mensaje cifrado: %s \n", cifrar(cadena));

	return 0;
}

char cifrar(char cadena[30], int n){
	char cifrado[30]="";
        char alfabeto[26]="abcdefghijklmnopqrstuvwxyz";
        for (int i=0;strlen(cadena);i++){
                cifrado[i]=alfabeto[

	return cifrado;
}

int buscar(char a, char tetxo[30]){
	int indice=-1;
	for (int i=0;strlen(texto);i++){
		if (a==texto[i]){
			indice=i;
			break;
		}
	}
	return indice;
}
