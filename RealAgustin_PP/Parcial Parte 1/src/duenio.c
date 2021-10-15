/*
 * duenio.c
 *
 *  Created on: 15 oct. 2021
 *      Author: Agustin
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "duenio.h"

#include "inputs.h"


int duenio_iniciarLista(sDuenio lista[], int len)
{
	int retorno=-1;

	if(lista!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			lista[i].estadoDuenioVacio=1;
		}
		retorno=1;
	}
  return retorno;
}
int duenio_agregarDuenio(sDuenio lista[], int len, int* id, char nombre[],int telefono)
{
	int retorno=-1;
	int index;

	if(lista!=NULL)
	{
		index=duenio_buscarEspacioLibre(lista, len);

		if(index!=-1)
		{
			printf("\nCargando la lista en espacios libres espere unos segundos...\n");
			if(lista!=NULL && lista[index].estadoDuenioVacio==1)
			{
				lista[index].id=id;
				strcpy(lista[index].nombre, nombre);
				lista[index].telefono=telefono;
				lista[index].estadoDuenioVacio=0;

			}
			else
			{
				printf("\nError ya se cargo la lista no hay espacios disponibles...\n");
			}
			retorno=0;
		}
		else
		{
			printf("\nNo se pudo cargar...\n");
			retorno=-1;
		}


	 return retorno;


	}

	return retorno;
}
int duenio_buscarEspacioLibre(sDuenio lista[], int len)
{
	int i;
	int index=-1;

	if(lista!=NULL)
	{
		for(i=0; i<len; i++)
		{
			if(lista[i].estadoDuenioVacio==1)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}
void duenio_mostrarUnaEstadia(sDuenio estadia)
{
	printf("%-5d %-20s %-20d\n", estadia.id, estadia.nombre, estadia.telefono);
}
int duenio_imprimirListaEstadiaDiaria(sDuenio lista[], int length)
{
	int retorno=-1;

	if(lista!=NULL)
	{

		for(int i=0;i<length;i++)
		{
			if(lista[i].estadoDuenioVacio==0)
			{
				duenio_mostrarUnaEstadia(lista[i]);
			}
		}
		printf("\n");
	 retorno=1;
	}

	return retorno;

}
