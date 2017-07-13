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

#define BUFLEN 128 
#define QLEN 10 

#ifndef HOST_NAME_MAX 
#define HOST_NAME_MAX 256 
#endif	


int main( int argc, char *argv[]) { 

	if(argc == 1){
		printf("Uso: ./servidor <IP> <numero de puerto>\n");
		exit(-1);
	}

	if(argc != 2){
		printf( "por favor especificar un numero de puerto\n");
	}

	int puerto = atoi(argv[2]);

	int sockfd;

	//Direccion del servidor
	struct sockaddr_in direccion_servidor;

	memset(&direccion_servidor, 0, sizeof(direccion_servidor));	//ponemos en 0 la estructura direccion_servidor

	//llenamos los campos
	direccion_servidor.sin_family = AF_INET;		//IPv4
	direccion_servidor.sin_port = htons(puerto);		//Convertimos el numero de puerto al endianness de la red
	direccion_servidor.sin_addr.s_addr = inet_addr("127.0.0.1") ;	//Nos vinculamos a la interface localhost o podemos usar INADDR_ANY para ligarnos A TODAS las interfaces

	
	int fd = socket(direccion_servidor.sin_family, sizeof(direccion_servidor), 0);

	bind(fd, (struct sockaddr *)&direccion_servidor, sizeof(direccion_servidor));

	listen(fd, 1000);
		

	while(1){
		int solicitud;
		solicitud = accept(sockfd, (struct sockaddr *)&direccion_servidor, sizeof(direccion_servidor));
		//serve(sockfd);
		//TODO servimos
	}
	

	
	exit( 1); 
}

