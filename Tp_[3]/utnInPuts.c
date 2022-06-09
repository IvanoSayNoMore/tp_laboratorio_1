/*
 * InPuts.c
 *
 *  Created on: 9 abr 2022
 *      Author: Usuario Programador
 */

#include "utnInPuts.h"
#define REINTENTOS 3
#define RETORNONEGATIVO -1
#define RETORNOPOSITIVO 0

/**
 * \brief Recorre stdin hasta \n o hasta maximo de "cadena"-1
 * @param cadena cadena Puntero al espacio de memoria donde se copia la cadena obtenida
 * @param longitud longitud Largo de la cadena
 * @return Retorna 0 si se obtiene una cadena. -1 Cuando no encuentra cadena
 */
static int myGets(char* cadena, int longitud);

/**
 *\brief Verifica que la cadena sea numerica
 * @param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * @return retorna 0 si obtiene cadena. -1 cuando no .
 */
static int getInt(int* pResultado);

/**
 * \brief Verifica si la cadena ingresada es numerica
 * @param cadena Cadena a ser analizada
 * @return Rotorna 1 si la cadena es numerica. 0, si no lo es.
 */
static int esNumerica(char* cadena);


static int esCaracter(char* cadena, int posicion);
////////////////////Fin declaracion Estaticas///////////////////////



static int myGets(char* cadena, int longitud)
{
	int retorno=-1;
	if(cadena!=NULL)
	{
		fflush(stdin);
		fgets(cadena,longitud,stdin);
		cadena[strlen(cadena)-1]='\0';
		retorno=0;
	}
	return retorno;
}


static int esNumerica(char* cadena)
{
	int retorno=-1;
	int i=0;
	if(cadena!=NULL)
	{

		for(;cadena[i] != '\0';i++)
		{
			if(i==0&&(cadena[i]=='-' || cadena[i] == '+' ))
			{
				continue;
			}
			if(i==0&&(cadena[i]==' '|| cadena[i]=='\n' || cadena==0))
			{
				break;
			}
			if(esCaracter(cadena, i)==0)
			{
				retorno=0;
				break;
			}
		}

	}

	return retorno;
}

static int esCaracter(char* cadena, int posicion)
{
	int retorno=-1;
	if(cadena[posicion]>'9' || cadena[posicion]<'0')
	{
		retorno=0;
	}
	return retorno;
}


static int getInt(int* pResultado)
{
	int retorno=-1;
	char buffer[1000];

	if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
	{
		retorno=0;
		*pResultado=atoi(buffer);
	}

	return retorno;
}

int getIntChar(char* pResultado)
{
	int retorno=-1;
	char buffer[1000];

	if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
	{
		retorno=0;
		strncpy(pResultado,buffer,1000);
	}

	return retorno;
}

int utnGetNumero(int* pNumeroIngresado, char* mensaje, char* mensajeError,char* mensajeSeguirNoSeguir, int minimo, int maximo, int reintentos)
{
	int retorno =-1;
	int buffer;
	int verificacionFinal;

	if(pNumeroIngresado!=NULL && mensaje!=NULL && mensajeError!=NULL && mensajeSeguirNoSeguir!=NULL
			&& minimo<=maximo && reintentos>=0)

		do
		{

			printf("%s",mensaje);
			if(getInt(&buffer)==0 && buffer>=minimo && buffer<=maximo)
			{
				*pNumeroIngresado=buffer;
				retorno=0;
				break;
			}

			if(reintentos!=0 && retorno!=0)
			{
				verificacionFinal=utnVerificacionConChar(mensajeSeguirNoSeguir,mensajeError, "\n",0);
				if(verificacionFinal==-1||verificacionFinal==-3)
				{
					reintentos=0;
					break;
				}
				else
				{
					if(verificacionFinal==0)
					{
						reintentos--;
					}
				}
			}
			else
			{
				puts("No queden intentos.\n");
			}


		}while(reintentos>=1);

	return retorno;
}

int utnVerificacionConChar(char* mensajeValidacion,char* mensajePorSi, char* mensajePorNo,int validacion)
{
	int retorno;
	char ingresoDeUsuario[5];
	int seguir;
	int reintentos=3;
	int valido;
	if(mensajeValidacion!=NULL && mensajePorSi!=NULL && mensajePorNo!=NULL)
	{
		do
		{
			if(reintentos==0)
			{
				puts("No quedan intentos\n");
				retorno = -2;
				break;
			}

			printf("%s",mensajeValidacion);
			if(myGets(ingresoDeUsuario, sizeof(ingresoDeUsuario))==0)
			{
				for(int i=0;i<sizeof(ingresoDeUsuario)-1;i++)
				{
					if(esCaracter(ingresoDeUsuario, i)==-1)
					{
						reintentos--;
						printf("Por favor, ingrese solo letras. Quedan %d intentos\n",reintentos);
						valido = 1;
						seguir = -1;
						break;
					}
					else
					{
						ingresoDeUsuario[i]=tolower(ingresoDeUsuario[i]);
						valido = 0;
					}

				}
			}
			if(valido==0)
			{
				if(strncmp(ingresoDeUsuario,"no",sizeof(ingresoDeUsuario))==validacion)
				{
					printf("\n %s \n",mensajePorNo);
					retorno = -1;
					seguir = 0;
				}
				else
				{
					if(strncmp(ingresoDeUsuario,"si",sizeof(ingresoDeUsuario))==validacion)
					{
						printf("\n %s \n",mensajePorSi);
						retorno = 0;
						seguir = 0;
					}
					else
					{
						printf("Respuesta incorrecta, quedan %d intentos\n",reintentos);
						reintentos--;
						seguir = -1;
					}
				}

			}//Fin if valido==0

		}while(seguir==-1);


	}//Fin if inicial

	return retorno;
}

int utnIngresarFlotante(char mensaje[],float* numeroFloat, int reintentos)
{
    char cadenaNumero[100];
    int retorno=0;
    int i;
    int largoCadena;
    int flagComa=0;
    int seguir;
    if(mensaje!=NULL)
    {
    	do{
    		printf("%s",mensaje);
			largoCadena=sizeof(cadenaNumero);
			if(myGets(cadenaNumero,largoCadena)==0)
			{
				if((cadenaNumero[0]==' '|| cadenaNumero[0]==0)==1)
				{
					puts("No se permiten espacios, o enter de primera\n");
					retorno=-1;
				}
				for(i=0;cadenaNumero[i] != '\0';i++)
				{
					if(esCaracter(cadenaNumero, i)==0)
					{
						if(cadenaNumero[i]=='.' && flagComa==0)
						{
							flagComa++;
							continue;
						}
						else
						{
							printf("\nNo se admiten dos comas o letras\n ");
							retorno=-1;
							break;
						}
					}
					else
					{
						seguir=1;
					}
				}//Fin For
			}//Fin primer IF

			if(retorno==-1)
			{
				if(reintentos>0)
				{
					if(utnVerificacionConChar("\nDesea reintentar ?? Si o No.\n", "Continua\n", "Se cancela el ingreso\n",0)==0)
					{
						reintentos--;
						flagComa=0;
						printf("Quedan %d intentos\n",reintentos);
						retorno=0;
						seguir=0;
					}
					else
					{
						retorno=-1;
						seguir=-1;
					}
				}
				else
				{
					puts("No quedan intentos disponibles\n");
					seguir=-1;
				}

			}

    	}while(seguir==0);

		if(retorno==0)
		{
			*numeroFloat=atof(cadenaNumero);
		}

    }


	return retorno;
}

int utnRecibeCadenaSoloCaracteres(char cadena[],char mensaje[],int reintentos,int tam)
{
	setbuf(stdout,NULL);
	char auxiliarString[51];
	int valido=0;
	int retorno=-1;
	int largo;

	if (cadena != NULL && mensaje != NULL)
	{
		do
		{
			if(reintentos==0)
			{
				retorno=-1;
				break;
			}
			printf(mensaje);
			myGets(auxiliarString, tam);
			largo=strnlen(auxiliarString,sizeof(tam));
			valido=0;
			if( largo > tam )
			{
				reintentos--;
				valido=1;
				printf("Ingreso demaciados caracteres. Quedan %d intentos\n",reintentos);
			}
			if(auxiliarString[0]==' '|| auxiliarString[0]=='\n' || largo==0)
			{
				reintentos--;
				valido=1;
				printf("Por favor, no ingrese espacios o enter en primer lugar. Quedan %d intentos\n",reintentos);
			}
			if(valido==0)
			{
				for(int i=0;auxiliarString[i]!='\0';i++)
				{
					if(esCaracter(auxiliarString, i)==-1)
					{
						reintentos--;
						printf("Por favor, ingrese solo letras. Quedan %d intentos\n",reintentos);
						valido=1;
						break;
					}

				}//Fin for

			}

		}while(valido!=0);

		if(valido==0)
		{
			strncpy(cadena,auxiliarString,tam);
			retorno=0;
		}

	}
	return retorno;
}



int utnIngresarAlfanumerico(char cadena[], char mensaje[],int reintentos, int tam)
{
	setbuf(stdout,NULL);
	char auxiliarString[tam];

	int valido=0;
	int retorno=-1;
	int largo;

	if(cadena != NULL && mensaje != NULL)
	{
		do
		{
			if(reintentos==0)
			{
				retorno=-1;
				break;
			}
			printf(mensaje);
			myGets(auxiliarString, tam);
			largo=strnlen(auxiliarString,sizeof(tam));

			if(largo>tam)
			{
				valido=1;
				puts("Ingreso demaciados caracteres\n");
				if(utnVerificacionConChar("Desea volver a intentar? si o no", "Continua\n", "Adios",0)==0)
				{
					puts("Vuelva a ingresar :\n");
					reintentos--;
				}
				else
				{
					break;
				}
			}

			if(auxiliarString[0]==' '|| auxiliarString[0]=='\n' || largo==0)
			{
				reintentos--;

				valido=1;
				printf("Por favor, no ingrese espacios o enter en primer lugar. Quedan %d intentos\n",reintentos);
				puts("Vuelva a ingresar :\n");
			}
			if(valido==0)
			{
				strncpy(cadena,auxiliarString,tam);
				retorno=0;
				break;
			}

		}while(reintentos>0);

	}

	return retorno;
}

int pasajeTodoAminusculaOmayusculaConNum(char cadena[], int validez)
{
	int retorno=-1;
	int i;
	int largoCadena;
	largoCadena=strlen(cadena);
	char cadenaAux[largoCadena];
		for(i=0;i<largoCadena;i++)
		{
			if(cadena[i]<9 || cadena[i]>0)
			{
				if(validez==0)
				{
					cadenaAux[i]=toupper(cadena[i]);
				}
				else
				{
					cadenaAux[i]=tolower(cadena[i]);
				}

			}
		}//Fin ford
	strncpy(cadena,cadenaAux,largoCadena);
	return retorno;

}
void utnToupper(char cadena[])
{

	int largoCadena;
	largoCadena=strlen(cadena);
	char cadenaAux[largoCadena];
	int flag=0;
	if(cadena!=NULL)
	{
		for(int i=0;i<=largoCadena;i++)
		{

			if(flag==0)
			{
				cadenaAux[i]=toupper(cadena[i]);
				flag++;
			}
			else
			{
				if(cadena[i]==' ')
				{
					cadenaAux[i]=cadena[i];
					flag=0;
				}
				else
				{
					cadenaAux[i]=tolower(cadena[i]);
				}
			}
		}//Fin For
		strncpy(cadena,cadenaAux,largoCadena);
	}
}

void contadorId(int* num)
{
	static int contador=0;
	contador++;
	*num=contador;
}

void contadorIdZone(int* num)
{
	static int contador=0;
	contador++;
	*num=contador;
}

int utnIngressStringChar(char name[], char mensaje[],int lenCadena)
{
	int retorno;
	char auxChar[lenCadena];
	if(utnRecibeCadenaSoloCaracteres(auxChar,mensaje, REINTENTOS, lenCadena)==RETORNONEGATIVO)
	{
		retorno=-1;
	}
	else
	{
		utnToupper(auxChar);
		strncpy(name,auxChar,lenCadena);
		retorno=0;
	}

	return retorno;
}

int utnIngressNameLastname(char name[], char mensaje[],int lenCadena)
{
	int retorno;
	char auxChar[lenCadena];
	if(utnRecibeCadenaSoloCaracteres(auxChar,mensaje, REINTENTOS, lenCadena)==RETORNONEGATIVO)
	{
		retorno=-1;
	}
	else
	{
		utnToupper(auxChar);
		strncpy(name,auxChar,lenCadena);
		retorno=0;
	}

	return retorno;
}
