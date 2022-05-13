/*
 * ingresoDePasajeros.c
 *
 *  Created on: 5 may 2022
 *      Author: Usuario Programador
 */

#define REINTENTOS 3
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#include "utnInPuts.h"

int utnIngressNameLastname(char name[], char mensaje[],int lenCadena)
{
	int retorno;
	char auxChar[lenCadena];
	if(utnRecibeCadenaSoloCaracteres(auxChar,mensaje, REINTENTOS, lenCadena)==RETORNONEGATIVO)
	{
		retorno=-1;
	}
	else
	{
		utnToupper(auxChar);
		strncpy(name,auxChar,lenCadena);
		retorno=0;
	}

	return retorno;
}

