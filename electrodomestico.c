/*
 * electrodomestico.c
 *
 *  Created on: 14 oct. 2020
 *      Author: Lucasdamiann
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "electrodomestico.h"
#include "utn.h"

void hardcodeoMarcas(eMarca *lista)
    {
    eMarca marcaElectro[] =
	{
	    {
	    1000, "SONY", 0
	    },
	    {
	    1001, "LILIANA", 0
	    },
	    {
	    1002, "GAFA", 0
	    },
	    {
	    1003, "PHILIPS", 0
	    },
	    {
	    1004, "WHIRLPOOL", 0
	    }
	};

    for (int i = 0; i < 5; i++)
	{
	lista[i] = marcaElectro[i];
	}
    }

int inicializarElectros(eElectrodomestico *list, int len)
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


int agregarElectro(eElectrodomestico *list, int len, int id, int serie,int idMarca,
	int modelo)
    {printf("vale %d",idMarca);
    int ret = -1;
    int position;

    if (list != NULL && len > 0)
	{
	position = get_FreeSpace(list, 200);

	list[position].idElectro = id;
	list[position].numSerie = serie;
	list[position].modelo = modelo;
	list[position].idMarca= idMarca;
	list[position].isEmpty = 0;
	ret = 0;
	}
    return ret;
    }

int removeElectro(eElectrodomestico *list, int len, int id)
    {
    int retorno = -1;
    if (list != NULL && len > 0)
	{
	for (int i = 0; i < len; i++)
	    {
	    if (list[i].idElectro == id && list[i].isEmpty == 0)
		{
		list[i].isEmpty = 1;
		retorno = 0;
		break;
		}

	    }
	}
    return retorno;
    }

int printElectros(eElectrodomestico *list, int len)
    {
    int retorno = -1;

    if (list != NULL && len > 0)
	{
	printf(
		"\n[MODELO]          [ID EQUIPO]          [NUM.SERIE]\n");
	for (int i = 0; i < len; i++)
	    {
	    if (list[i].isEmpty == 0)
		{

			printf(
				"\n»%-10d       »%-4.4d                »%-4.4d\n",
				list[i].modelo, list[i].idElectro,
				list[i].numSerie);



		}

	    }
	retorno = 0;
	}
    return retorno;
    }
int printMarcas(eMarca *lista, int len)
    {
    int retorno = -1;
    if (lista != NULL && len > 0)
	{
		printf("\n[MARCA]              [ID DE MARCA]\n");
	for (int i = 0; i < len; i++)
	    {
	    if (lista[i].isEmpty == 0)
		{

		    printf("\n»%-10s          »%-4.4d\n", lista[i].descripcion,
			    lista[i].idMarca);
		}
	    }
	retorno = 0;
	}
    return retorno;
    }
int printOneElectro(eElectrodomestico *list, eMarca *lista, int index, int id)
    {
    int retorno = -1;
    char buffer[DESC];
    if (list != NULL && lista != NULL)
	{
	printf(
		"\n[MARCA]          [MODELO]          [ID]          [NUM.SERIE]          \n");

	if (list[index].isEmpty == 0)
	    {
	    for (int i = 0; i < 5; i++)
		{
		if (id == lista[i].idMarca)
		    {
		    strcpy(buffer, lista[i].descripcion);
		    }
		}
	    printf(
		    "\n»%-10s      »%-10d       »%-4.4d         »%-4.4d             \n",
		    buffer, list[index].modelo, list[index].idElectro,
		    list[index].numSerie);
	    }

	retorno = 0;
	}
    return retorno;
    }

int findElectroById(eElectrodomestico *list, int len, int id)
    {
    int ret = -1;
    if (list != NULL && len > 0)
	{
	for (int i = 0; i < len; i++)
	    {
	    if (list[i].idElectro == id && list[i].isEmpty == 0)
		{
		ret = i;
		break;
		}
	    }
	}
    return ret;
    }
int ordenaElectrosConCriterio(eElectrodomestico *list, int len, int order)
    {
    int retorno = -1;
    eElectrodomestico aux;
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
		if ((list[i].modelo<list[i+1].modelo || list[i].numSerie<list[i+1].numSerie) && order == 0)//descendente
		    {
		    aux = list[i];
		    list[i] = list[i + 1];
		    list[i + 1] = aux;
		    retorno = 0;
		    flag = 0;
		    }
		else if ((list[i].modelo>list[i+1].modelo || list[i].numSerie>list[i+1].numSerie) && order == 1)//ascendente
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
