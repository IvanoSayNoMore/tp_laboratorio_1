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
#include "Peliculas.h"
#include "parser.h"
#include "utnInPuts.h"
#include "Controller.h"

#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define REINTENTOS 3
#define MAXIMOCHAR 51

int controller_loadFromText(char* path , LinkedList* pArrayListPelicula)
{
	int retorno = -2;
	FILE *pFile;

	if (path != NULL && pArrayListPelicula != NULL)
	{
		pFile = fopen(path, "r");
		if (pFile != NULL)
		{
			retorno = parser_PeliculaFromText(pFile, pArrayListPelicula);
			fclose(pFile);//mmmm
		}
		else
		{
			retorno=RETORNONEGATIVO;
			puts("error");
		}
	}
	else
	{
		puts("Error . -> path == NULL || pArrayListPassenger == NULL ");
	}
	return retorno;

}
int controller_saveAsText(char* path , LinkedList* pArrayListPelicula)
{
	int retorno = RETORNONEGATIVO;
	FILE *pFile;

	if (path != NULL && pArrayListPelicula != NULL)
	{
		pFile = fopen(path, "w+");
		if (pFile != NULL)
		{
			retorno = parser_guardaPeliculasCsv(pFile, pArrayListPelicula);

			fclose(pFile);
		}
		else
		{
			puts("Error pFile==NULL");
		}

	}

    return retorno;
}






int controller_ListPeliculas(LinkedList* pArrayListPeliculas)
{
    int retorno = RETORNONEGATIVO;
    int len;

    if(pArrayListPeliculas != NULL)
    {
    	len = ll_len(pArrayListPeliculas);

    	puts("|   ID    |   NOMBRE                 |     DiA      |   HORARIO  |     SALA     | CANTIDAD ENTRADS| Monto  |\n");

    	for(int i=0;i<len;i++)
    	{
    		retorno = controller_scanPeliculasParaImprimir(pArrayListPeliculas,i);
    	}
    }
    return retorno;
}

int controller_scanPeliculasParaImprimir(LinkedList* pArrayListPeliculas, int posicion)
{
	int retorno=RETORNONEGATIVO;
	Pelicula* pPelicula;
	Pelicula peliculaAux;
	char auxDia[51];
	if(pArrayListPeliculas != NULL && posicion > -1)
	{
		pPelicula = (Pelicula*)ll_get(pArrayListPeliculas, posicion);
		if(pPelicula != NULL
				&& Pelicula_getId(pPelicula, &peliculaAux.id_venta) 					  	 == RETORNOPOSITIVO
				&& Pelicula_getHora(pPelicula, peliculaAux.horario)							 == RETORNOPOSITIVO
				&& Pelicula_getNombre(pPelicula, peliculaAux.nombre_pelicula)				 == RETORNOPOSITIVO
				&& Pelicula_getDia(pPelicula, &peliculaAux.dia) 							 == RETORNOPOSITIVO
				&& Pelicula_getSala(pPelicula, &peliculaAux.sala)							 == RETORNOPOSITIVO
				&& Pelicula_getCantEntradas(pPelicula, &peliculaAux.cantidad_entradas)		 == RETORNOPOSITIVO
				&& Pelicula_getMonto(pPelicula, &peliculaAux.monto)							 == RETORNOPOSITIVO)
		{
			controller_convierteNum_a_Cadena(peliculaAux.dia, auxDia);

			printf("\n|  %5d  | %20s | %10s |  %10s | %5d | %5d  |  %.2f |"
					,peliculaAux.id_venta,peliculaAux.nombre_pelicula,auxDia,
					peliculaAux.horario,peliculaAux.sala,peliculaAux.cantidad_entradas,peliculaAux.monto);

			retorno=RETORNOPOSITIVO;
		}
	}

	return retorno;
}

int calcu_calculaMonto(void* pElement)
{
	int retorno=-1;
	int precioUnidad;
	float precio;

	Pelicula auxPelicula;
	if(pElement != NULL)
	{
		Pelicula_getDia(pElement, &auxPelicula.dia);

		Pelicula_getCantEntradas(pElement, &auxPelicula.cantidad_entradas);

		if(auxPelicula.dia>=1 || auxPelicula.dia<=3)
		{
			precioUnidad=240;
			printf("ok1");
		}
		else
		{
			//printf("ok");
			precioUnidad=350;
		}
		if(auxPelicula.cantidad_entradas>3)
		{
			precio=(float)(precioUnidad*10)/100;

		}
		Pelicula_setMonto(pElement, precio);

		retorno=0;
	}

	return retorno;
}

int controller_convierteNum_a_Cadena(int num, char* cadena)
{
	int retorno=-1;
	switch(num)
	{
	case 0:
		strcpy(cadena,"Domingo");
		break;
	case 1:
		strcpy(cadena,"Lunes");
		break;
	case 2:
		strcpy(cadena,"Martes");
		break;
	case 3:
		strcpy(cadena,"Miércoles");
		break;
	case 4:
		strcpy(cadena,"Jueves");
		break;
	case 5:
		strcpy(cadena,"Viernes");
		break;
	case 6:
		strcpy(cadena,"Sábado");
		break;
	}


	return retorno;
}














