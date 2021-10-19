/*
 * RJimenez.c
 *
 *  Created on: 14 oct. 2021
 *      Author: rocio
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RJimenez.h"
#include "Cliente.h"
#include "Estado.h"
#include "Pedidos.h"

#define TAM_STR 256
#define TAM_INT 20
#define TAM_CUIT 20
#define LARGO_DE_CLIENTES 100
#define TAM_MODIFICACION 50


int ObtenerString(char mensaje [TAM_STR], char nombre [TAM_STR])
{
	char nombreSinValidar [TAM_STR];
	int retorno;

	retorno = -1;

	printf(mensaje);
	scanf("%s", nombreSinValidar);

	retorno = ValidarNombre(nombreSinValidar);

	if(retorno == 0)
	{
		strcpy(nombre, nombreSinValidar);
	}

	return retorno;
}

int ValidarNombre(char nombre [TAM_STR])
{
	int i;
	int retorno;

	retorno = 0;

	for(i = 0; i < strlen(nombre); i++)
	{
		if(nombre[i] >= '0' && nombre[i] <= '9')
		{
			retorno = -1;
			break;
		}
	}

	return retorno;
}

int PedirFloat(char mensaje [TAM_STR], float *operando)
{
	int retorno;
	char numeroSinValidar [TAM_INT];
	retorno = 0;

	printf(mensaje);
	scanf("%s", numeroSinValidar);

	if (ValidarFloat(numeroSinValidar) == 0)
	{
		*operando = atof(numeroSinValidar);

	} else
	{
		retorno = 1;
	}
	return retorno;
}


int ValidarFloat (char operando [TAM_INT])
{
	int retorno;
	int banderaFlotante;
	int banderaNegativa;
	int i;

	retorno = 0;
	banderaFlotante = 0;
	banderaNegativa = 0;


	for(i=0 ; i<strlen(operando) ; i++)
	{
		if(operando [i] < '0' || operando [i] > '9')
		{
			if (operando [i] == '.')
			{
				if (banderaFlotante == 1)
				{
					retorno = 1;
					break;
				}
			banderaFlotante = 1;

			} else if (operando[i] == '-')
			{
				if (banderaNegativa == 1)
				{
					retorno = 1;
					break;
				}
				banderaNegativa = 1;
			} else
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int PedirInt(char mensaje [TAM_STR], int *operando)
{
	int retorno;
	char numeroSinValidar [TAM_INT];
	retorno = 0;

	*operando = -1;
	printf(mensaje);
	scanf("%s", numeroSinValidar);

	if (ValidarInt(numeroSinValidar) == 0)
	{
		*operando = atoi(numeroSinValidar);

	} else
	{
		retorno = -1;
	}

	return retorno;
}


int ValidarInt(char operando [TAM_INT])
{
	int retorno;
	int i;

	retorno = 0;

	for(i=0 ; i<strlen(operando) ; i++)
	{
		if(operando [i] < '0' || operando [i] > '9')
		{
			retorno = 1;
			break;
		}
	}

	return retorno;
}

int PedirCliente(char MENSAJE_PEDIR_NOMBRE [TAM_STR], char MENSAJE_ERROR_NOMBRE [TAM_STR], char MENSAJE_PEDIR_CUIT [TAM_STR],
		char MENSAJE_ERROR_CUIT [TAM_STR], char MENSAJE_PEDIR_DIRECCION [TAM_STR], char MENSAJE_ERROR_DIRECCION [TAM_STR],
		char MENSAJE_PEDIR_LOCALIDAD [TAM_STR], char MENSAJE_ERROR_LOCALIDAD [TAM_STR], int idCliente, int len, Cliente *arrayClientes,
		char MENSAJE_ERROR_LUGAR [TAM_STR], char MENSAJE_EXITO_ALTA [TAM_STR])
{
	int retorno;
	Cliente aux;
	int indice;


	retorno = -1;

 	indice = BuscarLugarLibreCliente (arrayClientes, len);
 	if(indice != -1)
	{
		if (ObtenerString(MENSAJE_PEDIR_NOMBRE, aux.nombre) == 0)
		{
			if(PedirCuit(MENSAJE_PEDIR_CUIT, aux.cuit) == 0)
			{
				fflush(stdin);
				if(ObtenerString(MENSAJE_PEDIR_DIRECCION, aux.direccion) == 0)
				{
					fflush(stdin);
					if(ObtenerString(MENSAJE_PEDIR_LOCALIDAD, aux.localidad) == 0)
					{
						fflush(stdin);
						AgregarNuevoCliente(arrayClientes, len, idCliente, aux.nombre, aux.cuit, aux.direccion, aux.localidad);

						printf(MENSAJE_EXITO_ALTA);
						printf("\n SU NUMERO DE ID ES %d", idCliente);

						retorno = 0;
					}
					else
					{
						printf(MENSAJE_ERROR_LOCALIDAD);
					}
				}
				else
				{
					printf(MENSAJE_ERROR_DIRECCION);
				}

			}
			else
			{
				printf(MENSAJE_ERROR_CUIT);
			}
		}
		else
		{
			printf(MENSAJE_ERROR_NOMBRE);
		}
	}
 	else
 	{
 		printf(MENSAJE_ERROR_LUGAR);
 	}

	return retorno;
}

int PedirCuit(char mensaje [TAM_STR], char operando [TAM_CUIT])
{
	int retorno;
	char numeroSinValidar [TAM_INT];
	retorno = 0;

	printf(mensaje);
	scanf("%s", numeroSinValidar);

	if (ValidarInt(numeroSinValidar) == 0)
	{
		strcpy(operando, numeroSinValidar);

	} else
	{
		retorno = -1;
	}

	return retorno;
}


int PedirEliminacionDelCliente(Cliente *arrayClientes, int len, char  MENSAJE_ELIMINAR [TAM_STR], char MENSAJE_ELIMINACION_EXITOSA [TAM_STR],
			char MENSAJE_ERROR_NO_ENCONTRADO [TAM_STR], char MENSAJE_ERROR_ELIMINAR [TAM_STR])
{
	int retorno;
	int opcion;
	int indice;

	retorno = -1;

	MostrarClientes(arrayClientes, len);

	if (PedirInt(MENSAJE_ELIMINAR, &opcion) == 0)
	{
		indice = EncontrarClientePorId(arrayClientes, len, opcion);
		if(indice != -1)
		{
			arrayClientes[indice].isEmpty = 0;
			printf(MENSAJE_ELIMINACION_EXITOSA);
		}
		else
		{
			printf(MENSAJE_ERROR_NO_ENCONTRADO);
		}
	}
	else
	{
		printf (MENSAJE_ERROR_ELIMINAR);
	}

	return retorno;
}

int ModificarCliente (char MENSAJE_MODIFICAR [TAM_STR], char MENSAJE_ERROR_NO_ENCONTRADO [TAM_STR], char MENSAJE_ERROR_MODIFICAR [TAM_STR],
		char MENSAJE_OPCIONES_MODIFICACION [TAM_STR], char MENSAJE_MODIFICAR_DIRECCION [TAM_STR], char MENSAJE_MODIFICAR_LOCALIDAD [TAM_STR],
		char MENSAJE_MODIFICAR_DIRECCION_EXITOSA [TAM_STR], char MENSAJE_MODIFICAR_DIRECCION_ERROR [TAM_STR], char MENSAJE_MODIFICAR_LOCALIDAD_EXITOSA [TAM_STR],
		char MENSAJE_MODIFICAR_LOCALIDAD_ERROR [TAM_STR], char MENSAJE_ERROR_OPCION_MODIFICAR [TAM_STR], Cliente *arrayClientes , int len)
{
	int retorno;
	int idEmpleado;
	int indice;
	int opcion;
	retorno = -1;

	MostrarClientes(arrayClientes, len);

	if (PedirInt(MENSAJE_MODIFICAR, &idEmpleado) == 0)
	{
		indice = EncontrarClientePorId(arrayClientes, len, idEmpleado);
		if(indice != -1)
		{
			if (PedirInt(MENSAJE_OPCIONES_MODIFICACION, &opcion) == 0)
			{
				switch (opcion)
				{
					case 1:
						if(ModificarDireccion (MENSAJE_MODIFICAR_DIRECCION, arrayClientes[indice]) != -1)
						{
							printf(MENSAJE_MODIFICAR_DIRECCION_EXITOSA);
							retorno = 0;
						} else
						{
							printf(MENSAJE_MODIFICAR_DIRECCION_ERROR);
						}
						break;
					case 2:
						if(ModificarLocalidad (MENSAJE_MODIFICAR_LOCALIDAD, arrayClientes[indice]) != -1)
						{
							printf(MENSAJE_MODIFICAR_LOCALIDAD_EXITOSA);
							retorno = 0;
						} else
						{
							printf(MENSAJE_MODIFICAR_LOCALIDAD_ERROR);
						}
						break;
					default:
						printf(MENSAJE_ERROR_OPCION_MODIFICAR);
				}
			}
		} else
		{
			printf(MENSAJE_ERROR_NO_ENCONTRADO);
		}
	} else
	{
		printf (MENSAJE_ERROR_MODIFICAR);
	}

	return retorno;
}

int ModificarDireccion (char MENSAJE_MODIFICAR [TAM_STR], Cliente cliente)
{
	int retorno;
	char nuevaDireccion [TAM_MODIFICACION];
	retorno = -1;


	retorno = ObtenerString(MENSAJE_MODIFICAR, nuevaDireccion);
	if (retorno != -1)
	{
		strcpy(nuevaDireccion, cliente.direccion);
	}

	return retorno;
}

int ModificarLocalidad (char MENSAJE_MODIFICAR [TAM_STR], Cliente cliente)
{
	int retorno;
	char nuevaLocalidad[TAM_MODIFICACION];
	retorno = -1;


	retorno = ObtenerString(MENSAJE_MODIFICAR, nuevaLocalidad);
	if (retorno != -1)
	{
		strcpy(nuevaLocalidad, cliente.localidad);
	}

	return retorno;
}


int PedidoDeRecoleccion(char MENSAJE_PEDIDO [TAM_STR], char MENSAJE_ERROR_PEDIDO [TAM_STR], Cliente *arrayClientes, int lenCl, Pedido* arrayPedidos,
		int lenPe, Estado* arrayEstados, char MENSAJE_CLIENTE_NO_ENCONTRADO [TAM_STR], char MENSAJE_INGRESAR_KILOS_TOTALES [TAM_STR],
		char MENSAJE_ERROR_SIN_PEDIDOS [TAM_STR], int idPedido)
{
	int retorno;
	int idCliente;
	int indiceCliente;
	int indicePedido;
	float kilos;

	retorno = 0;

	MostrarClientes(arrayClientes, lenCl);

	indicePedido = BuscarLugarLibrePedido(arrayPedidos, lenPe);

	if(indicePedido != -1)
	{
		if(PedirInt(MENSAJE_PEDIDO, &idCliente) != -1)
		{
			indiceCliente = EncontrarClientePorId(arrayClientes, LARGO_DE_CLIENTES, idCliente);
			if(indiceCliente != -1)
			{
				if(PedirFloat(MENSAJE_INGRESAR_KILOS_TOTALES, &kilos))
				{
					AgregarNuevoPedido(arrayPedidos, lenPe, idPedido, kilos, arrayEstados[0], arrayClientes[indiceCliente]);
					retorno = 1;
				}
				else
				{
					printf(MENSAJE_ERROR_PEDIDO);
				}
			}
			else
			{
				printf(MENSAJE_CLIENTE_NO_ENCONTRADO);
			}
		}
		else
		{
			printf(MENSAJE_ERROR_PEDIDO);
		}
	} else
	{
		printf(MENSAJE_ERROR_SIN_PEDIDOS);
	}


	return retorno;
}
