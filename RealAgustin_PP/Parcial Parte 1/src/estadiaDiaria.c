/*
 * estadiaDiaria.c
 *
 *  Created on: 10 oct. 2021
 *      Author: Agustin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estadiaDiaria.h"
#include "inputs.h"

int EstadiaDiaria_iniciarLista(sEstadiaDiaria lista[], int len)
{
	int retorno=-1;

	if(lista!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			lista[i].estadoEstadiaVacio=1;
		}
		retorno=1;
	}
	return retorno;
}
int EstadiaDiaria_agregarEstadiaDiaria(sEstadiaDiaria lista[], int len, int id, char nombresDuenio[],int telefonoContacto, int idPerro, sFecha fecha)
{
	int retorno=-1;

	int index;
	  index=EstadiaDiaria_buscarEspacioLibre(lista, len);

		if(index!=-1)
		{
			printf("\nCargando la lista en espacios libres espere unos segundos...\n");
			if(lista!=NULL && lista[index].estadoEstadiaVacio==1)
			{
				lista[index].id=id;
				strcpy(lista[index].nombresDuenio, nombresDuenio);
				lista[index].telefonoContacto=telefonoContacto;
				lista[index].idPerro=idPerro;
				lista[index].fecha=fecha;
				lista[index].estadoEstadiaVacio=0;

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
int EstadiaDiaria_eliminarPerroEstadia(sEstadiaDiaria lista[], int len, int id)
{
	int retorno=-1;
	int index;
	int idIngresado;

	if(lista!=NULL)
	{
		pedirEntero(&idIngresado,"Ingrese el ID del cliente de la estadia a borrar de (100000-1000000): ", "Reingrese el ID del cliente de la estadia a borrar de (100000-1000000): ", 100000, 1000000);
		index=EstadiaDiaria_buscarPorId(lista, len, idIngresado);

		if(index!=-1)
		{
			EstadiaDiaria_mostrarUnaEstadia(lista[index]);

			if(!ConfirmarSioNoEstadiaDiaria("\nIngrese 's' para confirmar la eliminacion del perrito de la estadia."))
			{
				lista[index].estadoEstadiaVacio=1;
				printf("\nEl perrito de la estadia %s fue eliminado correctamente!\n\n", lista[index].nombresDuenio);
				retorno=0;
			}
			else
			{
				printf("\nSe cancelo la eliminacion...\n\n");
			}
		}
		else
		{
			printf("\nError. No se encontro la estadia del perrito...");
		}
	}
	return retorno;
}

int EstadiaDiaria_orderEstadiaPerrito(sEstadiaDiaria lista[], int len)
{

		int retorno=-1;
		sEstadiaDiaria auxLista;

		if(lista!=NULL)
		{
		 for(int i=0;i<len;i++)
				 {
				   for(int j=i+1;j<len;j++)
				   {
					   if(Fecha_AcpyB(lista[i].fecha, lista[j].fecha)==-1)
					   {
						  auxLista=lista[i];
						  lista[i]=lista[j];
						  lista[j]=auxLista;
					   }
					   else if((Fecha_AcpyB(lista[i].fecha, lista[j].fecha)==0) && strcmp(lista[i].nombresDuenio, lista[j].nombresDuenio)>0)
					   {
						  auxLista=lista[i];
						  lista[i]=lista[j];
						  lista[j]=auxLista;
					   }
				   }
				 }

			 retorno=1;
		}

		return retorno;
}
void EstadiaDiaria_mostrarUnaEstadia(sEstadiaDiaria estadia)
{
	printf("%-5d %-20s %-20d %-20d %d-%d-%d \n", estadia.id, estadia.nombresDuenio, estadia.telefonoContacto, estadia.idPerro, estadia.fecha.dia, estadia.fecha.mes, estadia.fecha.anio);
}

int EstadiaDiaria_imprimirListaEstadiaDiaria(sEstadiaDiaria lista[], int length)
{
	int retorno=-1;

	if(lista!=NULL)
	{

		for(int i=0;i<length;i++)
		{
			if(lista[i].estadoEstadiaVacio==0)
			{
				EstadiaDiaria_mostrarUnaEstadia(lista[i]);
			}
		}
		printf("\n");
	 retorno=1;
	}

	return retorno;

}
int ConfirmarSioNoEstadiaDiaria(char* mensaje)
{
	int retorno=-1;
	char respuesta;

	pedirCaracter(&respuesta, mensaje);

	if(respuesta=='s' || respuesta=='S')
	{
		retorno=0;
	}

	return retorno;
}
int EstadiaDiaria_buscarPorId(sEstadiaDiaria lista[], int len,int id)
{
	int index=-1;

		if(lista!=NULL )
		{
			for(int i=0;i<len;i++)
			{
				if(lista[i].estadoEstadiaVacio==0 && lista[i].id==id)
				{
					index=i;
					break;
				}
			}
		}
		return index;
}
int EstadiaDiaria_buscarEspacioLibre(sEstadiaDiaria lista[], int len)
{
	int i;
	int index=-1;

	if(lista!=NULL)
	{
		for(i=0; i<len; i++)
		{
			if(lista[i].estadoEstadiaVacio==1)
			{
				index = i;
				break;
			}
		}
	}
	return index;

}

