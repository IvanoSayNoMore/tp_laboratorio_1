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


int menu_altaPasajero(LinkedList* pArrayListPassenger);

#endif /* PUNTOSDEMENU_H_ */
