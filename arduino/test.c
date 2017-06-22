#include <stdio.h>    // Standard input/output definitions
#include <stdlib.h>
#include <string.h>   // String function definitions
#include <unistd.h>   // para usleep()
#include <getopt.h>
#include <math.h>

#include "arduino-serial-lib.h"

float calculateSD(float data[]);

void error(char* msg)
{
    fprintf(stderr, "%s\n",msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	int fd = -1;
	int baudrate = 9600;  // default

	fd = serialport_init("/dev/ttyACM0", baudrate);
	char * archivo = "/dev/ttyACM0";
	

	if( fd==-1 )
	{
		error("couldn't open port");
		return -1;
	}

	while(1) {

		char com = 't';
	
		write(fd, &com, 1);
	
		int* temperatura;

		read(fd,temperatura,sizeof(int));
		printf("Temperatura: %d\n",*temperatura);
		usleep(5000000);

	}
	close( fd );
	return 0;	
}

/* Ejemplo para calcular desviacion estandar y media */
float calculateSD(float data[])
{
    float sum = 0.0, mean, standardDeviation = 0.0;

    int i;

    for(i = 0; i < 10; ++i)
    {
        sum += data[i];
    }

    mean = sum/10;

    for(i = 0; i < 10; ++i)
        standardDeviation += pow(data[i] - mean, 2);

    return sqrt(standardDeviation / 10);
}

