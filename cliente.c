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
#define MAXSLEEP 64

int main( int argc, char *argv[]) { 

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0) {
        	printf("ERROR opening socket");
	}
	if(argc <  5){
		printf("Uso: ./cliente <ip> <puerto> <archivo>\n");
		exit(-1);
	}

	if(argc != 5){
		printf( "por favor especificar un numero de puerto\n");
	}

	int puerto = atoi(argv[2]);


	//Direccion del servidor
	struct sockaddr_in direccion_cliente;

	memset(&direccion_cliente, 0, sizeof(direccion_cliente));	//ponemos en 0 la estructura direccion_servidor

	//llenamos los campos
	direccion_cliente.sin_family = AF_INET;		//IPv4
	direccion_cliente.sin_port = htons(puerto);		//Convertimos el numero de puerto al endianness de la red
	direccion_cliente.sin_addr.s_addr = inet_addr(argv[1]) ;	//Nos tratamos de conectar a esta direccion

	//AF_INET + SOCK_STREAM = TCP

	socklen_t a_len = sizeof(direccion_cliente); 

	if ((sockfd = connect(sockfd,(struct sockaddr *) &direccion_cliente, a_len)) < 0) { 
		printf("falló conexión\n"); 
		exit(-1);
	} 

	char* buf = (char*) malloc(sizeof(char)*100);
	buf = argv[3];

	send(sockfd,buf,strlen(buf),0);
	sleep(1);

	//En este punto ya tenemos una conexión válida
	//print_uptime(sockfd, argv[3]);

	return 0; 
}


