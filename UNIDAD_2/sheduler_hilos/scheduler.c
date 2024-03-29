#include "scheduler.h"

static int buscarIndex_empty(array_procesos *_array);
static void initArray(array_procesos *_array);
static bool isOk_ID_Process(array_procesos *_array, process _t);

int cont_procesos=0;

process *crear_Proceso(int _id, int _delay, char *_nombreProceso, FN_ACCION _proceso_realizar, int _estado){
	process *_p = (process *)malloc(sizeof(process));
	_p->id = _id;
	_p->delay = _delay;
	strcpy(_p->nombrePROCESO, _nombreProceso);
	_p->proceso_realizar = _proceso_realizar;
	_p->estado = _estado;
	return _p;
}
//CRECACION DE LOS HILOS DENTRO DE AGREGAR_PROCESO
//PARA NO CREAR HILOS DE PROCESOS REPETIDOS
void agregar_Proceso(array_procesos *_array, process _p){
	int _index = buscarIndex_empty(_array);
	bool id_ok = isOk_ID_Process(_array, _p);
	if(_index != -1){
		if(id_ok != false){
			_array[_index].proceso = _p;
			_array[_index].empty = false;
			pthread_create(&_array[_index].proceso.hilo,NULL,(void *)_array[_index].proceso.proceso_realizar,&_array[_index].proceso);
			printf("Se agrego a [_array] el proceso [%s] con id [%d] <---- OK\n", _array[_index].proceso.nombrePROCESO, _array[_index].proceso.id);
			cont_procesos++;
		}
		else{
			printf("El ID [%d] ya se encuentra asociado a un Proceso...\n", _p.id);
			//pthread_exit(_array[_index].proceso.hilo);
		}
	}
	else{
		printf("NO hay index disponible...\n");
	}
}

//ESPERA DE QUE FINALIZEN LOS PROCESOS DEL ARREGLO
void ejecutar_Procesos(array_procesos *_array){
	printf("-----> Procesos = [%d]\n", cont_procesos);
	for(int i = 0; i < cont_procesos; i++){
		pthread_join(_array[i].proceso.hilo,NULL);
	}
}

array_procesos *crear_ArrayProcesos(void){
	array_procesos *array = (array_procesos *)malloc(sizeof(array_procesos)*MAX_PROCESOS);
	initArray(array);
	return array;
}

/* PRIVATE FUNCTIONS */

static bool isOk_ID_Process(array_procesos *_array, process _p){
	bool id_Ok = true;
	for(int i = 0; i < MAX_PROCESOS; i++){
		if(_array[i].proceso.id == _p.id){
			id_Ok = false;
			break;
		}
	}
	return id_Ok;
}

static void initArray(array_procesos *_array){
	for(int i = 0; i < MAX_PROCESOS; i++){
		_array[i].proceso.id = -1;
		_array[i].empty = true;
	}
}

static int buscarIndex_empty(array_procesos *_array){
	int _index_empty = -1;
	for(int i = 0; i < MAX_PROCESOS; i++){
		if(_array[i].empty == true){
			_index_empty = i;
			break;
		}
	}
	return _index_empty;
}
