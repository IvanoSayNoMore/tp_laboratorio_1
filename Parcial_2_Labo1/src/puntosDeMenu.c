/*
 * puntosDeMenu.c
 *
 *  Created on: 5 jun 2022
 *      Author: Usuario Programador
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"
#include "utnInPuts.h"
#include "puntosDeMenu.h"

#include "Buscadores.h"
#include "Calculadora.h"

#define FULL 0
#define EMPTY -1
#define REINTENTOS 3
#define RETORNONEGATIVO -1
#define RETORNOPOSITIVO 0
#define MAXIMOCADENA 51
#define MAXIMOCADENACODIGOVUELO 51
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define MINIMOIDS 0
#define MAXIMOSIDS 5000

int menu_cargaDatosPasajerosDesdeCsv(char* path , LinkedList* pArrayListPassenger)
{
	int retorno;

	if (path != NULL && pArrayListPassenger != NULL)
	{
		retorno = controller_loadFromText(path, pArrayListPassenger);
	}
	if(retorno==RETORNONEGATIVO)
	{
		printf("\nNo se pudo abrir el archivo csv.\n");
	}

	return retorno;
}

int menu_cargaDatosPasajerosDesdeBinario(char* path , LinkedList* pArrayListPassenger)
{

	int retorno=RETORNONEGATIVO;

	if (path != NULL && pArrayListPassenger != NULL)
	{
		retorno = controller_loadFromBinary(path, pArrayListPassenger);
	}
	if(retorno==RETORNONEGATIVO)
	{
		printf("\nNo se pudo abrir el archivo Binario.\n");
	}

	return retorno;
}

int menu_altaPasajero(LinkedList* pArrayListPassenger)
{
	int retorno=RETORNONEGATIVO;

	if(controller_addPassenger(pArrayListPassenger)==RETORNOPOSITIVO)
	{
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int menu_modificarPasajero(LinkedList* pArrayListPassenger)
{
	int retorno=RETORNONEGATIVO;
	int opcion;

	if(utnGetNumero(&opcion, "\nIngrese 1 si conoce al pasajero a modificar o 0 si decea imprimir la lista de pasajeros ",
			"\nERROR DE OPCION ", "Las opciones son 0 y 1 \n", 0, 1,REINTENTOS)==RETORNOPOSITIVO)
	{
		if(opcion==0)
		{
			controller_ListPassenger(pArrayListPassenger);
		}
		retorno=controller_editPassenger(pArrayListPassenger);
	}

		return retorno;
}

int menu_eliminarPasajero(LinkedList* pArrayListPassenger)
{
	int retorno=RETORNONEGATIVO;
	int opcion;

	if(utnGetNumero(&opcion, "\nIngrese 1 si conoce al pasajero a eliminar o 0 si decea imprimir la lista de pasajeros ",
			"\nERROR DE OPCION ", "Las opciones son 0 y 1 \n", 0, 1,REINTENTOS)==RETORNOPOSITIVO)
	{
		if(opcion==0)
		{
			controller_ListPassenger(pArrayListPassenger);
		}
		retorno = controller_removePassenger(pArrayListPassenger);
	}

		return retorno;
}

int menu_ordenarPasajero(LinkedList* pArrayListPassenger)
{
	int retorno=-2;


	retorno = controller_sortPassenger(pArrayListPassenger);
	if(retorno == RETORNOPOSITIVO)
	{
		puts("El archivo ha sido Ordenado correctamente");
	}


	return retorno;
}

int menu_guardarArchivoCsv(LinkedList* pArrayListPassenger)
{
	int retorno=-2;
	int opcion;
	char auxCadena[MAXIMOCADENA];

	if(utnGetNumero(&opcion, "Ingrese 1 si desea crear un nuevo archivo o 2 si desea guardar sobre el mismo o 0 para cancelar\n"
			, "Error al ingresar Opcion", "Desea reintentar? ", 0,2, REINTENTOS)==RETORNOPOSITIVO)
	{
		if(opcion==1)
		{
			if(utnIngresarAlfanumerico(auxCadena, "Ingrese el nombre del archivo sin la extencion \n", REINTENTOS, 51)==RETORNOPOSITIVO)
			{
				strcat(auxCadena,".csv");
				if(controller_saveAsText(auxCadena,pArrayListPassenger)==RETORNOPOSITIVO)
				{
					retorno=RETORNOPOSITIVO;
					puts("Guardado correctamente");
				}
			}
			else
			{
				puts("Error al nombrar al archivo");
			}
		}
		else if(opcion==2)
		{
			if(controller_saveAsText("data.csv",pArrayListPassenger)==RETORNOPOSITIVO)
			{
				puts("Guardado correctamente");
				retorno=RETORNOPOSITIVO;
			}
		}
		if(opcion==0)
		{
			retorno=RETORNONEGATIVO;
			puts("Se cancela la operacion");
		}
	}


	return retorno;
}

int menu_guardarArchivoBinario(LinkedList* pArrayListPassenger)
{
	int retorno=-2;

	int opcion;
	char auxCadena[MAXIMOCADENA];

	if(utnGetNumero(&opcion, "Ingrese 1 si desea crear un nuevo archivo o 2 si desea guardar sobre el mismo o 0 para cancelar\n"
			, "Error al ingresar Opcion", "Desea reintentar? ", 0,2, REINTENTOS)==RETORNOPOSITIVO)
	{
		if(opcion==1)
		{
			if(utnIngresarAlfanumerico(auxCadena, "Ingrese el nombre del archivo sin la extencion \n", REINTENTOS, 51)==RETORNOPOSITIVO)
			{
				strcat(auxCadena,".bin");
				if(controller_saveAsBinary(auxCadena,pArrayListPassenger)==RETORNOPOSITIVO)
				{
					retorno=RETORNOPOSITIVO;
					puts("Guardado correctamente");
				}
			}
			else
			{
				puts("Error al nombrar al archivo");
			}
		}
		else if(opcion==2)
		{
			if(controller_saveAsBinary("data.bin",pArrayListPassenger)==RETORNOPOSITIVO)
			{
				puts("Guardado correctamente");
				retorno=RETORNOPOSITIVO;
			}
		}
		if(opcion==0)
		{
			retorno=RETORNONEGATIVO;
			puts("Se cancela la operacion");
		}
	}

	return retorno;
}
int menu_filtroPorTipoPasajero(LinkedList* pArrayListPassenger)
{
	int retorno=0;
	int contFClass=0;
	int contExClass=0;
	int contEcClass=0;

	contFClass = ll_count(pArrayListPassenger,count_BuscadorFirstClass);
	contExClass= ll_count(pArrayListPassenger,count_BuscadorExecutiveClass);
	contEcClass= ll_count(pArrayListPassenger,count_BuscadorEconomyClass);
	printf("FirstClass = %d \nExecutiveClass = %d \nEconomyClass = %d \n",contFClass,contExClass,contEcClass);
	return retorno;
}

int menu_armaListasPorCodigoPasajero(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int opcion;
	char nombreArchivo[51];
	char direc[51]="C:\\Registros\\Ordenados\\";
	LinkedList* newList;

	if(utnGetNumero(&opcion, "Generar listado por :\n1-FristClass\n2-EconomyClass\n3-ExecutiveClass\n0-Para salir\n"
			, "Error al ingresar opcion\n", "Desea salir ?", 1, 3, 3)==RETORNOPOSITIVO)
	{
		if(opcion==0)
		{
			puts("Cancelado");

		}
		else
		{
			switch(opcion)
			{
			case 1:
				newList=ll_filter(pArrayListPassenger, count_BuscadorFirstClass);
				strncpy(nombreArchivo,"FirstClas.csv",51);

				break;
			case 2:
				newList=ll_filter(pArrayListPassenger, count_BuscadorEconomyClass);
				strncpy(nombreArchivo,"EconomyClass.csv",51);
				break;
			case 3:
				newList=ll_filter(pArrayListPassenger, count_BuscadorExecutiveClass);
				strncpy(nombreArchivo,"ExecutiveClass.csv",51);
				break;
			}

		}
	}
	if(opcion !=0 && newList != NULL)
	{
		printf("El archivo se guardara como %s",nombreArchivo);
		utnGetNumero(&opcion, "\nIngrese 0 si desea guardar el doc con el mismo nombre o 1 si desea cambiarlo\n", "Error", "Desea reintentar?", 0, 1, 3);
		if(opcion==0)
		{
			strncat(direc,nombreArchivo,51);

			if(controller_saveAsText(direc, newList)==RETORNOPOSITIVO)
			{
				retorno=RETORNOPOSITIVO;
				printf("Se ha guardado el archivo en : %s ",direc);
			}
		}
		else if(opcion==1)
		{
			utnRecibeCadenaSoloCaracteres(nombreArchivo, "Ingrese el nombre del nuevo archivo\n", 3, 51);
			strncat(direc,nombreArchivo,51);
			if(controller_saveAsText(direc, newList)==RETORNOPOSITIVO)
			{
				printf("Se ha guardado el archivo en : %s ",direc);
				retorno=RETORNOPOSITIVO;
			}
		}
	}

	ll_deleteLinkedList(newList);


	return retorno;

}

int menu_calculaMillas(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	LinkedList* listaAux=NULL;

	listaAux=ll_map(pArrayListPassenger, calcu_calculaMillas);
	pArrayListPassenger=ll_clone(listaAux);
	ll_deleteLinkedList(listaAux);
	controller_ListPassenger(pArrayListPassenger);

	return retorno;
}



























