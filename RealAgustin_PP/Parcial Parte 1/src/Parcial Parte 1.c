/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inputs.h"
#include "perritos.h"
#include "estadiaDiaria.h"


#define maxNombreDuenioPerro 51
#define maxNumeroTelefono 1199999999
#define minNumeroTelefono 1100000000
#define minIdPerro 7000
#define maxIdPerro 70000
#define minIdcontador 100000
#define maxIdcontador 1000000
#define largoPerritos 1000
#define largoListaClientes 1000
int main(void)
{
	setbuf(stdout, NULL);

	sEstadiaDiaria auxEstadia;
	sEstadiaDiaria listaClientesEstadia[largoListaClientes];
	sPerritos listaPerritos[largoPerritos];
	int option;
	int auxEstadoPosicionVacio;
	int contadorClientesActivo=0;
	int contadorId=100000;
	int afirmacion;
	int almacenarAuxIdModificar;
	int auxBuscarIndice;
	int contadorPerritos=0;
	float promedioPerritos;
	float acumuladorEdadesPerritos=0;

	Perritos_iniciarLista(listaPerritos, largoPerritos);
	Perritos_agregarPerrito(listaPerritos, largoPerritos, 7000, "Lobo","Sharpie",2);
	Perritos_agregarPerrito(listaPerritos, largoPerritos, 7001, "Sheila","Goldrn",12);
	Perritos_agregarPerrito(listaPerritos, largoPerritos, 7002, "Reina","Galgo,",13);


	EstadiaDiaria_iniciarLista(listaClientesEstadia, largoListaClientes);
	do
	{
			pedirEntero(&option, "-------------------------------------------------------------------------------\n"
								 "1.RESERVAR ESTADIA.\n"
								 "2.MODIFICAR ESTADIA.\n"
					             "3.CANCELAR ESTADÍA.\n"
								 "4.LISTAR ESTADÍAS:\n"
								 "5.LISTAR PERROS:\n"
								 "6.Promedio de edad de los perros.\n"
								 "7.SALIR\n"
								 "--------------------------------------------------------------------------------\n"
								 "Ingrese una opcion: ",

								 "1.RESERVAR ESTADIA\n"
								 "2.MODIFICAR ESTADIA.\n"
								 "3.CANCELAR ESTADÍA.\n"
								 "4.LISTAR ESTADÍAS:\n"
								 "5.LISTAR PERROS:\n"
								 "6.Promedio de edad de los perros.\n"
								 "7.SALIR\n"
								 "---------------------------------------------------------------------------------\n"
								 "Opcion invalida, reingrese: ",1, 7);


			switch(option)
			{
			case 1:
				auxEstadoPosicionVacio=EstadiaDiaria_buscarEspacioLibre(listaClientesEstadia, largoListaClientes);
				if(auxEstadoPosicionVacio!=-1)
				{

					pedirCadena(auxEstadia.nombresDuenio, "Ingrese el nombre del duenio del perro: ", "Error.Ingrese el id del cliente  para la estadia: ", maxNombreDuenioPerro);
				    pedirEntero(&auxEstadia.telefonoContacto, "Ingrese el numero de telefono del cliente de la estadia(11---------): ", "Error.Ingrese el numero de telefono del cliente de la estadia(11---------): ", minNumeroTelefono, maxNumeroTelefono);
					pedirEntero(&auxEstadia.idPerro, "Ingrese la id del perro del cliente de la estadia(7000-70000): ", "Error. Ingrese la id del perro del cliente de la estadia(1-1000):", minIdPerro, maxIdPerro);
					Fecha_pedirVerificarFecha(&auxEstadia.fecha);
					auxEstadia.id=contadorId;

					printf("\n\n");
					pedirCaracter(&afirmacion,"\n\nPresione S para agregar al cliente ingresado: ");
					if(afirmacion=='s' || afirmacion=='S')
					{
						EstadiaDiaria_agregarEstadiaDiaria(listaClientesEstadia, largoListaClientes, auxEstadia.id, auxEstadia.nombresDuenio, auxEstadia.telefonoContacto, auxEstadia.idPerro, auxEstadia.fecha);
						contadorId++;
						contadorClientesActivo++;
						printf("El nuevo el cliente fue agregado....\n");
						getchar();
					}
					else
					{
						printf("Se ha producido un error...\n");
					}
				}
				else
				{
					printf("El sistema esta lleno vuelva en otras instancias\n");
				}
				EstadiaDiaria_mostrarUnaEstadia(listaClientesEstadia[0]);
				system("pause");
				break;
			case 2:
				if(contadorClientesActivo>0)
				{
					pedirEntero(&almacenarAuxIdModificar, "Cual es id que desea modifcar: ", "Error. Cual es id que desea modifcar: ", minIdcontador, maxIdcontador);
					auxBuscarIndice=EstadiaDiaria_buscarPorId(listaClientesEstadia, largoListaClientes, almacenarAuxIdModificar);
					if(listaClientesEstadia[auxBuscarIndice].estadoEstadiaVacio==0)
					{
						EstadiaDiaria_mostrarUnaEstadia(listaClientesEstadia[auxBuscarIndice]);
						do
						{

							pedirEntero(&option,"--------------------------------------------------------------------------------\n"
												"1-MODIFICAR El teléfono de contacto.\n"
												"2-MODIFICAR El perro.\n"
												"3-SALIR.\n"
												"--------------------------------------------------------------------------------\n"
												"Ingrese una opcion: ",

												"1-MODIFICAR El teléfono de contacto.\n"
												"2-MODIFICAR El perro.\n"
												"3-SALIR\n"
												"--------------------------------------------------------------------------------\n"
												"Opcion invalida, reingrese: ", 1, 3);
							switch(option)
							{
								case 1:
									pedirEntero(&listaClientesEstadia[auxBuscarIndice].telefonoContacto, "Ingrese el numero de telefono del cliente de la estadia: ", "Error.Ingrese el numero de telefono del cliente de la estadia: ", minNumeroTelefono, maxNumeroTelefono);
									break;
								case 2:
									pedirEntero(&listaClientesEstadia[auxBuscarIndice].idPerro, "Ingrese la id del perro del cliente de la estadia: ", "Error. Ingrese la id del perro del cliente de la estadia:", minIdPerro, maxIdPerro);
									break;

							}
							EstadiaDiaria_mostrarUnaEstadia(listaClientesEstadia[auxBuscarIndice]);

						}while(option!=3);
					}
					else
					{
						printf("No se indentifico ese cliente\n");
					}
				}
				else
				{
					printf("No se ha ingresado ningun cliente...\n");
				}
				option=0;
				break;
			case 3:
				if(contadorClientesActivo>0)
				{
					EstadiaDiaria_eliminarPerroEstadia(listaClientesEstadia, largoListaClientes, almacenarAuxIdModificar);
				}
				else
				{
					printf("No se ha ingresado ningun cliente...\n");
				}
				break;
			case 4:
				printf("Listado estadias diasrias Perritos.\n");
				if(contadorClientesActivo>0)
				{
					EstadiaDiaria_orderEstadiaPerrito(listaClientesEstadia, largoListaClientes);
					EstadiaDiaria_imprimirListaEstadiaDiaria(listaClientesEstadia, largoListaClientes);
				}
				else
				{
					printf("No se puedo mostrar la lista de estadia...\n");
				}
				break;
			/*case 5:
				printf("Mostrar los perritos...\n");
				if(contadorClientesActivo>0)
				{
					Perritos_imprimirPerritos(listaPerritos, largoPerritos);
				}
				else
				{
					printf("No se puedo mostrar la lista de perritos...\n");
				}
				break;
			case 6:
				printf("El promedio de los perritos es: \n");
				if(contadorClientesActivo>0)
				{
					Perritos_contarPerritosActivos(listaPerritos, largoPerritos, &contadorPerritos);
					Perritos_SumaEdadesGeneral(listaPerritos, largoPerritos, &acumuladorEdadesPerritos);
					Perritos_PromedioEdades(listaPerritos, largoPerritos, &promedioPerritos, &acumuladorEdadesPerritos, &contadorPerritos);
				}
				else
				{
					printf("No se puedo mostrar el promedio de los perritos...\n");
				}
				break;*/
			}

		}while(option!=7);


	return EXIT_SUCCESS;
}
