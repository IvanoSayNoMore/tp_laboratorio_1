/*
 * Calculos.c
 *
 *  Created on: 18 may 2022
 *      Author: Usuario Programador
 */
#include "ArrayZona.h"
#include "ArrayCencista.h"
#include "Calculos.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY 0
#define FULL -1
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1

float dataCollection(datosCenso* datos, int lenDatosCenso)
{
	float retorno=RETORNONEGATIVO;
	int auxAusentes=0;
	int totalCensados=0;
	int auxInSitu=0;
	int auxVirtual=0;
	int auxCensistas=0;
	int flagOk=RETORNONEGATIVO;
	//float promedioDeCensosPorCensista;
	//float promedioAusentes;
	//float promedioVirtual;
	//float promedioInSitu;
	//int totalCensados;
	if(datos!=NULL)
	{
		for(int i=0;i<lenDatosCenso;i++)
			{
				if(datos[i].isEmpty==FULL)
				{
					auxAusentes+=datos[i].ausentes;
					auxVirtual+=datos[i].censadosVirtual;
					auxInSitu+=datos[i].censadosInSitu;
					datos[i].totalCensados=datos[i].censadosInSitu+datos[i].censadosVirtual;
					totalCensados+=datos[i].totalCensados;
					auxCensistas++;
					flagOk=RETORNOPOSITIVO;
				}
			}
		if(flagOk==RETORNOPOSITIVO)
		{
			retorno=promediar(auxCensistas, totalCensados);
		}

			//promedioAusentes=promediar(auxCensistas, auxAusentes);
			//promedioVirtual=promediar(auxCensistas,auxVirtual);
			//promedioInSitu=promediar(auxCensistas,auxInSitu);

			//totalCensados=auxAusentes+auxVirtual+auxInSitu;


	}

	return retorno;
}

float promediar(int valorPivot, int valorPromediar)
{
	float retorno;

	retorno=(float)valorPromediar/valorPivot;

	return retorno;

}












