/*
 * Peliculas.c
 *
 *  Created on: 30 jun 2022
 *      Author: Usuario Programador
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include "Peliculas.h"

#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define MAXIMOCHAR 51

Pelicula* Pelicula_new()
{
	return (Pelicula*) malloc(sizeof(Pelicula));
}
Pelicula* Pelicula_newParametros(int id,char* nombreStr,int dia,char* horario,int sala,int cantidad_entradas)
{

	Pelicula* punteroPelicula = NULL;
	punteroPelicula = Pelicula_new();


	if(punteroPelicula != NULL && nombreStr != NULL && nombreStr != NULL && id>0 )
	{

		Pelicula_setId(punteroPelicula,id);
		Pelicula_setNombre(punteroPelicula, nombreStr);
		Pelicula_setDia(punteroPelicula, dia);
		Pelicula_setHora(punteroPelicula, horario);
		Pelicula_setSala(punteroPelicula, sala);
		Pelicula_setCantEntradas(punteroPelicula, cantidad_entradas);

	}
	else
	{
		puts("PunteroPelicula == null");
	}

	return punteroPelicula;
}

void Pelicula_delete(Pelicula* this)
{
	free(this);
}

int Pelicula_setId(Pelicula* this,int id)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && id>0)
	{
		this->id_venta=id;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Pelicula_getId(Pelicula* this,int* id)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && id>0)
	{
		*id=this->id_venta;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Pelicula_setNombre(Pelicula* this,char* nombre)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && nombre!=NULL)
	{
		strncpy(this->nombre_pelicula,nombre,MAXIMOCHAR);
		retorno=RETORNOPOSITIVO;
	}
	return retorno;

}

int Pelicula_getNombre(Pelicula* this,char* nombre)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && nombre!=NULL)
	{
		strncpy(nombre,this->nombre_pelicula,MAXIMOCHAR);
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Pelicula_setDia(Pelicula* this,int dia)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && dia>0)
	{
		this->dia=dia;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Pelicula_getDia(Pelicula* this,int* dia)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && dia>0)
	{
		*dia=this->dia;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Pelicula_setHora(Pelicula* this,char* hora)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && hora!=NULL)
	{
		strncpy(this->horario,hora,MAXIMOCHAR);
		retorno=RETORNOPOSITIVO;
	}
	return retorno;

}

int Pelicula_getHora(Pelicula* this,char* hora)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && hora!=NULL)
	{
		strncpy(hora,this->horario,MAXIMOCHAR);
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Pelicula_setSala(Pelicula* this,int sala)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && sala>0)
	{
		this->sala=sala;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Pelicula_getSala(Pelicula* this,int* sala)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && sala>0)
	{
		*sala=this->sala;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Pelicula_setCantEntradas(Pelicula* this,int CantEntradas)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && CantEntradas>0)
	{
		this->cantidad_entradas=CantEntradas;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Pelicula_getCantEntradas(Pelicula* this,int* CantEntradas)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && CantEntradas>0)
	{
		*CantEntradas=this->cantidad_entradas;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}


int Pelicula_setMonto(Pelicula* this,float monto)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && monto>0)
	{
		this->monto=monto;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Pelicula_getMonto(Pelicula* this,float* monto)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && monto>0)
	{
		*monto=this->monto;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}
