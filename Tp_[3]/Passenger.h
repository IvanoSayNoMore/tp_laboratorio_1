/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	float precio;
	char nombre[50];
	char apellido[50];
	char tipoPasajero[50];
	char codigoVuelo[50];
	char statusFlight[50];

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(int id,char* nombreStr,char* apellidoStr,float price,char* flyCode,char* tipoPasajeroStr,char* estadoVuelo);
void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this,char* statusFlight);
int Passenger_getEstadoVuelo(Passenger* this,char* statusFlight);

#endif /* PASSENGER_H_ */
