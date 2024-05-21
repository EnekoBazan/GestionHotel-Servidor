#include <iostream>
#include <string.h>
#include "Ciudad.h"

Ciudad::Ciudad(int id, const char* nombre,int numHoteles) {
	std::cout << "Constructor Ciudad" << std::endl;
	this->id = id;
	this->nombre = new char[strlen(nombre) + 1];
	strcpy(this->nombre, nombre);
	this->numHoteles = numHoteles;
}

Ciudad::~Ciudad() {
	std::cout << "Destructor Ciudad" << std::endl;
	delete[] nombre;
}

const char* Ciudad::getNombre(){
	return this->nombre;
}

int Ciudad::getId(){
	return this->id;
}

void Ciudad::setNombre(char* nombre){
	this->nombre = nombre;
};

void Ciudad::setId(int id){
	this->id = id;
};

void Ciudad::imprimirCiudad(){
	std::cout << "Nombre: " << this->getNombre() << " Id: " << this->getId() << " NumeroHoteles: " << this->getNumHoteles() << std::endl;
}
