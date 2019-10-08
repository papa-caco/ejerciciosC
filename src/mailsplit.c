/*
*   Separa el mail en un usuario y un dominio.
*   Ejemplo:
*   char* mail = "ritchie@ansic.com.ar";
*   char* user, dominio;
*   mail_split(mail, &user, &dominio);
*   =>
*   user = "ritchie"
*   dominio = "ansic.com.ar"
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <commons/txt.h>
#include <commons/string.h>

char* mail = "ritchie@ansic.com.ar";

int mailsplitmain(void) {
char *user;
char *dominio;
char**  informacion;

informacion = string_split(mail,"@");
	user = malloc(10);
	dominio = malloc(20);
	strcpy(user,*informacion);
	strcpy(dominio,*(informacion + 1));
	puts(user);
	puts(dominio);
	free(user);
	free(dominio);

return 0;

}

