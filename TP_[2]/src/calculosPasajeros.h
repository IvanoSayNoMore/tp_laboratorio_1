/*
 * calculosPasajeros.h
 *
 *  Created on: 1 may 2022
 *      Author: Usuario Programador
 */

#ifndef CALCULOSPASAJEROS_H_
#define CALCULOSPASAJEROS_H_


/**
 * \brief Calculadora de datos de pasajeros.
 * @param list recibe la lista de pasajeros a analizar y calcular
 * @param mayorAlPromedio devuelve cuantos pasajeros superan el promedio
 * @param totalPrecios devuelve la suma de los precios de todos los pasajeros
 * @param promedioPrecios devuelve el promedio de los pasajeros
 * @param len recibe el largo de la lista de pasajeros
 */
void flightCalculator(DateFlight* list,int* mayorAlPromedio,float* totalPrecios,float* promedioPrecios, int lenFlight);


#endif /* CALCULOSPASAJEROS_H_ */
