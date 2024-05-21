#include <string.h>

#include "Ciudad.h"

class Hotel
{
private:
	int id;
	char* nombre;
	int estrellas;
	Ciudad* ciudad;
public:
	Hotel();
	Hotel(int, const char*, int, Ciudad*);
	Hotel(const Hotel &other);
	virtual ~Hotel();
	int getId();
	void setId(int id);
	char* getNombre();
	void setNombre(const char* nombre);
	int getEstrellas();
	void setEstrellas(int estrellas);
	Ciudad getCiudad();
	void setCiudad(Ciudad* ciudad);
};

#endif /* CLASES_HOTEL_H_ */
