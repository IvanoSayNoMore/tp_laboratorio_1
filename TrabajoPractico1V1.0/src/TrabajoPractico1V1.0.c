/*
 ============================================================================
 Name        : 0.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Calculos.h"
#include "InPut.h"
#include "ImprimirMostrar.h"
#define MINIMODEKM 1500
#define MINIMO 15000
#define MAXIMO 9999999
#define REINTENTOS 3
#define RETORNONEGATIVO 0
#define KMFORZADOS 7090
#define PRECIOAREOLINEASHARDC 762965
#define PRECIOLAMATHARDC 159339

int main(void) {
	setbuf(stdout, NULL);

	int retornoGetNumero;
	char salir;
	int salida;
	float aerolineasConDebito;
	float latamConDebito;
	float diferenciaDePrecios;
	float precioPorKmAerolineas;
	float precioPorKmLatam;
	float aerolineasConCredito;
	float latamConCredito;
	float aeroBitcoin;
	float latamBitcoin;
	float KM;
	float precioLatam;
	float precioAerolineas;
	int flagKm=0;
	int flagCalculos=0;
	int flagVuelos=0;
	int opcion;

	do{
		printf("\n1- Ingrese (KM=");
		if(flagKm!=0)
		{
			printf("%2.f)\n",KM);
		}
		else
		{
			printf("X)\n");
		}//Vista de KM

		printf("2- Ingresar Precio de Vuelos \n");
		if(flagVuelos!=0)
		{
			printf("(Aerolineas=%2.f , LATAM=%2.f) \n",precioAerolineas, precioLatam);
		}
		else
		{
			printf("(Aerolineas=X , LATAM=Y)\n");
		}//Vista de precios

		printf("3- Calcular costos del vuelo\n");

		printf("4- Mostrar Costos \n");

		printf("5- Carga Forzada\n");

		printf("6- Salir\n");
		scanf("%d",&opcion);//Seleccion de usuario
		fflush(stdin);//Por si ingresa caracter

		switch(opcion)
		{
		case 1:
			retornoGetNumero=(utnGetNumero(&KM,"Ingrese los KM a recorrer\n","Recuerde que el minimo de km son 1500.\n Ingrese solo numeros\n"
					,"Error en la carga de datos, desea intentar nuevamente?\n",MINIMODEKM, MAXIMO, REINTENTOS)==0);

			if(retornoGetNumero==RETORNONEGATIVO)
			{

				puts("Se cancela la operacion y se reinician los KM\n");
				flagKm=0;
			}
			else
			{
				flagKm++;
			}
			break;

		case 2:

			retornoGetNumero=(utnGetNumero(&precioAerolineas,"Ingrese precio del vuelo de AEROLINEAS:\n"
					,"Ingrese solo numeros. El precio minimo es de 15000\n","Error en la carga de datos, desea intentar nuevamente?\n"
					,MINIMO, MAXIMO, REINTENTOS)==0);
			if(retornoGetNumero==RETORNONEGATIVO)
			{
				puts("Se cancela la operacion\n");
				break;
			}
			else
			{
				flagVuelos++;
			}

			retornoGetNumero=(utnGetNumero(&precioLatam,"Ingrese precio del vuelo de LATAM:\n"
					,"Ingrese solo numeros. El precio minimo es de 15000\n","Error en la carga de datos, desea intentar nuevamente?\n"
					,MINIMO, MAXIMO, REINTENTOS)==0);
			if(retornoGetNumero==RETORNONEGATIVO)
			{
				puts("Se cancela la operacion\n");
				flagVuelos=0;
				break;
			}
			break;

		case 3:
			if(flagKm !=0 && flagVuelos!=0)
			{
				utnCalcularValores(KM,precioAerolineas,precioLatam,&aerolineasConDebito,&latamConDebito,
								&aerolineasConCredito,&latamConCredito,&precioPorKmLatam,
								&precioPorKmAerolineas,&diferenciaDePrecios,&aeroBitcoin,&latamBitcoin);
				flagCalculos++;
				puts("Se han calculado los costos exitosamente.\n\n");
			}
			else
			{
				printf("Aun faltan cargar Datos\n");
			}
			break;

		case 4:
			if(flagCalculos)
			{
				utnMostrarResultados(KM,precioAerolineas,precioLatam,aerolineasConDebito,latamConDebito,
						aerolineasConCredito,latamConCredito,precioPorKmLatam,precioPorKmAerolineas,diferenciaDePrecios,aeroBitcoin,latamBitcoin);

				flagCalculos=0;
				flagKm=0;
				flagVuelos=0;
			}
			else
			{
				printf("Aun faltan cargar y/o calcular los datos");
			}
			break;

		case 5:
			utnCalcularValores(KMFORZADOS,PRECIOAREOLINEASHARDC,PRECIOLAMATHARDC,&aerolineasConDebito,&latamConDebito,
											&aerolineasConCredito,&latamConCredito,&precioPorKmLatam,
									  		&precioPorKmAerolineas,&diferenciaDePrecios,&aeroBitcoin,&latamBitcoin);

			utnMostrarResultados(KMFORZADOS,PRECIOAREOLINEASHARDC,PRECIOLAMATHARDC,aerolineasConDebito,latamConDebito,
					aerolineasConCredito,latamConCredito,precioPorKmLatam,
					precioPorKmAerolineas,diferenciaDePrecios,aeroBitcoin,latamBitcoin);


			break;

		case 6:
			salida=utnVerificacionConChar("Seguro desea salir  ?s o n \n","\n ADIOS \n");
			if(salida==-1)
			{
				salir='s';
				break;
			}

			break;
		default:
			puts("\n\nError en la seleccion de la opcion\n\n");
			break;

		}//fin swhitch
	}while(salir!='s');//Fin Menu
	return EXIT_SUCCESS;
}

