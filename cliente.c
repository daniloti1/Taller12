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
#define MAXSLEEP 64
//  ./cliente 127.0.0.1 45343 /home/eduardo/imagen.png imagen.png
int main( int argc, char *argv[]) {

	printf("argv[3]: %s\n",argv[3]); 
	int archivo;

	printf("antes del socket\n");
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
	//archivo = fopen(argv[3],"rb");
	
	//printf("Abrio el archivo\n"); 
	//Direccion del servidor
	struct sockaddr_in direccion_cliente;

	memset(&direccion_cliente, 0, sizeof(direccion_cliente));	//ponemos en 0 la estructura direccion_servidor

	//llenamos los campos
	direccion_cliente.sin_family = AF_INET;		//IPv4
	direccion_cliente.sin_port = htons(puerto);		//Convertimos el numero de puerto al endianness de la red
	direccion_cliente.sin_addr.s_addr = inet_addr(argv[1]) ;	//Nos tratamos de conectar a esta direccion

	//AF_INET + SOCK_STREAM = TCP

	socklen_t a_len = sizeof(direccion_cliente); 
	printf("antes del connect\n");

	if ((connect(sockfd,(struct sockaddr *) &direccion_cliente, a_len)) < 0) { 
		printf("falló conexión\n"); 
		exit(-1);
	} 

	char buffer[BUFLEN]={0};
	char *recibido=(char*) malloc(sizeof(char)*100);
	int envio = -1;
	char * ruta = argv[3];
	printf("%s\n",ruta);
	printf("antes del send\n");
	printf("size: %d\n",strlen(ruta));
	

	envio = send(sockfd,ruta,strlen(ruta),0);

	printf("%d\n",envio);
	/*
	printf("antes del recv\n");
	recv(sockfd, recibido , 100 , 0);	
	printf("recibido: %s\n",recibido);	
	printf("antes del while\n");
	while((recv(sockfd, buffer, BUFLEN, 0)) > 0){
		printf("%s",buffer);
		archivo = open(argv[4],O_WRONLY|O_CREAT);
		write(archivo,buffer,sizeof(char));
	}
	printf("sale del while\n");
	close(archivo);
	*/
	return 0; 
}



