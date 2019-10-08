/*
 * personas.c
 *
 *  Created on: 5 oct. 2019
 *      Author: utnso
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <commons/txt.h>
#include <commons/string.h>

typedef struct persona{
	char* region;
	char* nombreYApellido;
	int edad;
	char* nroTel;
	int DNI;
	double saldo;
}persona;

#define LARGO_MAXIMO 200

int personsmain(void) {
	persona personas[12];
	char aux[200];
	//char outline[200];
	char** informacion;
	int i = 0;

	FILE* archivo = fopen("archivo.txt","r");
	//FILE* salida = fopen("salida.txt","w");

	while(fgets(aux, LARGO_MAXIMO, archivo) != NULL) {
			//LEE EL PRIMER RENGLON, ES DECIR LA PERSONA
			//busca caracteres 1 x 1, hasta el n°200 de cada línea
			// y en donde encuentra NULL empieza a separar los atributos de la
			// persona que encuentra en c/renglon
		informacion = string_split(aux,";");		//divide el renglon leído "aux" y genera "informacion" => una lista de Strings(listas de chars)
		personas[i].region = malloc(20);  			//Reserva memoria para poder guardar la info (Region) que leyó de cada "aux"
		personas[i].nombreYApellido = malloc(30);
		personas[i].nroTel = malloc(8);				//Reserva memoria para poder guardar NyA que leyó de cada "aux"
		strcpy(personas[i].region, *informacion);				//copia todos los caracteres de region que haya en la lista "información"
		strcpy(personas[i].nombreYApellido, *(informacion+1));
		strcpy(personas[i].nroTel, *(informacion+3));
		personas[i].edad = atoi(*(informacion+2));
		personas[i].DNI = atoi(*(informacion+4));
		personas[i].saldo = atoi(*(informacion+5));
		printf("%s\n",aux);
		i++;

		for (int j=0; j<6; j++) {
			free(informacion[j]);
			}
		free(informacion);
		//free(aux);
	}

	fclose(archivo);

	for(int a=0; a<12; a++) {
		puts(personas[a].region);
		printf("%p\n",&(personas[a].region));
		puts(personas[a].nombreYApellido);
		printf("%p\n",&(personas[a].nombreYApellido));
		printf("edad: %d\n",personas[a].edad);
		printf("%p\n",&(personas[a].edad));
		puts(personas[a].nroTel);
		printf("%s\n",(personas[a].nroTel));
		printf("%p\n",&(personas[a].nroTel));
		printf("DNI: %d\n",personas[a].DNI);
		printf("%p\n",&(personas[a].DNI));
		printf("saldo: %f\n",personas[a].saldo);
		printf("%p\n\n",&(personas[a].saldo));
		//printf("%s\n",outline);
		free(personas[a].region);
		free(personas[a].nombreYApellido);
		free(personas[a].nroTel);
		//free(outline);
	}
	//fclose(salida);
	return 0;
}

