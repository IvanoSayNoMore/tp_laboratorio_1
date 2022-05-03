/*
 * ArrayPassenger.c
 *
 *  Created on: 25 abr 2022
 *      Author: Usuario Programador
 */
#define EMPTY 0
#define FULL -1
#define MAXIMOCHAR 51
#define REINTENTOS 3
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define ESTADODEVUELOACTIVO 1
#include "ArrayPassenger.h"
#include "utnInPuts.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

void contadorId(int* num)
{
	static int contador=0;
	contador++;
	*num=contador;
}

int initPassengers(Passenger* list, int len)
{
	int retorno=-1;
	if(list!=NULL)
	{
		int i;
		for(i=0;i<len;i++)
		{
			list[i].isEmpty=EMPTY;
			retorno=0;
		}

	}

	return retorno;
}

int addPassenger(Passenger* list, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int len)
{
	int retorno=-1;
	int espacioLibre;
	if(list!=NULL && name!=NULL && lastName!= NULL && flycode!=NULL)
	{
		espacioLibre=utnIsEmptyOrFull(list, EMPTY, len);
		if(espacioLibre!=RETORNONEGATIVO)
		{
			list[espacioLibre].id=id;
			list[espacioLibre].price=price;
			list[espacioLibre].statusFlight=ESTADODEVUELOACTIVO;
			list[espacioLibre].typePassenger=typePassenger;
			strncpy(list[espacioLibre].nameLastName.lastName,lastName,sizeof(list[espacioLibre].nameLastName.lastName));
			strncpy(list[espacioLibre].nameLastName.name,name,sizeof(list[espacioLibre].nameLastName.name));
			strncpy(list[espacioLibre].flycode,flycode,sizeof(list[espacioLibre].flycode));
			list[espacioLibre].isEmpty=FULL;
			retorno=0;
		}
	}
	return retorno;

}

int ingresPassenger(char name[],char lastName[],float* price,int* typePassenger, char flycode[],int len)
{
	int retorno=-1;
	float auxFloat;
	int auxInt;
	char auxChar[MAXIMOCHAR];
	int flagOk=0;
	int continuar=0;
	do{
		//Nombre
		if(utnRecibeCadenaSoloCaracteres(auxChar, "\nIngrese su nombre: \n", REINTENTOS, len)==RETORNONEGATIVO)
		{
			flagOk=-1;
			break;
		}
		else
		{
			utnToupper(auxChar, len);
			strncpy(name,auxChar,len);
		}
		//Apellido
		if(utnRecibeCadenaSoloCaracteres(auxChar, "\nIngrese su apellido: \n", REINTENTOS, len)==RETORNONEGATIVO)
		{
			flagOk=-1;
			break;
		}
		else
		{
			utnToupper(auxChar, len);
			strncpy(lastName,auxChar,len);
		}
		//Precio
		if(utnIngresarFlotante("\nIngrese el precio\n",&auxFloat,REINTENTOS)==RETORNONEGATIVO)
		{
			flagOk=-1;
			break;
		}
		else
		{
			*price=auxFloat;
		}
		//Tipo
		if(utnGetNumero(&auxInt, "\nIngrese el tipo, hay 5 .\n","Se cancela el alta en TIPO\n", "Error. Hay 5 tipos maximos. Desea reintentar?\n", 0, 5, REINTENTOS)==RETORNONEGATIVO)
		{
			flagOk=-1;
			break;
		}
		else
		{
			*typePassenger=auxInt;
		}
		//Codigo
		if(utnIngresarAlfanumerico(auxChar, "Ingrese codigo de Vuelo\n", len)==RETORNONEGATIVO)
		{
			flagOk=-1;
			break;
		}
		else
		{
			pasajeTodoAminusculaOmayusculaConNum(auxChar, 0, len);
			strncpy(flycode,auxChar,len);
			break;
		}

	}while(continuar==1);

	retorno=flagOk;

	return retorno;

}

int utnIsEmptyOrFull(Passenger* list,int fullEmpty,int len)
{
	int retorno=-1;
	int i;
	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty==fullEmpty)
		{
			retorno=i;
			break;
		}
	}
	return retorno;
}

int findPassengerById(Passenger* list, int id,int* posicion,int len)
{
	int retorno=-1;
	int i;
	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty==FULL && list[i].id==id )
		{
			retorno=0;
			*posicion=i;
			break;
		}
	}

	return retorno;
}
int findPassengerByCode(Passenger* list, char code[],int len)
{
	int retorno=-1;
	int i;
	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty==FULL && strncmp(list[i].flycode,code,MAXIMOCHAR)==0)
		{
			retorno=0;
			break;
		}
	}

	return retorno;
}

int changePassager(Passenger* list, int posicion, int lenChar)
{
	int retorno=-1;
	int continuar;
	int opcion;
	char auxChar[lenChar];
	int flagOk=0;
	float auxFloat;
	int auxInt;

	do{
		if(utnGetNumero(&opcion, "Ingrese la op que desea modificar.\n1-Nombre\n2-Apellido\n3-Precio\n4-Tipo\n5-Codigo "
				,"\nPor favor, ingrese solo numeros\n", "Error al ingresar Opcion. Desea reintentar?\n", 1, 6, REINTENTOS)==RETORNOPOSITIVO)
		{
			switch(opcion)
			{
			case 1:
				if(utnRecibeCadenaSoloCaracteres(auxChar, "\nIngrese su nombre: \n", REINTENTOS, lenChar)==RETORNONEGATIVO)
				{
					flagOk=RETORNONEGATIVO;
					break;
				}
				else
				{
					utnToupper(auxChar, lenChar);
					strncpy(list[posicion].nameLastName.name,auxChar,lenChar);
					break;
				}


			case 2:
				if(utnRecibeCadenaSoloCaracteres(auxChar, "\nIngrese su Apellido: \n", REINTENTOS, lenChar)==RETORNONEGATIVO)
				{
					flagOk=RETORNONEGATIVO;
					break;
				}
				else
				{
					utnToupper(auxChar, lenChar);
					strncpy(list[posicion].nameLastName.lastName,auxChar,lenChar);
					break;
				}


			case 3:
				if(utnIngresarFlotante("\nIngrese el precio\n",&auxFloat,REINTENTOS)==RETORNONEGATIVO)
				{
					flagOk=RETORNONEGATIVO;
					break;
				}
				else
				{
					list[posicion].price=auxFloat;
					break;
				}

			case 4:
				if(utnGetNumero(&auxInt, "\nIngrese el tipo\n", "Error al ingresar tipo\n", "", 0, 5, REINTENTOS)==RETORNONEGATIVO)
				{
					flagOk=RETORNONEGATIVO;
					break;
				}
				else
				{

					list[posicion].typePassenger=auxInt;
					break;
				}

			case 5:
				if(utnIngresarAlfanumerico(auxChar, "Ingrese codigo de Vuelo\n", lenChar)==RETORNONEGATIVO)
				{
					flagOk=RETORNONEGATIVO;
					break;
				}
				else
				{
					pasajeTodoAminusculaOmayusculaConNum(auxChar, 0,lenChar);
					strncpy(list[posicion].flycode,auxChar,lenChar);
					break;
				}

			default :
				flagOk=RETORNONEGATIVO;
				puts("Error de opcion\n");

			}//Fin Switch

		}//Fin If utnGetNumero
		if(flagOk==RETORNONEGATIVO)
		{
			if(utnVerificacionConChar("Ocurrio un problema al cargar el cambio, Desea continuar el cambio?\n", "Continua\n","\nAdios\n",0)==-2)
			{
				flagOk=RETORNOPOSITIVO;
				continuar=RETORNOPOSITIVO;
			}//Fin if valida si vuelve a intentar
			else
			{
				continuar=RETORNONEGATIVO;

			}
		}//Fin if valida flag
		else
		{
			if(utnVerificacionConChar("Se ha modificado correctamente. Desea continuar con la opcion de cambio ? \n", "Continua\n", "\nAdios\n",0)==-2)
			{
				continuar=RETORNOPOSITIVO;
			}
			else
			{
				continuar=RETORNONEGATIVO;
				retorno=RETORNOPOSITIVO;
			}

		}

	}while(continuar==RETORNOPOSITIVO);


	return retorno;
}

int removePassenger(Passenger* list, int id, int len)
{
	int retorno=-1;
	int i;
	for(i=0;i<len;i++)
	{
		if(list[i].id==id)
		{
			list[i].isEmpty=EMPTY;
		}
	}

	return retorno;
}







