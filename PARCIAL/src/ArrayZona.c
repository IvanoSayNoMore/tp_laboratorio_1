/*
 * ArrayZona.c
 *
 *  Created on: 14 may 2022
 *      Author: Usuario Programador
 */

#include "ArrayCencista.h"
#include "ArrayZona.h"
#include "utnInPuts.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#define EMPTY 0
#define FULL -1
#define PENDIENTE -1
#define FINALIZADO 0
#define REINTENTOS 3
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define MAXOPCIONLOCALIDAD 5
#define MINOPCIONLOCALIDAD 1

int findLocalidadById(localidad* listlocalidad,int id,int* posicion, int lenLocalidad)
{
	int retorno=RETORNONEGATIVO;
	int i;
	for(i=0;i<lenLocalidad;i++)
	{
		if(listlocalidad[i].isEmpty==FULL && listlocalidad[i].id==id )
		{
			retorno=RETORNOPOSITIVO;
			*posicion=i;
			break;
		}
	}

	return retorno;
}

int initLocalidad(localidad* listlocalidad, int lenLocalidad)
{
	int retorno=-1;
	if(listlocalidad!=NULL)
	{
		int i;

		for(i=0;i<lenLocalidad;i++)
		{
			listlocalidad[i].isEmpty=EMPTY;
			retorno=0;
		}

	}

	return retorno;
}

int initZona(datoZona* listZona, int lenZona)
{
	int retorno=-1;
	if(listZona!=NULL)
	{
		int i;

		for(i=0;i<lenZona;i++)
		{
			listZona[i].isEmpty=EMPTY;
			retorno=0;
		}

	}

	return retorno;
}

int initDateCenso(datosCenso* listCenso, int lenDatosCenso)
{
	int retorno=-1;
	if(listCenso!=NULL)
	{
		int i;

		for(i=0;i<lenDatosCenso;i++)
		{
			listCenso[i].isEmpty=EMPTY;
			retorno=0;
		}

	}

	return retorno;
}

int addLocalidad(localidad* listalocalidad,char localidad[],int MaxLocalidad,int idLocalidad,int lenLocalidad)
{
	int retorno=RETORNONEGATIVO;
	for(int i=0;i<MaxLocalidad;i++)
	{
		if(listalocalidad[i].isEmpty==EMPTY)
		{
			listalocalidad[i].isEmpty=FULL;
			listalocalidad[i].id=idLocalidad;
			strncpy(listalocalidad[i].localidades,localidad,lenLocalidad);
			retorno=RETORNOPOSITIVO;
			break;
		}
	}
	return retorno;
}

int ingressZone(int* localidad, char zona[],int lenLocalidad,int lenCadena)
{
	int retorno=RETORNONEGATIVO;
	char auxChar[lenCadena];
	int auxLocalidad;

	if(utnGetNumero(&auxLocalidad, "Seleccione el numero que de localidad que corresponda o 0 para cancelar\n",
			"Error al seleccionar Localidad", "Opcion incorrecta. Desea reintentar?\n",0, lenLocalidad, REINTENTOS)==RETORNOPOSITIVO)
	{
		if(auxLocalidad==0)
		{
			puts("Se cancela la carga de ZONA");

		}
		else
		{
			if(utnIngressStringChar(auxChar, "\nIngrese la nueva zona : \n", lenCadena)==RETORNOPOSITIVO)
			{
				strncpy(zona,auxChar,lenCadena);
				*localidad=auxLocalidad;
				retorno=RETORNOPOSITIVO;
			}

		}

	}

	return retorno;
}

int addZone(datoZona* zona,int localidad,int idZona, char nombreZona[])
{
	int retorno=RETORNONEGATIVO;

	if(zona!=NULL)
	{
		zona->idCensista=0;
		zona->idZona=idZona;
		//listZona->estadoCenso=PENDIENTE;
		zona->localidadZona=localidad;
		strncpy(zona->zonaCenso,nombreZona,51);
		zona->idCensista=EMPTY;
		zona->isEmpty=FULL;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int utnIsEmptyOrFullZone(datoZona* listZona,int fullEmpty,int lenZona)
{
	int retorno=RETORNONEGATIVO;
	int i;
	for(i=0;i<lenZona;i++)
	{
		if(listZona[i].isEmpty==fullEmpty)
		{
			retorno=i;
			break;
		}
	}
	return retorno;
}

int utnIsEmptyOrFullDatCenso(datosCenso* listCenso,int fullEmpty,int lenDatoCenso)
{
	int retorno=RETORNONEGATIVO;
	int i;
	for(i=0;i<lenDatoCenso;i++)
	{
		if(listCenso[i].isEmpty==fullEmpty)
		{
			retorno=i;
			break;
		}
	}
	return retorno;
}

int assignZone(datoZona* zona,int idCensista)
{
	int retorno=RETORNONEGATIVO;
	if(zona != NULL )
	{
		zona->idCensista=idCensista;
		zona->estadoCenso=PENDIENTE;
	}

	return retorno;
}

int addDataZona(datoZona* zona,datosCenso* datoCenso,int idCensista,int censadosInSitu,int censadosVirtual, int ausentes)
{
	int retorno=RETORNONEGATIVO;
	if(datoCenso != NULL && zona != NULL)
	{
		datoCenso->idCensista=idCensista;
		datoCenso->ausentes=ausentes;
		datoCenso->censadosInSitu=censadosInSitu;
		datoCenso->censadosVirtual=censadosVirtual;
		datoCenso->isEmpty=FULL;
		zona->estadoCenso=FINALIZADO;
		zona->idCensista=idCensista;


		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int ingressDateCenso(int* ausentes, int* inSitu, int* virtual)
{
	int auxInt;
	int continuar=RETORNONEGATIVO;
	int flagOk=RETORNOPOSITIVO;
	int retorno=RETORNONEGATIVO;

	do{
		//ausentes
		if(utnGetNumero(&auxInt, "Ingrese la cantidad de ausentes en el censo\n",
				"Error al seleccionar Localidad", "Desea reintentar?",MINOPCIONLOCALIDAD, 10000, REINTENTOS)==RETORNOPOSITIVO)
		{
			*ausentes=auxInt;
		}
		else
		{
			flagOk=RETORNONEGATIVO;
			break;
		}
		//InSitu
		if(utnGetNumero(&auxInt, "Ingrese la cantidad censados InSitu en el censo\n",
				"Error al seleccionar Localidad", "Desea reintentar?",MINOPCIONLOCALIDAD, 10000, REINTENTOS)==RETORNOPOSITIVO)
		{
			*inSitu=auxInt;
		}
		else
		{
			flagOk=RETORNONEGATIVO;
			break;
		}
		//Virtual
		if(utnGetNumero(&auxInt, "Ingrese la cantidad cennsados virtual \n",
				"Error al seleccionar Localidad", "Desea reintentar?",MINOPCIONLOCALIDAD, 10000, REINTENTOS)==RETORNOPOSITIVO)
		{
			*virtual=auxInt;
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

int findZonaById(datoZona* list, int id,int* posicion,int lenZona)
{
	int retorno=RETORNONEGATIVO;
	int i;
	for(i=0;i<lenZona;i++)
	{
		if(list[i].isEmpty==FULL && list[i].idZona==id )
		{
			retorno=RETORNOPOSITIVO;
			*posicion=i;
			break;
		}
	}

	return retorno;
}

int findZonaByIdCensista(datoZona* list, int idCensista,int* posicion,int lenZona)
{
	int retorno=RETORNONEGATIVO;
	int i;
	for(i=0;i<lenZona;i++)
	{
		if(list[i].isEmpty==FULL && list[i].idCensista==idCensista )
		{
			retorno=RETORNOPOSITIVO;
			*posicion=i;
			break;
		}
	}

	return retorno;
}


