/*
 * SortHead.h
 *
 *  Created on: 18 may 2022
 *      Author: Usuario Programador
 */

#ifndef SORTHEAD_H_
#define SORTHEAD_H_


int sortPersonByLastName(Person* listPerson, int lenPerson);

void soap(Person* list,int posicionA, int posicionB);

int sortPersonByCantidadCensados(datosCenso* datos, int lenDatosCenso);

void soapDatoCenso(datosCenso* list,int posicionA, int posicionB);

void sortPersonByDireccion(Person* person, int lenPerson);
#endif /* SORTHEAD_H_ */
