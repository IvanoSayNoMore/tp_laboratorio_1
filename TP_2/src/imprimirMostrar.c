/*
 * imprimirMostrar.c
 *
 *  Created on: 25 abr 2022
 *      Author: Usuario Programador
 */
#define EMPTY 0
#define FULL -1
#include "imprimirMostrar.h"
#include "sortPassenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int printPassenger(Passenger* list, int len)
{
	int retorno=-1;
	if(list!=NULL)
	{puts("|Id Pasajero|   Apellido   |   Nombre   | Codigo del Vuelo |   Precio  |  Tipo de Pasajero  |  Estado del vuelo  |");
	    for(int i=0;i<len;i++)
	    {
	    	if(list[i].isEmpty==FULL)
	    	{
	    		printOnePassenger(list[i]);
	    		retorno=0;
	    	}
	    }
	}
    return retorno;
}

void printOnePassenger(Passenger passenger)
{

	printf("\n %d\t\t%s\t\t%s\t\t%s\t     %.2f\t\t%d\t",passenger.id,passenger.nameLastName.lastName,
			passenger.nameLastName.name,passenger.flycode,passenger.price,passenger.typePassenger);
	if(passenger.statusFlight==1)
	{
		puts("ACTIVO\n");
	}
	else
	{
		puts("CANCELADO\n");
	}
}
