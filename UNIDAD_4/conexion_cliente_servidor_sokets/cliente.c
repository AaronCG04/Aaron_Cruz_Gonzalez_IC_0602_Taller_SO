#include "cliente_funciones.h"
//#include "suma_n_numeros_funciones.h"

int main(int argc, char const *argv[])
{
    int puerto=atoi(argv[2]),cliente_conexion;
    char *num,numero[10];
    char *ip=(char *)argv[1];
    cliente_conexion=conectar_cliente_servidor(ip,puerto);
    num=optener_numero();
    enviar_datos(cliente_conexion, num);
    fflush(stdin);
    num=optener_numero();
    enviar_datos(cliente_conexion, num);
    recibir_datos(cliente_conexion);
    close(cliente_conexion);
    return 0;
}