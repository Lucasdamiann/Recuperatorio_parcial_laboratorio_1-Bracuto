/*
 * reparacion.c
 *
 *  Created on: 14 oct. 2020
 *      Author: Lucasdamiann
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reparacion.h"
#include "utn.h"

void hardcodeoServicio(eServicio *list)
    {
    eServicio tipoServicio[] =
	{
	    {
	    20000, "GARANTIA", 250
	    },
	    {
	    20001, "MANTENIM.", 500
	    },
	    {
	    20002, "REPUESTOS", 400
	    },
	    {
	    20003, "REFACCION", 600
	    }
	};
    for (int i = 0; i < 4; i++)
	{
	list[i] = tipoServicio[i];
	}
    }

int printServicios(eServicio *list, int len)
    {
    int retorno = -1;
    if (list != NULL && len > 0)
	{
	printf("\n[ID]            [SERVICIO] 	        [PRECIO]            \n");
	for (int i = 0; i < len; i++)
	    {
	    printf("\n»%-10d     »%-10s             »$%-4.d        \n",
		    list[i].idServicio, list[i].descServicio, list[i].precio);
	    }

	retorno = 0;
	}
    return retorno;
    }
int agregarReparacion(eReparacion *list, int len, int idRep,
	int servicio, int numSerieElectro)
    {
    int ret = -1;
    int position;

    if (list != NULL && len > 0)
	{
	position = get_FreeSpaceR(list, QTY_ELEC);
	if (validaFecha(list, position, len) == 0)
	    {
	    list[position].id = idRep;
	  //  list[position].idCliente.idCliente = cliente;
	    list[position].idServ = servicio;
	    list[position].numSerieElectro = numSerieElectro;
	    list[position].isEmpty = 0;
	    ret = 0;
	    }
	}
    return ret;
    }
int get_FreeSpaceR(eReparacion *list, int len)
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
void hardcodeoCliente(eCliente *list, int len)
    {
    eCliente cliente[] =
	{
	    {
	    4001, "Franco", "Armani", 0
	    },
	    {
	    4002, "Javier", "Pinola", 0
	    },
	    {
	    4003, "Milton", "Casco", 0
	    },
	    {
	    4004, "Gonzalo", "Montiel", 0
	    },
	    {
	    4005, "Enzo", "Perez", 0
	    },
	    {
	    4006, "Paulo", "Diaz", 0
	    }
	};

    for (int i = 0; i < len; i++)
	{
	list[i].idCliente = cliente[i].idCliente;
	strncpy(list[i].nombreCliente, cliente[i].nombreCliente,
		(sizeof(cliente[i].nombreCliente)));
	strncpy(list[i].apellidoCliente, cliente[i].apellidoCliente,
		(sizeof(cliente[i].apellidoCliente)));
	list[i].isEmpty = cliente[i].isEmpty;
	}
    }
int printClientes(eCliente *lista, int len)
    {
    int retorno = -1;
    if (lista != NULL && len > 0)
	{
	printf("\n[NOMBRE]          [APELLIDO]          [ID CLIENTE]\n");
	for (int i = 0; i < len; i++)
	    {
	    printf("\n»%-10s       »%-10s         »%-4.4d\n",
		    lista[i].nombreCliente, lista[i].apellidoCliente,
		    lista[i].idCliente);
	    }
	retorno = 0;
	}
    return retorno;
    }
int printReparaciones(eReparacion *lista,eCliente*list, int len)
    {
    int retorno = -1;
    if (lista != NULL && len > 0)
	{
	printf(
		"\n[SERVICIO]          [SERIE ELECTRODOMESTICO]          [ID CLIENTE]          [FECHA]\n");
	for (int i = 0; i < len; i++)
	    {
	    if (lista[i].isEmpty == 0 && lista[i].idCliente.isEmpty == 0)
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
int inicializarReparacion(eReparacion *list, int len)
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
int validaFecha(eReparacion *list, int index, int len)
    {
    int ret = -1;
    int dia;
    int mes;
    int anio;
    int reintentos=2;

    if (list != NULL && len > 0)
	{
	do
	    {
	if (utn_getNumber(&dia, "\nINGRESE DIA: ", "\nDIA INCORRECTO", 1, 31, 2)
		== 0
		&& (utn_getNumber(&mes, "\nINGRESE MES: ", "\nMES INCORRECTO",
			1, 12, 2) == 0)
		&& (utn_getNumber(&anio, "\nINGRESE AÑO: ", "\nAÑO INCORRECTO",
			1900, 2020, 2) == 0))
	    {
	    if (((anio > 1900 && anio <= 2020))
		    && (((mes == 4 || mes == 6 || mes == 9 || mes == 11)
			    && dia < 31)
			    || ((mes == 1 || mes == 3 || mes == 5 || mes == 7
				    || mes == 8 || mes == 10 || mes == 12)
				    && dia <= 31) || (mes == 2 && dia < 30)))
		{

		list[index].fecha.dia = dia;
		list[index].fecha.mes = mes;
		list[index].fecha.anio = anio;

		printf("\nLA FECHA SELECCIONADA ES: %d/%d/%d\n", dia, mes, anio);

		ret = 0;
		break;
		}
	    else
		{
		reintentos--;
		printf("\nVALOR DE FECHA INCORRECTO\n");
		}

	    }
	    }while(reintentos>0);
	}
    return ret;
    }

