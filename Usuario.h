#ifndef USUARIO_H_
#define USUARIO_H_

typedef struct{
	char dni[10];
	char nombre[40];
	char apellido[60];
	char email[60];
	int telefono;
	char user[40];
	char contra[16];
	char genero[2];
	char* fechaNcto;
	int numTarjeta;
}Usuario;

#endif /* USUARIO_H_ */
