/*
 * Pedidos.c
 *
 *  Created on: 17 oct. 2021
 *      Author: rocio
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RJimenez.h"
#include "Cliente.h"
#include "Pedidos.h"

#define TAM_STR 256
#define TAM_INT 20



int AgregarNuevoPedido(Pedido* pedidos , int len, int idPedido, float cantidadKilos, Estado estado, Cliente cliente)
{
	int retorno;
	int i;

	retorno = -1;

	i = BuscarLugarLibrePedido (pedidos, len);

	pedidos[i].cliente = cliente;
	pedidos[i].estado = estado;
	pedidos[i].idPedido = idPedido;
	pedidos[i].cantidadKilos = cantidadKilos;
	pedidos->isEmpty = 1;

	return retorno;
}

int BuscarLugarLibrePedido (Pedido *arrayPedidos, int len)
{
	int i;
	int retorno;

	retorno = -1;

	for(i = 0; i < len; i++)
	{
		if(arrayPedidos[i].isEmpty == 0)
		{
			retorno = i;
			break;
		}
	}

	return retorno;
}
