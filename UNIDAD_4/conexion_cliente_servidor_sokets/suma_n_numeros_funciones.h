#include <stdlib.h>
#include <stdio.h>
int total_ca=10,i=0;
int optener_total_cadena(){
	return i;
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

/*void hacer_suma(char *num1, char *num2){
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
		respaldo=(char*)malloc(sizeof(char)*1000);
		for (i= 0; i <=rc; ++i)
		{
			respaldo[i]=r[i];
		}
		free(r);
		r=(char*)malloc(sizeof(char)*(total_ca+1));
		r[0]=c+48;
		for (i = 0; i <= rc; ++i)
		{
			r[i+1]=respaldo[i];
		}
		free(respaldo);
	}
	printf("%s\n",r);
	free(r);
}
int main(int argc, char const *argv[])
{
	char *num1,*num2;
	num1=optener_numero();
	num2=optener_numero();

	printf("%s\n",num1);
	printf("%s\n",num2);
	return 0;
}*/