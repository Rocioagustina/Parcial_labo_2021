/*
 * RJimenez.h
 *
 *  Created on: 14 oct. 2021
 *      Author: rocio
 */

#ifndef RJIMENEZ_H_
#define RJIMENEZ_H_
#define TAM_STR 256
#define TAM_INT 20
#define TAM_CUIT 20
#include "Cliente.h"
#include "Estado.h"
#include "Pedidos.h"


int ObtenerString(char mensaje [TAM_STR], char nombre [TAM_STR]);

int ValidarNombre(char nombre [TAM_STR]);

int PedirFloat(char mensaje [TAM_STR], float *operando);

int ValidarFloat (char operando [TAM_INT]);

int PedirInt(char mensaje [TAM_STR], int *operando);

int ValidarInt(char operando [TAM_INT]);

int PedirCuit(char mensaje [TAM_STR], char operando [TAM_CUIT]);

int PedirCliente(char MENSAJE_PEDIR_NOMBRE [TAM_STR], char MENSAJE_ERROR_NOMBRE [TAM_STR], char MENSAJE_PEDIR_CUIT [TAM_STR],
		char MENSAJE_ERROR_CUIT [TAM_STR], char MENSAJE_PEDIR_DIRECCION [TAM_STR], char MENSAJE_ERROR_DIRECCION [TAM_STR],
		char MENSAJE_PEDIR_LOCALIDAD [TAM_STR], char MENSAJE_ERROR_LOCALIDAD [TAM_STR], int idCliente, int len, Cliente *arrayClientes,
		char MENSAJE_ERROR_LUGAR [TAM_STR], char MENSAJE_EXITO_ALTA [TAM_STR]);

int PedirEliminacionDelCliente(Cliente *arrayClientes, int len, char  MENSAJE_ELIMINAR [TAM_STR], char MENSAJE_ELIMINACION_EXITOSA [TAM_STR],
			char MENSAJE_ERROR_NO_ENCONTRADO [TAM_STR], char MENSAJE_ERROR_ELIMINAR [TAM_STR]);

int ModificarCliente (char MENSAJE_MODIFICAR [TAM_STR], char MENSAJE_ERROR_NO_ENCONTRADO [TAM_STR], char MENSAJE_ERROR_MODIFICAR [TAM_STR],
		char MENSAJE_OPCIONES_MODIFICACION [TAM_STR], char MENSAJE_MODIFICAR_DIRECCION [TAM_STR], char MENSAJE_MODIFICAR_LOCALIDAD [TAM_STR],
		char MENSAJE_MODIFICAR_DIRECCION_EXITOSA [TAM_STR], char MENSAJE_MODIFICAR_DIRECCION_ERROR [TAM_STR], char MENSAJE_MODIFICAR_LOCALIDAD_EXITOSA [TAM_STR],
		char MENSAJE_MODIFICAR_LOCALIDAD_ERROR [TAM_STR], char MENSAJE_ERROR_OPCION_MODIFICAR [TAM_STR],  Cliente *arrayClientes, int len);

int ModificarLocalidad (char MENSAJE_MODIFICAR [TAM_STR], Cliente cliente);

int ModificarDireccion (char MENSAJE_MODIFICAR [TAM_STR], Cliente cliente);

int PedidoDeRecoleccion(char MENSAJE_PEDIDO [TAM_STR], char MENSAJE_ERROR_PEDIDO [TAM_STR], Cliente *arrayClientes, int lenCl, Pedido* arrayPedidos,
		int lenPe, Estado* arrayEstados, char MENSAJE_CLIENTE_NO_ENCONTRADO [TAM_STR], char MENSAJE_INGRESAR_KILOS_TOTALES [TAM_STR],
		char MENSAJE_ERROR_SIN_PEDIDOS [TAM_STR], int idPedido);

#endif /* RJIMENEZ_H_ */
