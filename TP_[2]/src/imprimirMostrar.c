/*
 * imprimirMostrar.c
 *
 *  Created on: 25 abr 2022
 *      Author: Usuario Programador
 */
#define FULL 0
#define EMPTY -1
#include "imprimirMostrar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int printPassenger(Passenger* list,DateFlight* listDateFlight,Flight* vuelo, int lenPassenger, int lenFlight)
{
	int retorno=-1;
	if(list!=NULL && listDateFlight!=NULL)
	{
	    puts("----------------------------------------------------------------------------------------------------------------------\n");
	    puts("-------------------------------------------listado de pasajeros-------------------------------------------------------\n");
	    puts("----------------------------------------------------------------------------------------------------------------------\n");
		puts("|Id Pasajero|   Apellido   |   Nombre    |  Tipo de Pasajero  |     Precio    |  Estado del vuelo  |    DESTINO       \n");
	    puts("----------------------------------------------------------------------------------------------------------------------\n");
	    for(int i=0;i<lenPassenger;i++)
	    {
	    	if(list[i].isEmpty==FULL)
	    	{
	    		for(int j=0;j<lenPassenger;j++)
	    		{
	    			if(list[i].idPasajero==listDateFlight[j].idPasajero)
	    			{
	    				printOnePassenger(&list[i]);
	    				printOneDestin(&listDateFlight[j], vuelo, lenPassenger, lenFlight);

	    			}
	    		}

	    		retorno=0;
	    	}
	    }
	}
    return retorno;
}

void printOneDestin(DateFlight* listDateFlight,Flight* vuelo, int lenPassenger, int lenFlight)
{
	for(int k=0;k<lenFlight;k++)
	{
		int valor;
		valor=strcmp(listDateFlight->flyCode,vuelo[k].flycode);
		if(valor==0)
		{
			printf("|  $ %10.2f  |",listDateFlight->price);
			if(vuelo[k].statusFlight==0)
			{
				printf("    ACTIVO          |");
			}
			else
			{
				printf("    CANCELADO       |");
			}

			printf("%s     |\n",vuelo[k].vuelo);
			puts("---------------------------------------------------------------------------------------------------------------");
			break;
		}
	}

}

void printOnePassenger(Passenger* passenger)
{

	printf("|   %3d     | %s\t   | %s\t |  %5d             ",passenger->idPasajero,passenger->nameLastName.lastName,
				passenger->nameLastName.name,passenger->typePassenger);
}

int printListFlight(Flight* vuelo,int len)
{
	puts("\nHay vuelos a :\n");
	for(int i=0;i<len;i++)
	{
		if(vuelo[i].isEmtpy==0)
		{
			printFlight(&vuelo[i]);
		}
	}
	return 0 ;
}

void printFlight(Flight* vuelo)
{
	puts("---------------------------------------");
	printf("Destino: %s\n",vuelo->vuelo);
	printf("El codigo es.: %s\n",vuelo->flycode);
	if(vuelo->statusFlight==1)
	{
		printf("VUELO MOMENTANEAMENTE CANCELADO\n");
	}
	puts("---------------------------------------");

}

void printPassengerByCode(DateFlight* passenger,Flight* vuelo,int order,int lenPassenger)
{
	int valor;
	for(int i=0;i<lenPassenger;i++)
	{
		if(passenger[i].isEmpty==FULL)
		{
			for(int j=0;j<lenPassenger;j++)
			{
				valor=strncmp(passenger[i].flyCode,vuelo[j].flycode,51);
				if(vuelo[j].isEmtpy==FULL && valor==0)
				{
					if(order==1 && vuelo[j].statusFlight==0)
					{
						printf("\nId %d Codigo %s Estado Activo\n",passenger[i].idPasajero,passenger[i].flyCode);
					}
					if(order==0 && vuelo[j].statusFlight==1)
					{
						printf("\nId %d Codigo %s Estado CANCELADO\n",passenger[i].idPasajero,passenger[i].flyCode);
					}

					break;
				}
			}
		}

	}
}








