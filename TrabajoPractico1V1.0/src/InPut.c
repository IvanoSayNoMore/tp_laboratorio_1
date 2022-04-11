/*
 * InPut.c
 *
 *  Created on: 6 abr 2022
 *      Author: Usuario Programador
 */
#include "InPut.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int utnMyGets(char* cadena, int longitud)
{
	fflush(stdin);
	fgets(cadena,longitud,stdin);
	cadena[strlen(cadena)-1]='\0';
	return 0;
}

int utnGetInt(int* pResultado)
{
	int retorno=-1;
	char buffer[1000];

	if(utnMyGets(buffer,sizeof(buffer))==0 && utnEsNumerica(buffer))
	{
		retorno=0;
		*pResultado=atoi(buffer);
	}

	return retorno;
}

int utnGetNumero(float* pNumeroIngresado, char* mensaje, char* mensajeError,char* mensajeSeguirNoSeguir, int minimo, int maximo, int reintentos)
{
	int retorno =1;
	int buffer;
	int verificacionFinal;

	if(pNumeroIngresado!=NULL && mensaje!=NULL && mensajeError!=NULL && mensajeSeguirNoSeguir!=NULL
			&& minimo<=maximo && reintentos>=0)

		do
		{

			printf("%s",mensaje);
			if(utnGetInt(&buffer)==0 && buffer>=minimo && buffer<=maximo)
			{
				*pNumeroIngresado=buffer;
				retorno=0;
				break;
			}
			reintentos--;
			if(reintentos!=0 && retorno!=0)
			{
				verificacionFinal=utnVerificacionConChar(mensajeSeguirNoSeguir,mensajeError);
				if(verificacionFinal==-1)
				{
					reintentos=0;
					break;
				}
			}
			else
			{
				printf("No queden intentos.\n");
			}


		}while(reintentos>=1);

	return retorno;
}

int utnVerificacionConChar(char* mensajeValidacion,char* mensajeFinal)
{
	int retorno=0;
	char ingresoDeUsuario;
	printf("%s",mensajeValidacion);
	fflush(stdin);
	scanf("%c",&ingresoDeUsuario);
	ingresoDeUsuario=tolower(ingresoDeUsuario);

	if(ingresoDeUsuario=='s')
	{
		printf("\n %s \n",mensajeFinal);
		retorno =-1;
	}
	return retorno;
}

int utnEsNumerica(char* cadena)
{
	int retorno=1;
	int i=0;
	if(cadena[0]=='-')
	{
		i=1;
	}

	for(;cadena[i] != '\0';i++)
	{
		if(cadena[i]>'9' || cadena[i]<'0')
		{
			retorno=0;
			break;
		}
	}


	return retorno;
}









