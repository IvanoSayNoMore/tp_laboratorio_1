/*
 * PuntoDeMenu.h
 *
 *  Created on: 16 may 2022
 *      Author: Usuario Programador
 */

#ifndef PUNTODEMENU_H_
#define PUNTODEMENU_H_

int menuItemEnterPerson(Person* listPerson,int lenPerson);
int menuItemChangePerson(Person* listPerson, int lenPerson);
int menuItemDeletPerson(Person* listPerson, int lenPerson);
int menuItemAddZona(datoZona* listZona,  localidad* localidad,int lenZona,int lenLocalidad);
int menuItemAssignZona(datoZona* listZona,Person* listPerson, int lenZona,int lenPerson);
int menuItemAddDataZona(datoZona* listZona,datosCenso* listCenso,Person* listPerson, int lenZona,int lenPerson);
int menuItemOrdenamientos(datoZona* listZona,datosCenso* listCenso,Person* listPerson, int lenZona,int lenPerson);
int menuItemPrintCensistas(Person* listPerson,int lenPerson);
int menuItemInformes(datoZona* listZona,datosCenso* listCenso,Person* listPerson,localidad* localidad, int lenZona,int lenPerson);

int menuItemHardCode(datoZona* listZona,datosCenso* listCenso,Person* listPerson, int lenZona,int lenPerson);
#endif /* PUNTODEMENU_H_ */
