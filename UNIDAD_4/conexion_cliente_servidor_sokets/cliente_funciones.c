#include "cliente_funciones.h"

int total_ca=10,i=0;
int optener_total_cadena(){
	return i;
}
int conectar_cliente_servidor(char *ip,int puerto){

	struct sockaddr_in cliente;
	int conexion=0;
	if ((conexion = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        //return -1;
    }
   
    cliente.sin_family = AF_INET;
    cliente.sin_port = htons(puerto);
    //estableciendo el destino de la coneccion
    if(inet_pton(AF_INET,ip, &cliente.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        //return -1;
    }
   
    if (connect(conexion, (struct sockaddr *)&cliente, sizeof(cliente)) < 0)
    {
        printf("\nConnection Failed \n");
        exit(EXIT_FAILURE);
        //return -1;
    }
    return conexion;

}

void enviar_datos(int conexion, char *numero){
	send(conexion, numero, strlen(numero) , 0 );
}

///checar esta parte para ingresar el numero x de valores

void recibir_datos(int conexion){
	char buffer[1024];
	read( conexion , buffer, 1024);
	printf("Recibido %s\n",buffer);
}

char * optener_numero(){
	total_ca=10,i=0;
	int j,total_ca_an;
	char *str_d=(char *)malloc(sizeof(char)*total_ca);
	char *r;
	//char *str_c=(char *)malloc(sizeof(char)*total_ca);
	char ca;
	while(ca!='\n'){
		scanf("%c",&ca);
		
		if(i<total_ca){
			//printf("entro en el normal\n");
			str_d[i]=ca;
		}else{
			r=(char *)malloc(sizeof(char)*total_ca);
			for (j = 0; j <= total_ca; ++j)
			{
				r[j]=str_d[j];
			}
			//printf("hiso repaldo\n");
			free(str_d);		
			total_ca_an=total_ca;
			total_ca=total_ca+10;
			str_d=(char *)malloc(sizeof(char)*total_ca);
			for (j = 0; j <= total_ca_an; ++j)
			{
				str_d[j]=r[j];
			}
			//printf("copia respaldo a orignal\n");
			free(r);
			str_d[i]=ca;
		}
		i++;
	}
	j=0;
	str_d[i-1]='\0';
	return str_d;
}