/*
 * ImprimirMostrar.c
 *
 *  Created on: 9 abr 2022
 *      Author: Usuario Programador
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void utnMostrarResultados(float parametroPivot, float parametroA, float parametroB,float parametroAconDescuento,
		float parametroBconDescuento,float parametroAconAumento,float parametroBconAumento,float valorPorUnidadParametroB,
		float valorPorUnidadParametroA,float difDeValores,float parametroABitcoin, float parametroBBitcoin)
{
	printf(	"KMs Ingresados...............: %.2f\n\n",parametroPivot);

	printf(	"Precio Aerolineas............: %.2f\n"
			"Precio con tarjeta de débito.: %.2f\n"
			"Precio con tarjeta de crédito: %.2f\n"
			"Precio a Bitcoin.............: %.4f\n"
			"Precio Unitario..............: %.2f\n\n",parametroA,parametroAconDescuento,parametroAconAumento,parametroABitcoin,valorPorUnidadParametroA);

	printf(	"Precio Latam.................: %.2f\n"
			"Precio con tarjeta de débito.: %.2f\n"
			"Precio con tarjeta de crédito: %.2f\n"
			"Precio a Bitcoin.............: %.4f\n"
			"Precio Unitario..............: %.2f\n",parametroB,parametroBconDescuento,parametroBconAumento,parametroBBitcoin,valorPorUnidadParametroB);

	printf(	"\nLa diferencia es de..........: %.2f \n\n",difDeValores);

}

