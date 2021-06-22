#include "servidor_funciones.h"

int iniciar_socket_puerto(int puerto){
	int crear_sokcet,opt=0;

	//CREACION DELSOCKET
	if ((crear_sokcet=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		perror("crear_sokcet");
		exit(EXIT_FAILURE);
	}else{
		printf("Socket creado\n");
	}
	//
	if (setsockopt(crear_sokcet,SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	servidor.sin_family= AF_INET;
	servidor.sin_addr.s_addr= INADDR_ANY;
	servidor.sin_port = htons(puerto);

	if (bind(crear_sokcet,(struct sockaddr *)&servidor,sizeof(servidor))<0){
		perror("bind failed");
		exit(EXIT_FAILURE);
	}

	if (listen(crear_sokcet,3)<0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}else{
		printf("Servidor al eschuca en el puerto %d\n",ntohs(servidor.sin_port) );
	}
	return crear_sokcet;
}
int aceptar(int crear_sokcet){
	int socketlen=sizeof(servidor);
	int aceptado;
	if ((aceptado=accept(crear_sokcet,(struct sockaddr*)&servidor,(socklen_t*)&socketlen))<0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}
	return aceptado;
}

/*void leer(int aceptado,int n_caracteres){
	char buffer[n_caracteres];
	int valread;
	valread =read(aceptado,buffer,n_caracteres);
	printf("%s\n",buffer );
}*/
char* leer(int aceptado,int tam){
	char buffer[tam],*buffer1;
	bzero((char*)&buffer,sizeof(buffer));
	read(aceptado,buffer,tam);
	printf("-->>>%s\n",buffer);
	buffer1=buffer;
	return buffer1;
}

void enviar(int aceptado,char *texto){
	printf("ffgfdfrgth\n");
	send(aceptado, texto , strlen(texto) , 0 );
    printf("Hello message sent\n");
}

char * hacer_suma(char *num1, char *num2){
	int n1=0,n2=0,j=0,c=0,i=0,s=0,rc=0,rc2;
	char car;
	char *r,*respaldo;
	while(num1[n1]!='\0'){
		n1++;
	}
	
	while(num2[n2]!='\0'){
		n2++;
	}
	if (n1>=n2)
	{
		r=(char *)malloc(n1);
		rc=n1;
		rc2=rc;
		r[rc2]='\0';
		rc2--;
		n1--;
		n2--;
	}else{
		r=(char *)malloc(n2);
		rc=n2;
		rc2=rc;
		r[rc2]='\0';
		rc2--;
		n2--;
		n1--;
	}
	while(n2>=0 && n1 >=0){
		i=num1[n1]-48;
		j=num2[n2]-48;
		if ((s=i+j+c)>9)
		{
			c=1;
			car=(s-10)+48;
			r[rc2]=car;
			n2--;
			n1--;
			rc2--;
		}else{
			c=0;
			car=s+48;
			r[rc2]=car;
			//printf("%c\n", r[rc2]);
			n2--;
			n1--;
			rc2--;
		}
	}

	if (n1>=0){
		while(n1>=0){
			i=num1[n1]-48;
			if ((s=i+c)>9)
			{
				c=1;
				car=(s-10)+48;
				r[n1]=car;
				n1--;
			}else{
				c=0;
				car=s+48;
				r[n1]=car;
				n1--;
			}
		}
	}else{
		while(n2>=0){
			j=num2[n2]-48;
			if ((s=j+c)>9)
			{
				c=1;
				car=(s-10)+48;
				r[n2]=car;
				n2--;
			}else{
				c=0;
				car=s+48;
				r[n2]=car;
				n2--;
			}
		}
	}
	free(num1);
	free(num2);
	if (c==1)
	{
		respaldo=(char*)malloc(rc);
		for (i= 0; i <=rc; ++i)
		{
			respaldo[i]=r[i];
		}
		free(r);
		r=(char*)malloc(sizeof(char)*(rc+1));
		r[0]=c+48;
		for (i = 0; i <= rc; ++i)
		{
			r[i+1]=respaldo[i];
		}
		free(respaldo);
	}
	//printf("%s\n",r);
	return r;
	//free(r);
}