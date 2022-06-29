/*
 * Calculadora.c
 *
 *  Created on: 28 jun 2022
 *      Author: Usuario Programador
 */
#include "Calculadora.h"
#include "Passenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calcu_calculaMillas(void* pElement)
{
	int retorno=-1;
	float precio;
	int millas;
	if(pElement != NULL)
	{
		Passenger_getPrecio(pElement, &precio);
		millas=precio/10;
		Passenger_setMillas(pElement, millas);
		retorno=0;
	}

	return retorno;
}
