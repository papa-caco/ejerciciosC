/*
 * mailsplitter.h
 *
 *  Created on: 7 oct. 2019
 *      Author: utnso
 */
#ifndef MAILSPLITTER_H_
#define MAILSPLITTER_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <commons/txt.h>
#include <commons/string.h>

/*  Separa el mail en un usuario y un dominio.
 *  Ejemplo:
 *  char* mail = "ritchie@ansic.com.ar" =>
 *  char *user = "ritchie"
 *  char *dominio = "ansic.com.ar"
 *   mail_split(mail, &user, &dominio); */

void mailSplit(char* mail,char *user,char *dominio);


#endif
