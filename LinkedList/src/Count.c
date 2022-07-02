/*
 * Count.c
 *
 *  Created on: 30 jun 2022
 *      Author: Usuario Programador
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include "Count.h"
int count_BuscadorSalaUno(void* this)
{
	int retorno=-1;
	int auxSala;

	if(this!=NULL)
	{
		Pelicula_getSala(this, &auxSala);
		if(auxSala==1)
		{
			retorno=0;
		}
	}

	return retorno;
}



