/*
 * Cliente.c
 *
 *  Created on: 17 oct. 2021
 *      Author: rocio
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#define TAM_STR 256



int IniciarCliente (Cliente* list, int len)
{
	int retorno;
	int i;

	retorno = -1;

	for(i = 0; i < len; i++)
	{
		list[i].isEmpty = 0;
	}

	retorno = 0;

	return retorno;
}

int BuscarLugarLibreCliente (Cliente *arrayClientes, int len)
{
	int i;
	int retorno;

	retorno = -1;

	for(i = 0; i < len; i++)
	{
		if(arrayClientes[i].isEmpty == 0)
		{
			retorno = i;
			break;
		}
	}

	return retorno;
}

int AgregarNuevoCliente(Cliente* clientes, int len, int id, char nombre [TAM_STR], char cuit [TAM_STR], char direccion [TAM_STR], char localidad [TAM_STR])
{
	int retorno;
	int i;

	retorno = -1;

	i = BuscarLugarLibreCliente (clientes, len);

	strcpy(clientes[i].nombre, nombre);
	strcpy(clientes[i].cuit, cuit);
	strcpy(clientes[i].direccion, direccion);
	strcpy(clientes[i].localidad, localidad);
	clientes[i].id = id;
	clientes->isEmpty = 1;

	return retorno;
}

int MostrarClientes(Cliente *arrayClientes, int len)
{
	int retorno;
	int i;

	retorno = -1;

	for(i = 0; i < len; i++)
	{
		if(arrayClientes[i].isEmpty == 1)
		{
			MostrarUnCliente(arrayClientes[i]);
		}
	}

	return retorno;
}


int MostrarUnCliente (Cliente cliente)
{
		int retorno;
		retorno = 0;

		printf("%d\t", cliente.id);
		printf("%s\t",cliente.nombre);
		printf("%s\t", cliente.cuit);
		printf("%s\t", cliente.direccion);
		printf("%s\t", cliente.localidad);
		printf("\n");

		return retorno;
}


int EncontrarClientePorId(Cliente *arrayClientes, int len,int id)
{
	int retorno;
	int i;

	retorno = -1;

	for(i = 0; i < len; i++)
	{
		if(arrayClientes[i].id == id)
		{
			retorno = i;
			break;
		}
	}

	return retorno;
}
