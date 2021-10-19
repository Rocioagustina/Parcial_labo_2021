/*
 * Estado.c
 *
 *  Created on: 18 oct. 2021
 *      Author: rocio
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estado.h"

int iniciarEstado (Estado* list)
{
	int retorno;

	retorno = -1;

	list[0].id = 1;
	strcpy (list[0].descripcion, "Pendiente");
	list[1].id = 2;
	strcpy(list[1].descripcion, "Completado");

	retorno = 0;
	return retorno;
}
