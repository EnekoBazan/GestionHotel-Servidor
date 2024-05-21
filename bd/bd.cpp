/*
 * bd.cpp
 *
 *  Created on: 4 abr 2024
 *      Author: mario
 */

#include "bd.h"
#include <iostream>
#include <sqlite3.h>
#include <string>

using namespace std;

// BD

sqlite3* cargarBD() {
    sqlite3 *bd;
    int rc = sqlite3_open("baseDeDatos.db", &bd);
    if (rc != SQLITE_OK) {
        cerr << "Error al abrir la base de datos: " << sqlite3_errmsg(bd) << endl;
        sqlite3_close(bd);
        return nullptr;
    } else {
        cout << "Base de datos abierta correctamente." << endl;
    }
    return bd;
}

sqlite3* cerrarBD(sqlite3* bd) {
    if (bd) {
        sqlite3_close(bd);
        cout << "Base de datos cerrada correctamente." << endl;
    } else {
        cout << "No hay base de datos abierta para cerrar." << endl;
    }
    return nullptr;
}

int verificarAdmin(const string& nombreAdmin, const string& contrasena, sqlite3* bd) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT COUNT(*) FROM administradores WHERE usuario = ? AND contrasena = ?";
    int result = 0;

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, nombreAdmin.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, contrasena.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            result = sqlite3_column_int(stmt, 0); // Si hay una fila, el resultado será 1, indicando que las credenciales son válidas
        }

        sqlite3_finalize(stmt);
    }

    return result;
}

int cargarUsuarios(sqlite3* bd) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM usuarios";
    int result = 0;

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        cout << "Consulta preparada correctamente." << endl;

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            const unsigned char *nombre = sqlite3_column_text(stmt, 1);
            const unsigned char *apellido = sqlite3_column_text(stmt, 2);

            cout << "ID: " << id << ", Nombre: " << nombre << ", Apellido: " << apellido << endl;
        }

        sqlite3_finalize(stmt);
        result = 1; // Indicar que se cargaron usuarios exitosamente
    }

    return result;
}

int cargarReservas(sqlite3* bd) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM reservas";
    int result = 0;

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        cout << "Consulta preparada correctamente." << endl;

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            const unsigned char *nombreHotel = sqlite3_column_text(stmt, 1);
            const unsigned char *fechaEntrada = sqlite3_column_text(stmt, 2);
            const unsigned char *fechaSalida = sqlite3_column_text(stmt, 3);

            cout << "ID: " << id << ", Hotel: " << nombreHotel << ", Entrada: " << fechaEntrada << ", Salida: " << fechaSalida << endl;
        }

        sqlite3_finalize(stmt);
        result = 1; // Indicar que se cargaron reservas exitosamente
    }

    return result;
}

int anadirReserva(int id, const string& nombreHotel, const string& fechaEntrada, const string& fechaSalida, sqlite3* bd) {
    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO reservas (id, nombreHotel, fechaEntrada, fechaSalida) VALUES (?, ?, ?, ?)";
    int result = 0;

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, id);
        sqlite3_bind_text(stmt, 2, nombreHotel.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, fechaEntrada.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, fechaSalida.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_DONE) {
            cout << "Reserva añadida correctamente." << endl;
            result = 1; // Indicar que la reserva se añadió correctamente
        } else {
            cerr << "Error al añadir reserva: " << sqlite3_errmsg(bd) << endl;
        }

        sqlite3_finalize(stmt);
    }

    return result;
}

int eliminarReserva(int id, sqlite3* bd) {
    sqlite3_stmt *stmt;
    const char *sql = "DELETE FROM reservas WHERE id = ?";
    int result = 0;

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, id);

        if (sqlite3_step(stmt) == SQLITE_DONE) {
            cout << "Reserva eliminada correctamente." << endl;
            result = 1; // Indicar que la reserva se eliminó correctamente
        } else {
            cerr << "Error al eliminar reserva: " << sqlite3_errmsg(bd) << endl;
        }

        sqlite3_finalize(stmt);
    }

    return result;
}
