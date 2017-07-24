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
	FILE *archivo;
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

	memset(&direccion_servidor, 0, sizeof(direccion_servidor));	//ponemos en 0 la estructura direccion_servidor

	//llenamos los campos
	direccion_servidor.sin_family = AF_INET;		//IPv4
	direccion_servidor.sin_port = htons(puerto);		//Convertimos el numero de puerto al endianness de la red
	direccion_servidor.sin_addr.s_addr = inet_addr(argv[1]) ;	//Nos vinculamos a la interface localhost o podemos usar INADDR_ANY para ligarnos A TODAS las interfaces

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bind(sockfd, (struct sockaddr *) &direccion_servidor, sizeof(direccion_servidor));

	listen(sockfd,QLEN);

	int acept_socket;
	struct sockaddr_in socket_cliente;
	
	while(1){
		int tam_socket=sizeof(socket_cliente);
		
		acept_socket = accept(sockfd, (struct sockaddr *) &socket_cliente,&tam_socket);
		
		socket_cliente.sin_family = AF_INET;
		socket_cliente.sin_port = htons(puerto);
		
		char buffer[1];
		int recibido = -1;
		archivo = fopen("kurt","wb");
		while((recibido = recv(sockfd, buffer, BUFFSIZE, 0)) > 0){
			printf("%s",buffer);
			fwrite(buffer,sizeof(char),1,archivo);
		}

		fclose(archivo);
		
		
		
	}
	

	
	exit( 1); 
}


