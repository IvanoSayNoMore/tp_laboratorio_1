/*
 * printList.h
 *
 *  Created on: 15 may 2022
 *      Author: Usuario Programador
 */

#ifndef PRINTLIST_H_
#define PRINTLIST_H_

int printListCensistaByStatus(Person* listPerson,char mensaje[],int order,int lenPerson);

void printOneCensista(Person* person);

int printLocalidad(localidad* localidad,int lenLocalidad);

int printListCensistas(Person* listPerson,int lenPerson);

int printAllZone(datoZona* listDatoZona,Person* listPerson,datosCenso* listdatosCenso,localidad* localidad,int lenPerson,int lenLocalidad,int lenDatoCenso);

int printZonaLocalidad(datoZona * datoZona, localidad * listlocalidad,int lenLocalidad);

int printDatosCensados(Person * person, datosCenso *listDatosCenso, int lenDatosCenso);

int printPersonByLocalidad(datoZona* listDatoZona,Person* listPerson,datosCenso* listdatosCenso,localidad* localidad,int lenPerson,int lenLocalidad,int lenDatoCenso);

int printPersonByCantidadCensados(datosCenso* listDatosCenso,Person* listPerson, int lenDatosCenso);

int printZonaById(datoZona* datoZona, int lenZona);

int printOneLocalidad(localidad* localidad);

void printPersonByLastname(Person* listperson,int lenPerson);

#endif /* PRINTLIST_H_ */
