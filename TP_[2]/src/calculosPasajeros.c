/*
 * calculosPasajeros.c
 *
 *  Created on: 1 may 2022
 *      Author: Usuario Programador
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#define EMPTY 0
#define FULL -1
void calculosPasajeros(Passenger* list, int* mayorAlPromedio,float* totalPrecios,float* promedioPrecios, int len)
{

	int i;
	int auxTotalPasajeros=0;
	float auxTotalSumaDePrecios=0;
	int auxMayoresAlPromedio=0;
	float promedio;

	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty==FULL)
		{
			auxTotalPasajeros++;
			auxTotalSumaDePrecios+=list[i].price;
		}
	}
	promedio=auxTotalSumaDePrecios/(float)auxTotalPasajeros;
	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty==FULL && list[i].price>promedio)
		{
			auxMayoresAlPromedio++;
		}
	}
	*mayorAlPromedio=auxMayoresAlPromedio;
	*totalPrecios=auxTotalSumaDePrecios;
	*promedioPrecios=promedio;

}
