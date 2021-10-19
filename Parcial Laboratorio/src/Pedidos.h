/*
 * Pedidos.h
 *
 *  Created on: 17 oct. 2021
 *      Author: rocio
 */

#ifndef PEDIDOS_H_
#define PEDIDOS_H_
#include "Cliente.h"
#include "Estado.h"


struct
{
	int idPedido;
	float cantidadKilos;
	int isEmpty;
	Estado estado;
	Cliente cliente;
}typedef Pedido;

int AgregarNuevoPedido(Pedido* pedidos , int len, int idPedido, float cantidadKilos, Estado estado, Cliente cliente);

int BuscarLugarLibrePedido (Pedido *arrayPedidos, int len);

#endif /* PEDIDOS_H_ */
