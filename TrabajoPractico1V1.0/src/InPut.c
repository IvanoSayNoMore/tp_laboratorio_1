/*
 * InPut.c
 *
 *  Created on: 6 abr 2022
 *      Author: Usuario Programador
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "InPut.h"
/////////////////////////////////////////////////////////////////////
/**
 * \brief Recorre stdin hasta \n o hasta maximo de "cadena"-1
 * @param cadena cadena Puntero al espacio de memoria donde se copia la cadena obtenida
 * @param longitud longitud Largo de la cadena
 * @return Retorna 0 si se obtiene una cadena. -1 Cuando no encuentra cadena
 */
static int myGets(char* cadena, int longitud);

/**
 *\brief Verifica que la cadena sea numerica
 * @param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * @return retorna 0 si obtiene cadena. -1 cuando no .
 */
static int getInt(int* pResultado);

/**
 * \brief Verifica si la cadena ingresada es numerica
 * @param cadena Cadena a ser analizada
 * @return Rotorna 1 si la cadena es numerica. 0, si no lo es.
 */
static int esNumerica(char* cadena);
///////////////////////Fin declaracion Estaticas///////////////////////

static int myGets(char* cadena, int longitud)
{
	fflush(stdin);
	fgets(cadena,longitud,stdin);
	cadena[strlen(cadena)-1]='\0';
	return 0;
}

static int getInt(int* pResultado)
{
	int retorno=-1;
	char buffer[1000];

	if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
	{
		retorno=0;
		*pResultado=atoi(buffer);
	}

	return retorno;
}

static int esNumerica(char* cadena)
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

/////////////////////// Funciones para usuario ///////////////////////

int utnGetNumero(float* pNumeroIngresado, char* mensaje, char* mensajeFinal,char* mensajeSeguirNoSeguir, int minimo, int maximo, int reintentos)
{
	int retorno =1;
	int buffer;
	int verificacionFinal;

	if(pNumeroIngresado!=NULL && mensaje!=NULL && mensajeFinal!=NULL && mensajeSeguirNoSeguir!=NULL
			&& minimo<=maximo && reintentos>=0)

		do
		{

			printf("%s",mensaje);
			if(getInt(&buffer)==0 && buffer>=minimo && buffer<=maximo)
			{
				*pNumeroIngresado=buffer;
				retorno=0;
				break;
			}
			reintentos--;
			if(reintentos!=0 && retorno!=0)
			{
				verificacionFinal=utnVerificacionConChar(mensajeSeguirNoSeguir,mensajeFinal);
				if(verificacionFinal==0)
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





