/*
 * validacion.c
 *
 *  Created on: 23 sep. 2020
 *      Author: Lucasdamiann
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "reparacion.h"

int utn_getName(char *aResultado, char *mensaje, char *mensajeError, int len,
	char minimo, char maximo, int retries)
    {
    int retorno = -1;
    char buffer[len];
    if (aResultado != NULL && mensaje != NULL && mensajeError != NULL
	    && minimo <= maximo && retries >= 0)
	{
	do
	    {
	    printf("%s", mensaje);
	    fflush(stdin);

	    if (myGets(buffer, sizeof(buffer)) == 0 && isName(buffer) == 1)
		{
		strupr(strncpy(aResultado, buffer, len));
		retorno = 0;
		break;
		}
	    else
		{
		printf("%s", mensajeError);
		retries--;
		if (retries == 0)
		    {
		    printf("\nNo hay mas reintentos\n");
		    }
		printf("\nCantidad de reintentos: %d\n", retries);
		}
	    }
	while (retries >= 0);
	}

    return retorno;
    }
int utn_getNumber(int *pResultado, char *mensaje, char *mensajeError,
	int minimo, int maximo, int reintentos)
    {
    int retorno = -1;
    int bufferInt;
    if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
	    && minimo <= maximo && reintentos > 0)
	{
	do
	    {
	    printf("%s", mensaje);

	    if (getInt(&bufferInt) == 0 && bufferInt >= minimo
		    && bufferInt <= maximo)
		{
		*pResultado = bufferInt;
		retorno = 0;
		break;
		}
	    else
		{
		printf("%s", mensajeError);
		reintentos--;
		}
	    }
	while (reintentos >= 0);
	}
    return retorno;
    }
int utn_getUnsignedNumber(int *pResultado, char *mensaje, char *mensajeError,
	int minimo, int maximo, int reintentos)
    {
    int retorno = -1;
    int bufferInt;
    if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
	    && minimo <= maximo && reintentos > 0)
	{
	do
	    {
	    printf("%s", mensaje);

	    if (getIntUnsigned(&bufferInt) == 0 && bufferInt >= minimo
		    && bufferInt <= maximo)
		{
		*pResultado = bufferInt;
		retorno = 0;
		break;
		}
	    else
		{
		printf("%s", mensajeError);
		reintentos--;
		}
	    }
	while (reintentos >= 0);
	}
    return retorno;
    }
float utn_getNumberFloat(float *pResultado, char *mensaje, char *mensajeError,
	float minimo, float maximo, int reintentos)
    {
    int retorno = -1;
    float bufferFloat;
    if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
	    && minimo <= maximo && reintentos >= 0)
	{
	do
	    {
	    printf("%s", mensaje);

	    if (getFloat(&bufferFloat) == 0 && bufferFloat >= minimo
		    && bufferFloat <= maximo)
		{
		*pResultado = bufferFloat;
		retorno = 0;
		break;
		}
	    else
		{
		printf("%s", mensajeError);
		reintentos--;
		}
	    }
	while (reintentos >= 0);
	}
    return retorno;
    }

int getInt(int *pResultado)
    {
    int retorno = -1;
    char buffer[4096];
    if (pResultado != NULL)
	{
	if (myGets(buffer, sizeof(buffer)) == 0 && isNumber(buffer) == 1)
	    {
	    *pResultado = atoi(buffer);
	    retorno = 0;

	    }
	}
    return retorno;
    }

int getIntUnsigned(int *pResultado)
    {
    int retorno = -1;
    char buffer[4096];
    if (pResultado != NULL)
	{
	if (myGets(buffer, sizeof(buffer)) == 0 && isValidNumber(buffer) == 1)
	    {
	    *pResultado = atoi(buffer);
	    retorno = 0;

	    }
	}
    return retorno;
    }

int getFloat(float *pResultado)
    {
    int retorno = -1;
    char buffer[4096];
    if (pResultado != NULL)
	{
	if (myGets(buffer, sizeof(buffer)) == 0 && isNumber(buffer) == 1)
	    {
	    *pResultado = atof(buffer);
	    retorno = 0;
	    }
	}
    return retorno;
    }

int isNumber(char *pResultado)
    {
    int contadorPuntos = 0;
    int retorno = 1;
    int i = 0;
    if (pResultado != NULL)
	{

	if (pResultado[0] == '-')
	    {
	    i = 1;
	    }

	for (; pResultado[i] != '\0'; i++)
	    {
	    if (pResultado[i] == '.')
		{
		contadorPuntos++;
		}
	    if (((pResultado[i] > '9' || pResultado[i] < '0')
		    && pResultado[i] != '.') || contadorPuntos > 1)
		{
		retorno = 0;
		break;
		}

	    }
	}
    return retorno;
    }

int isValidNumber(char *pResultado)
    {
    int retorno = 1;
    int i;
    for (i = 0; pResultado[i] != '\0'; i++)
	{
	if (pResultado[i] < '0' || pResultado[i] > '9')
	    {
	    retorno = 0;
	    break;
	    }
	}
    return retorno;
    }

int isName(char *aResultado)
    {
    int retorno = 1;

    if (aResultado != NULL)
	{
	for (int i = 0; aResultado[i] != '\0'; i++)
	    {
	    if ((aResultado[i] < 'A' || aResultado[i] > 'Z')
		    && (aResultado[i] < 'a' || aResultado[i] > 'z')
		    && aResultado[i] != ' ')
		{
		retorno = 0;
		break;
		}
	    }
	}
    return retorno;
    }

int myGets(char *aResultado, int longitud)
    {
    int retorno = -1;
    char bufferString[4096];
    if (aResultado != NULL && longitud > 0)
	{
	fflush(stdin);
	if (fgets(bufferString, sizeof(bufferString), stdin) != NULL)
	    {
	    if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1]
		    == '\n')
		{
		bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] =
			'\0';
		}
	    if (strnlen(bufferString, sizeof(bufferString)) <= longitud)
		{
		strncpy(aResultado, bufferString, longitud);
		retorno = 0;
		}
	    }
	}
    return retorno;
    }
void printArray(int *array, int len)
    {
    if (array != NULL && len > 0)
	{
	for (int i = 0; i < len; i++)
	    {
	    printf("%d\n", array[i]);

	    }
	}
    }
int orderArray(int *recibeArray, int len)
    {
    int retorno = -1;
    int aux;
    int flag = 0;
    int contador = 0;
    int nuevoLimite;

    if (recibeArray != NULL && len > 0)
	{
	nuevoLimite = len - 1;
	while (flag == 0)
	    {
	    flag = 1;
	    for (int i = 0; i < nuevoLimite; i++)
		{
		contador++;
		if (recibeArray[i] > recibeArray[i + 1])
		    {
		    aux = recibeArray[i];
		    recibeArray[i] = recibeArray[i + 1];
		    recibeArray[i + 1] = aux;
		    retorno = 0;
		    flag = 0;
		    }

		}
	    nuevoLimite--;
	    }
	retorno = contador;
	}
    return retorno;
    }
int get_ID(int valorId, int *id)
    {
    int ret = -1;
    int buffer;
    if (id != NULL)
	{
	buffer = valorId + 1;
	*id = buffer;
	ret = 0;
	}
    return ret;
    }
int get_FreeSpace(eElectrodomestico *list, int len)
    {
    int ret = -1;
    if (list != NULL && len > 0)
	{
	for (int i = 0; i < len; i++)
	    {
	    if (list[i].isEmpty == 1)
		{
		ret = i;
		break;
		}
	    }
	}
    return ret;
    }
int acumularFloat(estructura *list, float *valorFloat, int len)
    {
    int ret = -1;
    float acumFloat = 0;
    if (list != NULL && valorFloat != NULL && len > 0)
	{
	for (int i = 0; i < len; i++)
	    {
	    if (list[i].isEmpty == 0)
		{
		//acumSalary += list[i].salary;
		*valorFloat = acumFloat;
		ret = 0;
		}
	    }
	}
    return ret;
    }
int superanPromedio(estructura *list, float valorFloat, int len)
    {
    int counter = 0;
    int ret = -1;
    if (list != NULL && len > 0)
	{
	for (int i = 0; i < len; i++)
	    {
	    if (list[i].isEmpty == 0 && list[i].valor > valorFloat)
		{
		counter++;
		ret = counter;
		}
	    else if (list[i].isEmpty == 0 && list[i].valor == valorFloat)
		{
		ret = counter;
		}
	    else if (list[i].isEmpty == 1)
		{
		ret = counter;
		}
	    }
	}
    return ret;
    }
int promedioPorEstructura(estructura *list, float *pCalculoResultProm, int len)
    {
    int retorno = -1;
    float acumSalary = 0;
    int counSalary = 0;
    if (list != NULL && pCalculoResultProm != NULL && len > 0)
	{
	for (int i = 0; i < len; i++)
	    {
	    if (list[i].isEmpty == 0)
		{
		counSalary++;
		acumSalary += list[i].valor;
		}
	    }
	*pCalculoResultProm = acumSalary / counSalary;
	retorno = 0;
	}
    return retorno;
    }
int ordenaConCriterio(estructura *list, int len, int order)
    {
    int retorno = -1;
    estructura aux;
    int flag = 0;
    int nuevoLimite;
    if (list != NULL && len > 0)
	{
	nuevoLimite = len - 1;
	while (flag == 0)
	    {
	    flag = 1;
	    for (int i = 0; i < nuevoLimite; i++)
		{
		if (((strcmp(list[i].valorDeChar, list[i + 1].valorDeChar) < 0)
			&& order == 0)
			|| ((strcmp(list[i].valorDeChar,
				list[i + 1].valorDeChar) == 0)
				&& ((list[i].sector < list[i + 1].sector)
					&& order == 0)))
		    {
		    aux = list[i];
		    list[i] = list[i + 1];
		    list[i + 1] = aux;
		    retorno = 0;
		    flag = 0;
		    }
		else if (((strcmp(list[i].valorDeChar, list[i + 1].valorDeChar)
			> 0) && order == 1)
			|| ((strcmp(list[i].valorDeChar,
				list[i + 1].valorDeChar) == 0)
				&& ((list[i].sector > list[i + 1].sector)
					&& order == 1)))
		    {
		    aux = list[i];
		    list[i] = list[i + 1];
		    list[i + 1] = aux;
		    retorno = 0;
		    flag = 0;
		    }
		}
	    nuevoLimite--;
	    }
	}
    return retorno;
    }
int inicializarEstructura(eElectrodomestico *list, int len)
    {
    int retorno = -1;
    if (list != NULL && len > 0)
	{
	for (int i = 0; i < len; i++)
	    {

	    list[i].isEmpty = 1;
	    }
	retorno = 0;
	}
    return retorno;
    }
int agregarUsuario(eElectrodomestico *list, int len, int id, int serie,
	int modelo)
    {
    int ret = -1;
    int position;

    if (list != NULL && len > 0)
	{
	position = get_FreeSpace(list, 200);

	list[position].idElectro = id;
	list[position].numSerie = serie;
	list[position].modelo = modelo;
	list[position].isEmpty = 0;
	ret = 0;
	}
    return ret;
    }

int printVarios(eElectrodomestico *list, eMarca *lista,int idMarca, int len)
    {
    int retorno = -1;
    if (list != NULL && lista != NULL && len > 0)
	{
	printf(
		"\n[MARCA]          [MODELO] 	        [ID EQUIPO]          [NUM.SERIE]          \n");
	for (int i = 0; i < len; i++)
	    {
	    if (list[i].isEmpty == 0)
		{
		printf(
			"\n»%-10s       »%-10d         »%-4.4d          »%-4.4d             \n",
			lista[idMarca].descripcion, list[i].modelo, list[i].idElectro,
			list[i].numSerie);
		}

	    }
	retorno = 0;
	}
    return retorno;
    }



