/*
 * ArrayDataFlight.c
 *
 *  Created on: 13 may 2022
 *      Author: Usuario Programador
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include "utnInPuts.h"
#include "ArrayFly.h"
#include "imprimirMostrar.h"
#define FULL 0
#define EMPTY -1
#define MAXIMOCHAR 51
#define REINTENTOS 3
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1

int initDataFlight(DateFlight* list, int lenDateFlight)
{
	int retorno=RETORNONEGATIVO;
	if(list!=NULL)
	{
		int i;
		retorno=RETORNOPOSITIVO;
		for(i=0;i<lenDateFlight;i++)
		{
			list[i].isEmpty=EMPTY;
			retorno=RETORNOPOSITIVO;

		}
	}

	return retorno;
}

int findFlightById(DateFlight* list, int id,int* posicion,int lenFlight)
{
	int retorno=-1;
	int i;
	for(i=0;i<lenFlight;i++)
	{
		if(list[i].isEmpty==FULL && list[i].idPasajero==id )
		{
			retorno=0;
			*posicion=i;
			break;
		}
	}

	return retorno;
}

int changeDataFlight(DateFlight* dateFl,Flight* listFlight, int lenFlight,int lenChar,int lenCharCode )
{
	int retorno=0;
	int continuar;
	int opcion;
	int flagOk=0;
	float auxFloat;

	char auxChar[lenCharCode];

	do{
		printf("El precio actual del vuelo es de %.2f\nSu codigo actual es el %s\n",dateFl->price,dateFl->flyCode);
		if(utnGetNumero(&opcion, "Ingrese la op que desea modificar.\n1-Precio\n2-Codigo\n3-Cancelar \n"
				,"\nPor favor, ingrese solo numeros\n", "Error al ingresar Opcion. Desea reintentar?\n", 1, 3, REINTENTOS)==RETORNOPOSITIVO)
		{
			switch(opcion)
			{
			case 1:
				if(utnIngresarFlotante("\nIngrese el precio\n",&auxFloat,REINTENTOS)==RETORNONEGATIVO)
				{
					flagOk=RETORNONEGATIVO;
					break;
				}
				else
				{
					printf("Cambio exitoso, el nuevo precio es de %.2f\n",auxFloat);
					dateFl->price=auxFloat;
					flagOk=RETORNOPOSITIVO;
					break;
				}

			case 2:
				if(loadFlightCode(listFlight,auxChar,lenFlight,REINTENTOS,lenCharCode)==RETORNOPOSITIVO)
				{
					pasajeTodoAminusculaOmayusculaConNum(auxChar, 0);
					printf("Cambio exitoso, el nuevo codigo es el de %s\n",auxChar);
					strncpy(dateFl->flyCode,auxChar,lenChar);
					flagOk=RETORNOPOSITIVO;
					break;
				}
				else
				{
					flagOk=RETORNONEGATIVO;
					break;
				}

			case 3:
				puts("Se cancela la modificacion\n");
				flagOk=RETORNOPOSITIVO;
				break;
			default:
				puts("Error");
				break;
			}//Fin switch
		}//Fin if getnumero
		if(flagOk==RETORNOPOSITIVO)
		{
			continuar=utnVerificacionConChar( "Desea continuar con la opcion de cambio de datos del vuelo? \n",
								"Seleccione que desea modificar\n", "Finaliza la modificacion de datos del vuelo\n" , 0);
		}
		else
		{
			continuar=utnVerificacionConChar( "Ocurrio un problema al cargar el cambio, Desea continuar el cambio?\n",
								"Seleccione que desea modificar\n", "Finaliza la modificacion" , 0);
		}


	}while(continuar==RETORNOPOSITIVO);

	return retorno;
}

int utnIsEmptyOrFullFlight(DateFlight* list,int fullEmpty,int lenDataFlight)
{
	int retorno=-1;
	int i;
	for(i=0;i<lenDataFlight;i++)
	{
		if(list[i].isEmpty==fullEmpty)
		{
			retorno=i;
			break;
		}
	}
	return retorno;
}

int removeFlight(DateFlight* list)
{
	int retorno=-1;
	if(list!=NULL)
	{
		list->isEmpty=EMPTY;
	}
	return retorno;
}
