/*
 * puntosDeMenu.c
 *
 *  Created on: 5 jun 2022
 *      Author: Usuario Programador
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "parser.h"
#include "Peliculas.h"

#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define MAXIMOCHAR 51

int parser_guardaPeliculasCsv(FILE* pFile , LinkedList* pArrayListPelicula)
{
	int retorno=RETORNONEGATIVO;
	Pelicula* pPelicula;
	Pelicula pelicula;
	int lenpArrayList;
	if(pFile != NULL && pArrayListPelicula != NULL)
	{
		lenpArrayList=ll_len(pArrayListPelicula);
		fprintf(pFile,"Id,nombre,dia,hora,sala,cantidad \n");
		for(int i=0;i<lenpArrayList+1;i++)
		{

			pPelicula = (Pelicula*)ll_get(pArrayListPelicula, i);
			if(Pelicula_getId(pPelicula, &pelicula.id_venta)==RETORNOPOSITIVO
					&& Pelicula_getNombre(pPelicula, pelicula.nombre_pelicula)==RETORNOPOSITIVO
					&& Pelicula_getDia(pPelicula, &pelicula.dia) == RETORNOPOSITIVO
					&& Pelicula_getHora(pPelicula, pelicula.horario) == RETORNOPOSITIVO
					&& Pelicula_getSala(pPelicula, &pelicula.sala) ==RETORNOPOSITIVO
					&& Pelicula_getCantEntradas(pPelicula, &pelicula.cantidad_entradas) ==RETORNOPOSITIVO
					&& Pelicula_getMonto(pPelicula, &pelicula.monto) ==RETORNOPOSITIVO
					)
			{
				fprintf(pFile,"%d,%s,%d,%s,%d,%d,%.2f\n",pelicula.id_venta,pelicula.nombre_pelicula,pelicula.dia,pelicula.horario,pelicula.sala,pelicula.cantidad_entradas,pelicula.monto);

				retorno=RETORNOPOSITIVO;
			}
		}
	}


	return retorno;
}


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PeliculaFromText(FILE* pFile , LinkedList* pArrayListPelicula)
{
	int retorno=RETORNONEGATIVO;
	Pelicula * pPelicula;
	char auxCabecera[200];
	char auxId[MAXIMOCHAR],auxName[MAXIMOCHAR],auxDia[MAXIMOCHAR];
	char horario[MAXIMOCHAR],auxSala[MAXIMOCHAR],auxCantidadEntradas[MAXIMOCHAR];
	int retScan;

	if(pFile != NULL && pArrayListPelicula != NULL)
	{
		fscanf(pFile,"%[^\n]\n",auxCabecera);//Titulo Datos
		do
		{
			retScan = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n"
					,auxId,auxName,auxDia,horario,auxSala,auxCantidadEntradas);
			if(retScan==6)
			{
				pPelicula = Pelicula_newParametros(atoi(auxId), auxName,atoi(auxDia),horario,atoi(auxSala),atoi(auxCantidadEntradas));

				if(pPelicula != NULL)
				{
					retorno = ll_add(pArrayListPelicula, pPelicula);
				}

			}
			else
			{
				break;
			}
		}while(!feof(pFile));

	}

    return retorno;
}
