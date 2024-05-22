#ifndef BD_H_
#define BD_H_

#include "sqlite3.h"
#include <iostream>
#include <string>

using namespace std;

//BD
sqlite3* cargarBD();
sqlite3* cerrarBD(sqlite3* bd);

//Admin
int verificarAdmin(const string& nombreAdmin, const string& contrasena, sqlite3* bd);

//Usuario
int cargarUsuarios(sqlite3* bd);
int anadirUsuario(const string& nombre, const string& apellido, const string& contrasena, int id, const string& email, sqlite3* bd);
int eliminarUsuario(int id, sqlite3* bd);
int verificarUsuario(const string& nombreUsuario, const string& contrasena, sqlite3* bd);

//Hoteles
int cargarHoteles(sqlite3* bd);
int anadirHotel(const string& nombre, int estrellas, const string& pais, const string& ciudad, int num_piso, int num_indiv, int num_dobles, int num_suite, sqlite3* bd);
int eliminarHotel(int id, sqlite3* bd);

//Habitaciones
int cargarHabitaciones(sqlite3* bd);
int anadirHabitacion(int id, const string& tipo, int capacidad, float precio, const string& estado, sqlite3* bd);
int eliminarHabitacion(int id, sqlite3* bd);

//Reservas
int cargarReservas(sqlite3* bd);
int anadirReserva(int id, const string& nombreHotel, const string& fechaEntrada, const string& fechaSalida, sqlite3* bd);
int eliminarReserva(int id, sqlite3* bd);

#endif /* BD_H_ */
