/*
 ============================================================================
 Name        : Parcial1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayCencista.h"
#include "ArrayZona.h"
#include "utnInPuts.h"
#include "PuntoDeMenu.h"
#include "printList.h"
#define MINIMOOPCION 1
#define MAXIMOOPCION 11
#define MAXIMOCENSISTAS 10
#define MAXIMOZONAS 30
#define MAXIMOLOCALIDADES 5
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define REINTENTOS 3

int main(void) {
	setbuf(stdout, NULL);
    int salir;
    int opcion;

	Person datosPersona[MAXIMOCENSISTAS];
	datoZona datosZona[MAXIMOZONAS];
	datosCenso datosCenso[MAXIMOZONAS];
	localidad localidades[MAXIMOLOCALIDADES];

	initPerson(datosPersona, MAXIMOCENSISTAS);
	initZona(datosZona, MAXIMOZONAS);
	initDateCenso(datosCenso, MAXIMOZONAS);
	initLocalidad(localidades, MAXIMOLOCALIDADES);

	addLocalidad(localidades, "Avellaneda", MAXIMOLOCALIDADES, 1, 51);
	addLocalidad(localidades, "Lanus", MAXIMOLOCALIDADES, 2, 51);
	addLocalidad(localidades, "Gerli", MAXIMOLOCALIDADES, 3, 51);
	addLocalidad(localidades, "Dominico", MAXIMOLOCALIDADES, 4, 51);
	addLocalidad(localidades, "Sarandi", MAXIMOLOCALIDADES, 5, 51);

    do{
    	if(utnGetNumero(&opcion, "\nOpcion 1: Cargar censista\nOpcion 2: Modificar datos de censista \nOpcion 3: Baja censista\nOpcion 4: Cargar Zona\nOpcion 5: Asignar Zona\nOpcion 6: Cargar datos \nOpcion 7: Mostrar censista\nOpcion 8: Mostrar Zonas\nOpcion 9: INFORMES \n10-HARDCODE\n"
    			,"", "Error al ingresar Opcion. Desea reintentar?Ingrese SI si desea continuar.\n", MINIMOOPCION,
				MAXIMOOPCION, REINTENTOS)==RETORNOPOSITIVO)
    	{
    	 	switch(opcion)
			{

			case 1://Cargar Censista
				menuItemEnterPerson(datosPersona, MAXIMOCENSISTAS);
				break;

			case 2://Modificar
				menuItemChangePerson(datosPersona, MAXIMOCENSISTAS);
					break;

			case 3://Borrar
				menuItemDeletPerson(datosPersona, MAXIMOCENSISTAS);
					break;

			case 4://Cargar Zona
				menuItemAddZona(datosZona, localidades, MAXIMOZONAS, MAXIMOLOCALIDADES);
					break;

			case 5://Asignar Zona
				menuItemAssignZona(datosZona, datosPersona, MAXIMOZONAS, MAXIMOCENSISTAS);
				   break;

			case 6://Cargar datos
				menuItemAddDataZona(datosZona, datosCenso, datosPersona, MAXIMOZONAS, MAXIMOCENSISTAS);
				break;

			case 7://Mostrar Censistas
				menuItemPrintCensistas(datosPersona, MAXIMOCENSISTAS);
				break;
			case 8:
				printAllZone(datosZona, datosPersona, datosCenso, localidades, MAXIMOCENSISTAS, MAXIMOLOCALIDADES, MAXIMOZONAS);
				//menuItemOrdenamientos(datosZona, datosCenso, datosPersona, MAXIMOZONAS, MAXIMOCENSISTAS);
				break;
			case 9:
				menuItemInformes(datosZona, datosCenso, datosPersona, localidades, MAXIMOZONAS, MAXIMOCENSISTAS);
				break;
			case 10://LA PRUEBA DE FUEGO
				menuItemHardCode(datosZona, datosCenso, datosPersona, MAXIMOZONAS, MAXIMOCENSISTAS);
				break;
			case 11:
				menuItemOrdenamientos(datosZona, datosCenso, datosPersona, MAXIMOZONAS, MAXIMOCENSISTAS);
				break;
			default:
				puts("Error en la seleccion\n");
				break;

			}//Fin Switch

    	}//Fin if elegir opcion
    	else
    	{
    		puts("\n Adios \n");
    		salir=-2;
    	}

    }while(salir!=-2);


	return EXIT_SUCCESS;
}
