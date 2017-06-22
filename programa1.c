
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define TAMANO 1024

char* cifrar(char cadena[TAMANO], int n);
int buscar(char a, char texto[TAMANO]);
int verificar(char letra);
void morse(char codigo[TAMANO]);

int main(int argc, char **argv){
	char* porConsola;
	porConsola=(char *)argv[2];
	char* otro1=argv[1];
	int otro=0;
	if (argc==3){
		for (int j=0;j<strlen(otro1);j++){
                	otro+=(otro1[j]-'0')*(pow(10,(strlen(otro1)-1-j)));
        	}
                char* retorno=cifrar(porConsola,otro);
		printf("Mensaje cifrado: %s \n",retorno);
		printf("Mensaje cifrado en Morse: ");
		morse(retorno);
		return 0;
        }
	printf("Cifrado ciclico\n");
	printf("Ingrese el mensaje a cifrar: \n");
	char cadenaCode[TAMANO];
	scanf("%[a-z A-Z0-9.,@_|°!#$%&\"\\/()*={}]", cadenaCode);
	printf("Ingrese la clave numerica: \n");
	int num;
	scanf("%d", &num);
	char* mensajeCifrado;
	mensajeCifrado=cifrar(cadenaCode,num);
	printf("Mensaje cifrado: %s \n", mensajeCifrado);

	printf("Mensaje cifrado en Morse: ");
	morse(mensajeCifrado);

	return 0;
}

char* cifrar(char cadena[TAMANO], int n){
	char* cifradoFinal=malloc(sizeof(char)*TAMANO);
        char cifrado[TAMANO];
	strcpy(cifrado,cadena);
	char alfabeto[26]="abcdefghijklmnopqrstuvwxyz";
	char alfabetoM[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int a=(int)strlen(cadena);
	for (int i=0;i<a;i++){
		if (verificar(cifrado[i])==0){
			int b=buscar(cifrado[i],alfabeto);
			b=(b+n)%26;
			cifrado[i]=alfabeto[b];
		}
		else if (verificar(cifrado[i])==1){
			int b=buscar(cifrado[i],alfabetoM);
			b=(b+n)%26;
			cifrado[i]=alfabetoM[b];
		}
	}
	strcpy(cifradoFinal,cifrado);
	return (char *)cifradoFinal;
}

int buscar(char a, char texto[TAMANO]){
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

int verificar(char letra){
	if (letra>='a' && letra<='z'){
		return 0;
	}
	if (letra>='A' && letra<='Z'){
		return 1;
	}
	return -1;
}
void morse(char mensaje[TAMANO]){
	char alfabetoMorse[36][6]={".-","_...","_._.","_..",".",".._.","__.","....","..",".___","_._","._..","__","_.","___",".__.","__._","._.","...","_",".._","..._",".__","_.._","_.__","__..","_____",".____","..___","...__","...._",".....","_....","__...","___..","____."};
	char auxiliar[TAMANO]={0};
	for (int i=0;i<strlen(mensaje);i++){
		strncpy(auxiliar,mensaje,TAMANO);
		int indice=(int)auxiliar[i];
		if (indice>=65 && indice<=90){
			indice-=65;
		}
		else if (indice>=97 && indice<=122){
			indice-=97;
		}
		else{
			indice-=22;
		}
		if (mensaje[i]==32){
			printf("/ ");
		}
		else {
			printf("%s ",alfabetoMorse[indice]);
		}
	}
	printf("\n");
}
