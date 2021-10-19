/*
 * Cliente.h
 *
 *  Created on: 17 oct. 2021
 *      Author: rocio
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#define TAM_STR 256

struct
{
	int id;
	char nombre[TAM_STR];
	char cuit [TAM_STR];
	char direccion [TAM_STR];
	char localidad [TAM_STR];
	int isEmpty;

}typedef Cliente;

int IniciarCliente (Cliente* list, int len);

int BuscarLugarLibreCliente (Cliente *arrayClientes, int len);

int AgregarNuevoCliente(Cliente* clientes, int len, int id, char nombre [TAM_STR], char cuit [TAM_STR], char direccion [TAM_STR], char localidad [TAM_STR]);

int MostrarClientes(Cliente *arrayClientes, int len);

int MostrarUnCliente (Cliente cliente);

int EncontrarClientePorId(Cliente *arrayClientes, int len, int id);



#endif /* CLIENTE_H_ */
