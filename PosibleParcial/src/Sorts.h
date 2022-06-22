/*
 * libSorts.h
 *
 *  Created on: 10 jun 2022
 *      Author: Usuario Programador
 */

#ifndef SORTS_H_
#define SORTS_H_

int Sort_compareByApellido(void* pasajeroUno, void* pasajeroDos);

int Sort_compareByNombre(void* pasajeroUno, void* pasajeroDos);

int Sort_compareByPrecio(void* pasajeroUno, void* pasajeroDos);

int Sort_compareById(void* pasajeroUno, void* pasajeroDos);

int Sort_compareByTipoPasajero(void* pasajeroUno, void* pasajeroDos);

int Sort_compareByEstado(void* pasajeroUno, void* pasajeroDos);

int Sort_compareByCodigoVuelo(void* pasajeroUno, void* pasajeroDos);

#endif /* SORTS_H_ */
