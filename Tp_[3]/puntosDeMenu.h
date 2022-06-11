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

<<<<<<< HEAD
int menu_cargaDatosPasajerosDesdeBinario(char* path , LinkedList* pArrayListPassenger);

=======
>>>>>>> 6ac921560a5d814f71475b007036fc0c702d9e3c
int menu_altaPasajero(LinkedList* pArrayListPassenger);

int menu_modificarPasajero(LinkedList* pArrayListPassenger);

int menu_eliminarPasajero(LinkedList* pArrayListPassenger);

<<<<<<< HEAD
int menu_guardarBinario_Texto(LinkedList* pArrayListPassenger);

int menu_ordenarPasajero(LinkedList* pArrayListPassenger);
=======
>>>>>>> 6ac921560a5d814f71475b007036fc0c702d9e3c
#endif /* PUNTOSDEMENU_H_ */
