#include <sys/types.h>          /* some systems still require this */
#include <sys/stat.h>
#include <stdio.h>              /* for convenience */
#include <stdlib.h>             /* for convenience */
#include <stddef.h>             /* for offsetof */
#include <string.h>             /* for convenience */
#include <unistd.h>             /* for convenience */
#include <signal.h>             /* for SIG_ERR */ 
#include <netdb.h> 
#include <errno.h> 
#include <syslog.h> 
#include <sys/socket.h> 
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/resource.h>

#define BUFFSIZE 1
#define BUFLEN 128 
#define QLEN 10 

#ifndef HOST_NAME_MAX 
#define HOST_NAME_MAX 256 
#endif	
//    ./servirdor 127.0.0.1 45343
int main( int argc, char *argv[]) { 
	int sockfd, n;
	char *host; 
	int archivo;
	if(argc < 2){
		printf("Uso: ./servidor <numero de puerto>\n");
		exit(-1);
	}

	if(argc != 3){
		printf( "por favor especificar un numero de puerto\n");
	}

	int puerto = atoi(argv[2]);

	if (( n = sysconf(_SC_HOST_NAME_MAX)) < 0) 		
		n = HOST_NAME_MAX; /* best guess */ 
	if ((host = malloc(n)) == NULL) 
		printf(" malloc error"); 
	if (gethostname( host, n) < 0) 		//Obtenemos nombre del host
		printf(" gethostname error"); 
	
	printf("Nombre del host: %s\n", host);	//Mostramos nuestro nombre

	

	//Direccion del servidor
	struct sockaddr_in direccion_servidor;
	printf("antes del memeset\n");
	memset(&direccion_servidor, 0, sizeof(direccion_servidor));	//ponemos en 0 la estructura direccion_servidor

	//llenamos los campos
	direccion_servidor.sin_family = AF_INET;		//IPv4
	direccion_servidor.sin_port = htons(puerto);		//Convertimos el numero de puerto al endianness de la red
	printf("antes de la direccion ip\n");
	direccion_servidor.sin_addr.s_addr = inet_addr(argv[1]) ;	//Nos vinculamos a la interface localhost o podemos usar INADDR_ANY para ligarnos A TODAS las interfaces
	printf("antes del socket\n");
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	printf("antes del bind\n");
	bind(sockfd, (struct sockaddr *) &direccion_servidor, sizeof(direccion_servidor));
	printf("antes del listen\n");
	listen(sockfd,QLEN);

	
	//char buf2[10000] = {0};
	
	//char ruta[100] = {0};

	//socklen_t a_len = sizeof(direccion_servidor); 
	
	//int tam_socket;
	int acept_socket;

	socklen_t tam_socket=sizeof(direccion_servidor);
	
	printf("antes del acept\n");
	acept_socket = accept(sockfd, (struct sockaddr *) &direccion_servidor,&tam_socket);
	if (acept_socket == -1) {
		printf("accept = -1");
	}
	char buffer[BUFLEN];
	char ruta[BUFLEN] = {0};
	printf("antes del recv\n");
	int m = recv(sockfd, ruta, BUFLEN, 0);
	printf("%d\n",m);
	printf("ruta: %s\n", ruta);
	puts(ruta);
	
	printf("antes del while(1)\n");
	while(1){
		printf("antes del acept\n");
		acept_socket = accept(sockfd, (struct sockaddr *) &direccion_servidor,&tam_socket);
		if (acept_socket == -1) {
			printf("accept = -1");
		}
		char buffer[BUFLEN];
		char ruta[BUFLEN] = {0};
		printf("antes del recv\n");
		int m = recv(acept_socket, ruta, BUFLEN, 0);
		printf("%d\n",m);
		printf("ruta: %s\n", ruta);
		puts(ruta);
		
		int recibido = -1;
		archivo = open(ruta,O_RDONLY);
		while((recibido = recv(sockfd, buffer, BUFLEN, 0)) > 0){
			printf("servidor recibe: %s\n\n",buffer);
			read(archivo,buffer,BUFLEN);
		}

		close(archivo);
		
		
		
	}
	

	
	exit( 1); 
}


