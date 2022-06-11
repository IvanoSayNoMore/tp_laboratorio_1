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
	int retorno=RETORNONEGATIVO;

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
<<<<<<< HEAD

	if (path != NULL && pArrayListPassenger != NULL)
	{
		retorno = controller_loadFromBinary(path, pArrayListPassenger);
	}
	if(retorno==RETORNONEGATIVO)
	{
		printf("\nNo se pudo abrir el archivo Binario.\n");
	}

=======

	if (path != NULL && pArrayListPassenger != NULL)
	{
		retorno = controller_loadFromBinary(path, pArrayListPassenger);
	}
	if(retorno==RETORNONEGATIVO)
	{
		printf("\nNo se pudo abrir el archivo Binario.\n");
	}

>>>>>>> 6ac921560a5d814f71475b007036fc0c702d9e3c
	return retorno;
}

int menu_altaPasajero(LinkedList* pArrayListPassenger)
{
	int retorno=RETORNONEGATIVO;
	if(pArrayListPassenger != NULL)
	{
		if(ll_isEmpty(pArrayListPassenger)==RETORNOPOSITIVO)
		{
			if(controller_addPassenger(pArrayListPassenger)==RETORNOPOSITIVO)
			{
				retorno=RETORNOPOSITIVO;
			}
		}
		else
		{
			puts("Primero se debe cargar los datos");
			retorno=-2;
		}
	}
	return retorno;
}

int menu_modificarPasajero(LinkedList* pArrayListPassenger)
{
	int retorno=RETORNONEGATIVO;
	int opcion;
	if(pArrayListPassenger != NULL)
	{
		if(ll_isEmpty(pArrayListPassenger)==RETORNOPOSITIVO)
		{
			if(utnGetNumero(&opcion, "\nIngrese 1 si conoce al pasajero a modificar o 0 si decea imprimir la lista de pasajeros ",
					"\nERROR DE OPCION ", "Las opciones son 0 y 1 \n", 0, 1,REINTENTOS)==RETORNOPOSITIVO)
			{
				if(opcion==0)
				{
					controller_ListPassenger(pArrayListPassenger);
				}
<<<<<<< HEAD
				retorno=controller_editPassenger(pArrayListPassenger);
			}
=======
				controller_editPassenger(pArrayListPassenger);
			}

>>>>>>> 6ac921560a5d814f71475b007036fc0c702d9e3c
		}
		else
		{
			puts("Primero se debe cargar los datos");
			retorno = -2;
		}

	}

		return retorno;
}

int menu_eliminarPasajero(LinkedList* pArrayListPassenger)
{
	int retorno=RETORNONEGATIVO;
	int opcion;
	if(pArrayListPassenger != NULL)
	{
		if(ll_isEmpty(pArrayListPassenger)==RETORNOPOSITIVO)
		{
			if(utnGetNumero(&opcion, "\nIngrese 1 si conoce al pasajero a eliminar o 0 si decea imprimir la lista de pasajeros ",
					"\nERROR DE OPCION ", "Las opciones son 0 y 1 \n", 0, 1,REINTENTOS)==RETORNOPOSITIVO)
			{
				if(opcion==0)
				{
					controller_ListPassenger(pArrayListPassenger);
				}
<<<<<<< HEAD
				retorno = controller_removePassenger(pArrayListPassenger);
=======
				controller_removePassenger(pArrayListPassenger);
>>>>>>> 6ac921560a5d814f71475b007036fc0c702d9e3c
			}

		}

	}
		return retorno;
}

int menu_ordenarPasajero(LinkedList* pArrayListPassenger)
{
	int retorno=-2;
	int valida;
	valida = ll_isEmpty(pArrayListPassenger);

	if(pArrayListPassenger != NULL && valida == RETORNOPOSITIVO)
	{
		retorno = controller_sortPassenger(pArrayListPassenger);
		if(retorno == RETORNOPOSITIVO)
		{
			puts("El archivo ha sido Ordenado correctamente");
		}
	}

	return retorno;
}
