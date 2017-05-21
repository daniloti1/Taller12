
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

char* cifrar(char cadena[30], int n);
int buscar(char a, char texto[30]);
int verificar(char letra);

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
		return 0;
        }
	printf("Cifrado ciclico\n");
	printf("Ingrese el mensaje a cifrar: \n");
	char cadenaCode[30];
	scanf("%[a-z A-Z0-9.,@_|°!#$%&\"\\/()={}]", cadenaCode);
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

int verificar(char letra){
	if (letra>='a' && letra<='z'){
		return 0;
	}
	if (letra>='A' && letra<='Z'){
		return 1;
	}
	return -1;
}
