#include "cliente_funciones.h"
//#include "suma_n_numeros_funciones.h"

int main(int argc, char const *argv[])
{
    if (argc ==3)
    {
        int puerto=atoi(argv[2]),cliente_conexion;
        char *num;
        char *ip=(char *)argv[1];
        cliente_conexion=conectar_cliente_servidor(ip,puerto);
        printf("Ingrese el Primer Numero: ");
        num=optener_numero();
        enviar_datos(cliente_conexion, num);
        fflush(stdin);
        printf("Ingrese el Segundo Numero: ");
        num=optener_numero();
        enviar_datos(cliente_conexion, num);
        recibir_datos(cliente_conexion);
        close(cliente_conexion);
    }else{
        printf("Faltan Parametros <host(ip)> <puerto>\n");
    }
    return 0;
}