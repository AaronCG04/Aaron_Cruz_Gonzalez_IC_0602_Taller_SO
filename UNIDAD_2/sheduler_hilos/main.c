#include "scheduler.h"

void reproducir_musica(void*arg);
void abrir_youtube(void*arg);
void escribir_texto_word(void*arg);
void descargar_archivo(void*arg);
void subiendo_archivo(void*arg);
void compilando_programa(void*arg);
void ejecutando_programa(void*arg);
void usando_terminal(void*arg);

int main(int argc, char const *argv[]){

	process *p1 = crear_Proceso(1, UN_SEGUNDO, "Proceso_1", reproducir_musica, ACTIVO); 		//<--
	process *p2 = crear_Proceso(1, DOS_SEGUNDOS, "Proceso_1", abrir_youtube, NO_ACTIVO);
	process *p3 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_2", escribir_texto_word, ACTIVO); 	//<--
	process *p4 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_3", descargar_archivo, ACTIVO);   	//<--
	process *p5 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_4", subiendo_archivo, ACTIVO);		
	process *p6 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_5", compilando_programa, NO_ACTIVO);
	process *p7 = crear_Proceso(0, TRES_SEGUNDOS, "Proceso_6", ejecutando_programa, ACTIVO);	//<--	
	process *p8 = crear_Proceso(2, CUATRO_SEGUNDOS, "Proceso_7", usando_terminal, ACTIVO);		//<--
	process *p9 = crear_Proceso(5, CUATRO_SEGUNDOS, "Proceso_8", usando_terminal, NO_ACTIVO);	//<--

	array_procesos *array = crear_ArrayProcesos();

	agregar_Proceso(array, *p1);
	agregar_Proceso(array, *p2);
	agregar_Proceso(array, *p3);
	agregar_Proceso(array, *p4);
	agregar_Proceso(array, *p5);
	agregar_Proceso(array, *p6);
	agregar_Proceso(array, *p7);
	agregar_Proceso(array, *p8);
	agregar_Proceso(array, *p9);

	ejecutar_Procesos(array);

	free(array);
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	free(p7);
	free(p8);
	free(p9);

	return 0;
}
// PASMOS LA VERFIICACION DE ESTADO A CADA FUNCION QUE RECIBIRA EL HILO DE CADA PROCESO
void reproducir_musica(void*arg){
	process *p =arg;
	int j=0;
	if(p->estado == ACTIVO){
		printf("<=================================================================================>\n");
		printf("\tEl proceso de nombre [%s], con ID [%d], se encuentra realizando su [PROCESO], con un delay de [%d] segundo(s)\n", p->nombrePROCESO, p->id, p->delay);
		//_array[i].proceso.proceso_realizar();
		printf("Reproduciendo Música\n");
		//pthread_join(_array[i].proceso.hilo,NULL);
		printf("<=================================================================================>\n");
		for(j = 0; j < p->delay; j++){
			sleep(1); 
		}
		printf("El proceso [%s], con ID [%d] ah finalizado.\n", p->nombrePROCESO, p->id);
		
	}
	else if(p->estado == NO_ACTIVO){
		printf("<+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>\n");
		printf("\tEl proceso de nombre [%s], con ID [%d], SE ENCUENTRA EN ESTADO NO ACTIVO\n", p->nombrePROCESO, p->id);
		printf("<+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>\n");
	}
	else{
		;
	}
}

void abrir_youtube(void*arg){
	process *p =arg;
	if(p->estado == ACTIVO){
		printf("<=================================================================================>\n");
		printf("\tEl proceso de nombre [%s], con ID [%d], se encuentra realizando su [PROCESO], con un delay de [%d] segundo(s)\n", p->nombrePROCESO, p->id, p->delay);
		//_array[i].proceso.proceso_realizar();
		printf("Usando Youtube\n");
		//pthread_join(_array[i].proceso.hilo,NULL);
		printf("<=================================================================================>\n");
		for(int j = 0; j < p->delay; j++){
			sleep(1); 
		}
		printf("El proceso [%s], con ID [%d] ah finalizado.\n", p->nombrePROCESO, p->id);
	}
	else if(p->estado == NO_ACTIVO){
		printf("<+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>\n");
		printf("\tEl proceso de nombre [%s], con ID [%d], SE ENCUENTRA EN ESTADO NO ACTIVO\n", p->nombrePROCESO, p->id);
		printf("<+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>\n");
	}
	else{
		;
	}
}

void escribir_texto_word(void*arg){
	process *p =arg;
	if(p->estado == ACTIVO){
		printf("<=================================================================================>\n");
		printf("\tEl proceso de nombre [%s], con ID [%d], se encuentra realizando su [PROCESO], con un delay de [%d] segundo(s)\n", p->nombrePROCESO, p->id, p->delay);
		//_array[i].proceso.proceso_realizar();
		printf("Escribiendo Texto en Word\n");
		//pthread_join(_array[i].proceso.hilo,NULL);
		printf("<=================================================================================>\n");
		for(int j = 0; j < p->delay; j++){
			sleep(1); 
		}
		printf("El proceso [%s], con ID [%d] ah finalizado.\n", p->nombrePROCESO, p->id);
	}
	else if(p->estado == NO_ACTIVO){
		printf("<+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>\n");
		printf("\tEl proceso de nombre [%s], con ID [%d], SE ENCUENTRA EN ESTADO NO ACTIVO\n", p->nombrePROCESO, p->id);
		printf("<+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>\n");
	}
	else{
		;
	}
	
}

void descargar_archivo(void*arg){
	process *p =arg;
	if(p->estado == ACTIVO){
		printf("<=================================================================================>\n");
		printf("\tEl proceso de nombre [%s], con ID [%d], se encuentra realizando su [PROCESO], con un delay de [%d] segundo(s)\n", p->nombrePROCESO, p->id, p->delay);
		//_array[i].proceso.proceso_realizar();
		printf("Descargando Archivo\n");
		//pthread_join(_array[i].proceso.hilo,NULL);
		printf("<=================================================================================>\n");
		for(int j = 0; j < p->delay; j++){
			sleep(1); 
		}
		printf("El proceso [%s], con ID [%d] ah finalizado.\n", p->nombrePROCESO, p->id);
	}
	else if(p->estado == NO_ACTIVO){
		printf("<+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>\n");
		printf("\tEl proceso de nombre [%s], con ID [%d], SE ENCUENTRA EN ESTADO NO ACTIVO\n", p->nombrePROCESO, p->id);
		printf("<+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>\n");
	}
	else{
		;
	}
}

void subiendo_archivo(void*arg){
	process *p =arg;
	if(p->estado == ACTIVO){
		printf("<=================================================================================>\n");
		printf("\tEl proceso de nombre [%s], con ID [%d], se encuentra realizando su [PROCESO], con un delay de [%d] segundo(s)\n", p->nombrePROCESO, p->id, p->delay);
		//_array[i].proceso.proceso_realizar();
		printf("Subiendo Archivo\n");
		//pthread_join(_array[i].proceso.hilo,NULL);
		printf("<=================================================================================>\n");
		for(int j = 0; j < p->delay; j++){
			sleep(1); 
		}
		printf("El proceso [%s], con ID [%d] ah finalizado.\n", p->nombrePROCESO, p->id);
	}
	else if(p->estado == NO_ACTIVO){
		printf("<+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>\n");
		printf("\tEl proceso de nombre [%s], con ID [%d], SE ENCUENTRA EN ESTADO NO ACTIVO\n", p->nombrePROCESO, p->id);
		printf("<+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>\n");
	}
	else{
		;
	}
}

void compilando_programa(void*arg){
	process *p =arg;
	if(p->estado == ACTIVO){
		printf("<=================================================================================>\n");
		printf("\tEl proceso de nombre [%s], con ID [%d], se encuentra realizando su [PROCESO], con un delay de [%d] segundo(s)\n", p->nombrePROCESO, p->id, p->delay);
		//_array[i].proceso.proceso_realizar();
		printf("Compilando programa\n");
		//pthread_join(_array[i].proceso.hilo,NULL);
		printf("<=================================================================================>\n");
		for(int j = 0; j < p->delay; j++){
			sleep(1); 
		}
		printf("El proceso [%s], con ID [%d] ah finalizado.\n", p->nombrePROCESO, p->id);
	}
	else if(p->estado == NO_ACTIVO){
		printf("<+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>\n");
		printf("\tEl proceso de nombre [%s], con ID [%d], SE ENCUENTRA EN ESTADO NO ACTIVO\n", p->nombrePROCESO, p->id);
		printf("<+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>\n");
	}
	else{
		;
	}
}

void ejecutando_programa(void*arg){
	process *p =arg;
	if(p->estado == ACTIVO){
		printf("<=================================================================================>\n");
		printf("\tEl proceso de nombre [%s], con ID [%d], se encuentra realizando su [PROCESO], con un delay de [%d] segundo(s)\n", p->nombrePROCESO, p->id, p->delay);
		//_array[i].proceso.proceso_realizar();
		printf("Ejecutando programa\n");
		//pthread_join(_array[i].proceso.hilo,NULL);
		printf("<=================================================================================>\n");
		for(int j = 0; j < p->delay; j++){
			sleep(1); 
		}
		printf("El proceso [%s], con ID [%d] ah finalizado.\n", p->nombrePROCESO, p->id);
	}
	else if(p->estado == NO_ACTIVO){
		printf("<+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>\n");
		printf("\tEl proceso de nombre [%s], con ID [%d], SE ENCUENTRA EN ESTADO NO ACTIVO\n", p->nombrePROCESO, p->id);
		printf("<+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>\n");
	}
	else{
		;
	}
}
	
void usando_terminal(void*arg){
	process *p =arg;

	if(p->estado == ACTIVO){
		printf("<=================================================================================>\n");
		printf("\tEl proceso de nombre [%s], con ID [%d], se encuentra realizando su [PROCESO], con un delay de [%d] segundo(s)\n", p->nombrePROCESO, p->id, p->delay);
		//_array[i].proceso.proceso_realizar();
		
		printf("Usando la terminal\n");
		
		//pthread_join(_array[i].proceso.hilo,NULL);
		printf("<=================================================================================>\n");
		for (int i = 0; i < p->delay; ++i)
		{
			sleep(1); 
			
		}
		printf("El proceso [%s], con ID [%d] ah finalizado.\n", p->nombrePROCESO, p->id);
			
	}
	else if(p->estado == NO_ACTIVO){
		printf("<+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>\n");
		printf("\tEl proceso de nombre [%s], con ID [%d], SE ENCUENTRA EN ESTADO NO ACTIVO\n", p->nombrePROCESO, p->id);
		printf("<+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>\n");
	}
	else{
		;
	}
}
