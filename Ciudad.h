#ifndef CLASES_CIUDAD_H_
#define CLASES_CIUDAD_H_

class Ciudad {
private:
	int id;
	char* nombre;
	int numHoteles;
public:
	Ciudad(int id, const char* nombre, int numHoteles);
	virtual ~Ciudad();
	const char* getNombre();
	int getId();
	int getNumHoteles();
	void setNombre(char*);
	void setId(int);
	void setNumHoteles(int);
	void imprimirCiudad();

};

#endif
