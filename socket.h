#ifndef socket_H_
#define socket_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <math.h>
#include "socket.h"
#include "bd/bd.h"

void iniciarSocket(WSADATA wsaData, SOCKET conn_socket, SOCKET comm_socket, struct sockaddr_in server, struct sockaddr_in client, char sendBuff[512], char recvBuff[512]);
void cerrarSocket(SOCKET comm_socket);

void verificarAdminSocket(sqlite3 *db, SOCKET comm_socket, char sendBuff[512]);

void cargarUsuarios(sqlite3 *db, SOCKET comm_socket, char sendBuff[512]);
void anadirUsuario(sqlite3 *db, SOCKET comm_socket, char sendBuff[512]);
void eliminarUsuario(sqlite3 *db, SOCKET comm_socket, char recvBuff[512]);
void verificarUsuario(sqlite3 *db, SOCKET comm_socket, char recvBuff[512]);

void cargarHoteles(sqlite3 *db, SOCKET comm_socket, char sendBuff[512]);
void anadirHotel(sqlite3 *db, SOCKET comm_socket, char sendBuff[512]);
void eliminarHotel(sqlite3 *db, SOCKET comm_socket, char sendBuff[512]);

void cargarHabitaciones(sqlite3 *db, SOCKET comm_socket, char sendBuff[512]);
void anadirHabitacion(sqlite3 *db, SOCKET comm_socket, char sendBuff[512]);
void eliminarHabitacion(sqlite3 *db, SOCKET comm_socket, char recvBuff[512]);

void cargarReservas(sqlite3 *db, SOCKET comm_socket, char sendBuff[512]);
void anadirReserva(sqlite3 *db, SOCKET comm_socket, char sendBuff[512]);
void eliminarReserva(sqlite3 *db, SOCKET comm_socket, char sendBuff[512]);

#endif
