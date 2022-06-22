/*
 * puntosDeMenu.h
 *
 *  Created on: 5 jun 2022
 *      Author: Usuario Programador
 */

#ifndef PUNTOSDEMENU_H_
#define PUNTOSDEMENU_H_
//"\nOpcion 1: Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"

int menu_cargaDatosPasajerosDesdeCsv(char* path , LinkedList* pArrayListPassenger);

int menu_cargaDatosPasajerosDesdeBinario(char* path , LinkedList* pArrayListPassenger);

int menu_altaPasajero(LinkedList* pArrayListPassenger);

int menu_modificarPasajero(LinkedList* pArrayListPassenger);

int menu_eliminarPasajero(LinkedList* pArrayListPassenger);

int menu_guardarBinario_Texto(LinkedList* pArrayListPassenger);

int menu_ordenarPasajero(LinkedList* pArrayListPassenger);

int menu_guardarArchivoCsv(LinkedList* pArrayListPassenger);

int menu_guardarArchivoBinario(LinkedList* pArrayListPassenger);
#endif /* PUNTOSDEMENU_H_ */
