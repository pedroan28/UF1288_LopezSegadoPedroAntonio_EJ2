
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "servicio.h"

void pedirDatosServicio(servicio *servicio) {
	puts("Nombre Servicio: ");
	fflush(stdin);
	fflush(stdout);
	fgets(servicio->nombreServicio, MAXNOMBRESERV, stdin);
	servicio->nombreServicio[strlen(servicio->nombreServicio)-1]='\0';


	puts("Puerto: ");
	fflush(stdout);
	scanf("%d", &(servicio->puerto));

	puts("Nombre Servidor: ");
	fflush(stdin);
	fflush(stdout);
	fgets(servicio->nombreServidor, MAXNOMBRESERV, stdin);
	servicio->nombreServidor[strlen(servicio->nombreServidor)-1]='\0';

	puts("IP Servidor: ");
	fflush(stdin);
	fflush(stdout);
	fgets(servicio->ipServidor, MAXIP, stdin);
	servicio->ipServidor[strlen(servicio->ipServidor)-1]='\0';

	puts("Num Clientes: ");
	fflush(stdout);
	scanf("%d", &(servicio->numClientes));

}


void mostrarDatosServicio(servicio servicio) {
	printf("\nNombre Servicio: %s",servicio.nombreServicio);
	printf("\nServidor: %s", servicio.nombreServidor);
	printf("\nIP: %s",servicio.ipServidor);
	printf("\n Puerto: %d", servicio.puerto);
	printf("\nNumero de clientes: %d\n", servicio.numClientes);
}

void mostrarListaServicios(servicio listaServicios[MAXSERVICIOS], int tam){

	printf("Lista de Servicios:\n");

    for (int i = 0; i < tam; i++) {
        mostrarDatosServicio( listaServicios[i]);
		system("pause");
    }
	
}

int estaPuertoOcupado(servicio listaServicios[MAXSERVICIOS], int tam, int puerto) {
    for (int i = 0; i < tam; i++) {
        if (listaServicios[i].puerto == puerto) {
            
            return 1;
        }
    }
    return 0;
}

int insertarServicio(servicio listaServicios[MAXSERVICIOS], int tam, servicio servicio) {
    
    if (estaPuertoOcupado(listaServicios, tam, servicio.puerto)) {
        return 0;  
    }else return 1;

}