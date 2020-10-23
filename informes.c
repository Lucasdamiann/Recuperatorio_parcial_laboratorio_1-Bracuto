/*
 * informes.c
 *
 *  Created on: 22 oct. 2020
 *      Author: Lucasdamiann
 */
#include <stdio.h>
#include <stdlib.h>
#include "electrodomestico.h"
#include "reparacion.h"

int printElectros2020(eElectrodomestico *list, int len)
    {
    int retorno = -1;

    if (list != NULL && len > 0)
	{
	printf(
		"\n[MODELO]          [ID EQUIPO]          [NUM.SERIE]\n");
	for (int i = 0; i < len; i++)
	    {
	    if (list[i].isEmpty == 0 && list[i].modelo==2020)
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

int printElectrosMarca(eElectrodomestico *list,int marca, int len)
    {
    int retorno = -1;

    if (list != NULL  && len > 0)
	{
	printf(
		"\n[MODELO]          [ID EQUIPO]          [NUM.SERIE]       [ID MARCA]\n");
	for (int i = 0; i < len; i++)
	    {
	    if (list[i].isEmpty == 0 && list[i].idMarca==marca)
		{

			printf(
				"\n»%-10d       »%-4.4d                »%-4.4d       »%-4.4d\n",
				list[i].modelo, list[i].idElectro,
				list[i].numSerie,list[i].idMarca);
		}

	    }
	retorno = 0;
	}
    return retorno;
    }

int printReparacionesEfectuadas(eReparacion *lista,eCliente*list, int serieElectro,int len)
    {
    int retorno = -1;
    if (lista != NULL && len > 0)
	{
	printf(
		"\n[SERVICIO]          [SERIE ELECTRODOMESTICO]          [ID CLIENTE]          [FECHA]\n");
	for (int i = 0; i < len; i++)
	    {
	    if (lista[i].isEmpty == 0 && lista[i].idCliente.isEmpty == 0 && lista[i].numSerieElectro==serieElectro)
		{
		printf(
			"\n»%-10d         »%-10.4d                       »%-4d                 »%d/%d/%4d\n",
			lista[i].idServ, lista[i].numSerieElectro,
			list[i].idCliente, lista[i].fecha.dia,
			lista[i].fecha.mes, lista[i].fecha.anio);
		}

	    }
	retorno = 0;
	}
    return retorno;
    }
int printReparacionesEfectuadas2018(eReparacion *lista,eServicio*list,eElectrodomestico*listas, int len)
    {
    int retorno = -1;
    if (lista != NULL && len > 0)
	{
	printf(
		"\n[SERVICIO]          [SERIE ELECTRODOMESTICO]                   [FECHA]\n");
	for (int i = 0; i < len; i++)
	    {
	    if (lista[i].isEmpty == 0 && lista[i].idCliente.isEmpty == 0 && listas[i].modelo==2018)
		{
		printf(
			"\n»%-10d         »%-10s                                »%d/%d/%4d\n",
			lista[i].idServ, list[i].descServicio,
			lista[i].fecha.dia,
			lista[i].fecha.mes, lista[i].fecha.anio);
		}

	    }
	retorno = 0;
	}
    return retorno;
    }
int printSinReparacionesEfectuadas(eReparacion *lista,eCliente*list,eElectrodomestico* listas,int len)
    {
    int retorno = -1;
    if (lista != NULL && len > 0)
	{
	printf(
		"\n[SERVICIO]          [SERIE ELECTRODOMESTICO]          [ID CLIENTE]          [FECHA]\n");
	for (int i = 0; i < len; i++)
	    {
	    if (lista[i].isEmpty == 1 && listas[i].isEmpty==0)
		{
		printf(
			"\n»%-10d         »%-10.4d                       »%-4d                 »%d/%d/%4d\n",
			lista[i].idServ, lista[i].numSerieElectro,
			list[i].idCliente, lista[i].fecha.dia,
			lista[i].fecha.mes, lista[i].fecha.anio);
		}

	    }
	retorno = 0;
	}
    return retorno;
    }
