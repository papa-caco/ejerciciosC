/*
 * runner.c
 *
 *  Created on: 7 oct. 2019
 *      Author: utnso
 */
#include "mailsplitter.h"

char* correo = "a@abcdeabcde";
char *usuario;
char *domain;

int runnermain (void) {

	usuario = malloc(1);
	domain = malloc(10);
	mailSplit(correo,usuario,domain);
	puts(usuario);
	puts(domain);
	free(usuario);
	free(domain);
	return 0;
}
