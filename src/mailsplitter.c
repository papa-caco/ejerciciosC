/*
 * mailsplitter.c
 *
 *  Created on: 7 oct. 2019
 *      Author: utnso
 */
#include "mailsplitter.h"

char** informacion;

void mailSplit(char* mail,char *user,char *dominio) {
	informacion = string_split(mail,"@");
	strcpy(user,*informacion);
	strcpy(dominio,*(informacion + 1));
}
