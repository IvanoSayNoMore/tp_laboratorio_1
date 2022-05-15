/*
 * ArrayFly.c
 *
 *  Created on: 5 may 2022
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
#define REINTENTOS 3
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1

int loadFlight(Flight* list,char vuelo[],char codigoVuelo[],int estadoVuelo, int lenVuelos, int lenChar, int lenCharCode)
{
	int retorno=RETORNONEGATIVO;

    for(int i=0;i<lenVuelos;i++)
    {
    	if(list[i].isEmtpy==EMPTY)
    	{
    		list[i].isEmtpy=FULL;
    		strncpy(list[i].vuelo,vuelo,lenChar);
    		strncpy(list[i].flycode,codigoVuelo,lenCharCode);
    		list[i].statusFlight=estadoVuelo;
    		retorno=RETORNOPOSITIVO;
    		break;
    	}
    }

	return retorno;
}

int initFlight(Flight* list, int lenFlght)
{
	int retorno;
	if(list!=NULL && lenFlght>0)
	{
		retorno=RETORNOPOSITIVO;
		for(int i=0;i<lenFlght;i++)
		{
			list[i].isEmtpy=EMPTY;

		}
	}
	return retorno;
}

int findPassengerByCode(Flight* list, char code[],int* posicion ,int lenFlght)
{
	int retorno=-1;
	int i;
	for(i=0;i<lenFlght;i++)
	{
		if(list[i].isEmtpy==FULL &&
				strncmp(list[i].flycode,code,lenFlght)==0)
		{
			*posicion=i;
			retorno=0;
			break;
		}
	}

	return retorno;
}

int ingresDataFlight(Flight* list,float* price, char flycode[],int lenCharCodeFli,int lenVuelos)
{
	int retorno;
	float auxFloat;
	int flagOk=RETORNOPOSITIVO;
	char auxChar[lenCharCodeFli];
	int continuar=RETORNOPOSITIVO;

	do{
		//Precio
		if(utnIngresarFlotante("\nIngrese el precio del vuelo\n",&auxFloat,REINTENTOS)!=RETORNONEGATIVO)
		{
			if(auxFloat<15000 || auxFloat>20000)
			{
				puts("Error. El precio minimo es de 15000 y el maximo es de 20000");
				flagOk=RETORNONEGATIVO;
			}
			else
			{
				*price=auxFloat;
				flagOk=RETORNOPOSITIVO;
			}

		}
		else
		{
			flagOk=RETORNONEGATIVO;

		}

		//Codigo
		if(flagOk==RETORNOPOSITIVO)
		{
			if(loadFlightCode(list, auxChar, lenVuelos, REINTENTOS,lenCharCodeFli)==RETORNOPOSITIVO)
			{
				strncpy(flycode,auxChar,lenCharCodeFli);
				break;
			}
			else
			{
				flagOk=RETORNONEGATIVO;
			}

		}

		if(flagOk==RETORNONEGATIVO)
		{
			if(utnVerificacionConChar("Ocurrio un error al ingresar algun dato del vuelo. Desea reintentar? Si o no\n"
					,"Vuelva a intentar. \n", "Adios", 0)==RETORNOPOSITIVO)
			{
				continuar=RETORNOPOSITIVO;
			}
			else
			{
				continuar=RETORNONEGATIVO;
			}
		}
	}while(continuar==RETORNOPOSITIVO);

	retorno=flagOk;

	return retorno;
}

int loadFlightCode(Flight* list,char flycode[], int maximoVuelos, int reintentos,int lenCharCodeFli)
{
	char auxChar[lenCharCodeFli];
	int retorno;
	do{
		printListFlight(list, maximoVuelos);
		if(utnIngresarAlfanumerico(auxChar, "Ingrese codigo del Vuelo a asignar\n",REINTENTOS,lenCharCodeFli)==RETORNOPOSITIVO)
		{
			if(findFligthByCode(list, auxChar, maximoVuelos)==RETORNOPOSITIVO)
			{
				strncpy(flycode,auxChar,lenCharCodeFli);
				retorno=RETORNOPOSITIVO;
				break;
			}
			else
			{
				if(reintentos>0)
				{
					printf("No se encontro el codigo ingresado. Vuelva a intentar, quedan %d intentos",REINTENTOS);
					reintentos--;
					retorno=RETORNONEGATIVO;
				}
				else
				{
					puts("No quedan intentos");
					retorno=RETORNONEGATIVO;
				}

			}
		}

	}while(reintentos>0);

	return retorno;

}

int findFligthByCode(Flight* list,char codigoVuelo[],int lenFlight)
{
	int retorno=-1;
	pasajeTodoAminusculaOmayusculaConNum(codigoVuelo, 0);
	int valor;
	for(int i=0;i<lenFlight;i++)
	{
		valor=strncmp(list[i].flycode,codigoVuelo,lenFlight);
		if(list[i].isEmtpy==FULL && valor==RETORNOPOSITIVO)
		{
			retorno=0;
			break;
		}
	}


	return retorno;
}


