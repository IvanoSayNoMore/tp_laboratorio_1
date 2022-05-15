/*
 * ArrayPassenger.c
 *
 *  Created on: 25 abr 2022
 *      Author: Usuario Programador
 */
#define FULL 0
#define EMPTY -1
#define REINTENTOS 3
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#include  "ArrayFly.h"
#include "ArrayDataFlight.h"
#include "ingresoDePasajeros.h"
#include "ArrayPassenger.h"
#include "utnInPuts.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

int initPassengers(Passenger* list, int lenPassenger)
{
	int retorno=-1;
	if(list!=NULL)
	{
		int i;

		for(i=0;i<lenPassenger;i++)
		{
			list[i].isEmpty=EMPTY;
			retorno=0;
		}

	}

	return retorno;
}

int addPassenger(Passenger* listPassager,DateFlight* listFlight, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int lenPassagers, int lenFlight)
{
	int retorno=-1;


	if(listPassager!=NULL && listFlight!=NULL && name!=NULL && lastName!= NULL && flycode!=NULL)
	{

		listPassager->idPasajero=id;
		strncpy(listPassager->nameLastName.lastName,lastName,sizeof(listPassager->nameLastName.lastName));
		strncpy(listPassager->nameLastName.name,name,sizeof(listPassager->nameLastName.name));
		listPassager->isEmpty=FULL;
		listPassager->typePassenger=typePassenger;

		listFlight->idPasajero=id;;
		listFlight->price=price;
		strncpy(listFlight->flyCode,flycode,sizeof(listFlight->flyCode));
		listFlight->isEmpty=FULL;

		retorno=RETORNOPOSITIVO;
	}
	return retorno;

}


int ingresPassenger(char name[],char lastName[],int* typePassenger, int lenCadena)
{
	int retorno=-1;
	char auxChar[lenCadena];
	int flagOk=0;
	int continuar=0;
	int auxInt;
	do{
		//Nombre
		if(utnIngressNameLastname(auxChar, "\nIngrese su nombre: \n", lenCadena)==0)
		{

			strncpy(name,auxChar,lenCadena);
		}
		else
		{
			flagOk=-1;
			break;
		}

		//Apellido
		if(utnIngressNameLastname(auxChar, "\nIngrese su apellido: \n", lenCadena)==RETORNOPOSITIVO)
		{

			strncpy(lastName,auxChar,lenCadena);
		}
		else
		{
			flagOk=-1;
			break;
		}

		//Tipo
		if(utnGetNumero(&auxInt, "\nIngrese el tipo, hay 5 .\n","Reintente TIPO\n", "Error. Hay 5 tipos maximos. Desea reintentar?\n", 1, 5, REINTENTOS)==RETORNOPOSITIVO)
		{
			*typePassenger=auxInt;
		}
		else
		{
			flagOk=RETORNONEGATIVO;
			break;
		}

	}while(continuar==1);

	retorno=flagOk;


	return retorno;

}

int utnIsEmptyOrFullPassager(Passenger* list,int fullEmpty,int lenPassenger)
{
	int retorno=-1;
	int i;
	for(i=0;i<lenPassenger;i++)
	{
		if(list[i].isEmpty==fullEmpty)
		{
			retorno=i;
			break;
		}
	}
	return retorno;
}

int findPassengerById(Passenger* list, int id,int* posicion,int lenPassenger)
{
	int retorno=-1;
	int i;
	for(i=0;i<lenPassenger;i++)
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




int changePassager(Passenger* listPassager,int lenCadena)
{
	int retorno=-1;
	int continuar;
	int auxInt;
	int opcion;
	char auxChar[lenCadena];
	int flagOk=RETORNOPOSITIVO;


	do{
		printf("Su nombre actual es %s\nSu Apellido actual es %s\nSu tipo de pasajero actual es %d\n",listPassager->nameLastName.name,listPassager->nameLastName.lastName,listPassager->typePassenger);
		puts("----------------------------------\n");
		if(utnGetNumero(&opcion, "Ingrese la op que desea modificar.\n1-Nombre\n2-Apellido\n3-Tipo de pasajero\n4-Para cancelar la modificacion\n "
				,"\nPor favor, ingrese solo numeros\n", "Error al ingresar Opcion. Desea reintentar?\n", 1, 4, REINTENTOS)==RETORNOPOSITIVO)
		{
			switch(opcion)
			{
			case 1:

				if(utnIngressNameLastname(auxChar, "\nIngrese su nombre: \n", lenCadena)==RETORNOPOSITIVO)
				{
					utnToupper(auxChar);
					printf("Cambio exitoso, el nuevo nombre es el de %s\n",auxChar);
					strncpy(listPassager->nameLastName.name,auxChar,lenCadena);
					flagOk=RETORNOPOSITIVO;
					break;
				}
				else
				{
					flagOk=RETORNONEGATIVO;
					break;
				}

			case 2:
				if(utnIngressNameLastname(auxChar, "\nIngrese su apellido: \n", lenCadena)==RETORNOPOSITIVO)
				{
					utnToupper(auxChar);
					printf("Cambio exitoso, el nuevo apellido es el de %s\n",auxChar);
					strncpy(listPassager->nameLastName.lastName,auxChar,lenCadena);
					flagOk=RETORNOPOSITIVO;
					break;
				}
				else
				{
					flagOk=RETORNONEGATIVO;
					break;
				}

			case 3:
				if(utnGetNumero(&auxInt, "\nIngrese el tipo\n", "Error al ingresar tipo\n", "", 0, 5, REINTENTOS)==RETORNOPOSITIVO)
				{
					listPassager->typePassenger=auxInt;
					printf("Cambio exitoso, el nuevo tipo es el de %d\n",auxInt);

					flagOk=RETORNOPOSITIVO;
					break;
				}
				else
				{

					flagOk=RETORNONEGATIVO;
					break;
				}
			case 4:
				puts("Se cancela la opcion modificar\n");
				flagOk=RETORNOPOSITIVO;
				break;
			default :
				flagOk=RETORNONEGATIVO;
				puts("Error de opcion\n");

			}//Fin Switch

		}//Fin If utnGetNumero
		if(flagOk==RETORNOPOSITIVO)
		{
			continuar=utnVerificacionConChar( "Desea continuar con la opcion de cambio de datos personales ? \n",
								"Seleccione que desea modificar\n", "Finaliza la modificacion de datos personales" , 0);
		}
		else
		{
			continuar=utnVerificacionConChar( "Ocurrio un error al modificar,desea continuar el cambio de datos personales ?\n",
								"Seleccione que desea modificar\n", "Finaliza la modificacion de datos personales " , 0);
		}

	}while(continuar==RETORNOPOSITIVO);


	return retorno;
}

int removePassenger(Passenger* list)
{
	int retorno=-1;
	if(list!=NULL)
	{
		list->isEmpty=EMPTY;
	}
	return retorno;
}







