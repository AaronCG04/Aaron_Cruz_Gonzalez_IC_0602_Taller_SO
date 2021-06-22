#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

struct sockaddr_in servidor;

int iniciar_socket_puerto(int puerto);
int aceptar(int crear_sokcet);

/*void leer(int aceptado,int n_caracteres){
	char buffer[n_caracteres];
	int valread;
	valread =read(aceptado,buffer,n_caracteres);
	printf("%s\n",buffer );
}*/
char * leer(int aceptado,int tam);
void enviar(int aceptado,char *texto);
char *hacer_suma(char *num1, char *num2);