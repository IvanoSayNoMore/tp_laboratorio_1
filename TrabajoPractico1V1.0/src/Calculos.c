/*
 * Calculos.c
 *
 *  Created on: 8 abr 2022
 *      Author: Usuario Programador
 */
#include "Calculos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define AUMENTO 1.25
#define DESCUENTO 0.9
#define BITCOIN 4606954.55

void utnCalcularValores(float parametroPivot, float parametroA, float parametroB,float* parametroAconDescuento,
		float* parametroBconDescuento,float* parametroAconAumento,float* parametroBconAumento,float* valorPorUnidadParametroB,
		float* valorPorUnidadParametroA,float* difDeValores,float* parametroABitcoin, float* parametroBBitcoin)
{
	float valorAux;

	porcentajeDeUnValor(parametroA, AUMENTO,&valorAux);
	*parametroAconAumento=valorAux;
	porcentajeDeUnValor(parametroB, AUMENTO,&valorAux);
	*parametroBconAumento=valorAux;

	porcentajeDeUnValor(parametroA, DESCUENTO,&valorAux);
	*parametroAconDescuento=valorAux;
	porcentajeDeUnValor(parametroB, DESCUENTO,&valorAux);
	*parametroBconDescuento=valorAux;

	valorUnitario(parametroB,parametroPivot,&valorAux);
	*valorPorUnidadParametroB=valorAux;
	valorUnitario(parametroA,parametroPivot,&valorAux);
	*valorPorUnidadParametroA=valorAux;

	diferenciaDeValores(parametroA,parametroB,&valorAux);
	*difDeValores=valorAux;

	valorAbitcoin(parametroA,&valorAux);
	*parametroABitcoin=valorAux;
	valorAbitcoin(parametroB,&valorAux);
	*parametroBBitcoin=valorAux;
}

void porcentajeDeUnValor(float valorInicial, float valorPorcentaje, float* valorResultado)
{
	*valorResultado=(float)valorInicial*valorPorcentaje;
}

void valorAbitcoin(float valorInicial,float* valorABitcoin)
{
	*valorABitcoin=(float)valorInicial/BITCOIN;
}

void valorUnitario(float valorInicial,  float undiad, float* valorPorUnidad)
{

	*valorPorUnidad=valorInicial/undiad;
}

void diferenciaDeValores(float valorA, float valorB, float* valorResultado)
{
	if(valorA>valorB||valorA==valorB)
	{
		*valorResultado=valorA-valorB;
	}
	else
	{
		*valorResultado=valorB-valorA;
	}
}

