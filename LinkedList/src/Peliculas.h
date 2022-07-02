/*
 * Peliculas.h
 *
 *  Created on: 30 jun 2022
 *      Author: Usuario Programador
 */

#ifndef PELICULAS_H_
#define PELICULAS_H_

typedef struct
{
	int id_venta;
	char nombre_pelicula[51];
	int dia;
	char horario[51];
	int sala;
	int cantidad_entradas;
	float monto;

}Pelicula;


Pelicula* Pelicula_new();
Pelicula* Pelicula_newParametros(int id,char* nombreStr,int dia,char* horario,int sala,int cantidad_entradas);
void Pelicula_delete(Pelicula* this);
int calculaPrecioEntrada(int dia,int cantidad, float* precio);
int Pelicula_setId(Pelicula* this,int id);
int Pelicula_getId(Pelicula* this,int* id);
int Pelicula_setNombre(Pelicula* this,char* nombre);
int Pelicula_getNombre(Pelicula* this,char* nombre);
int Pelicula_setDia(Pelicula* this,int dia);
int Pelicula_getDia(Pelicula* this,int* dia);
int Pelicula_setHora(Pelicula* this,char* hora);
int Pelicula_getHora(Pelicula* this,char* hora);
int Pelicula_setSala(Pelicula* this,int sala);
int Pelicula_getSala(Pelicula* this,int* sala);
int Pelicula_setCantEntradas(Pelicula* this,int CantEntradas);
int Pelicula_getCantEntradas(Pelicula* this,int* CantEntradas);
int Pelicula_setMonto(Pelicula* this,float monto);
int Pelicula_getMonto(Pelicula* this,float* monto);

#endif /* PELICULAS_H_ */
