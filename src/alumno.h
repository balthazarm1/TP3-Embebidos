/************************************************************************************************
Copyright (c) 2023, Balthazar Martin <balthazarm8@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

#ifndef ALUMNO_H
#define ALUMNO_H

/**
 ** \author Balthazar Martin
 ** \date ??/04/23
 ** \brief Declaraciones publicas del modulo de alumnos
 **
 ** \addtogroup alumno Alumnos.h
 ** \brief Modulo para gestion de alumnos.
 ** @{ */

/* === Headers files inclusions ================================================================ */

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

#include <stdint.h>

/**
 * @brief Define el tamaño de los campos de texto
 *
 * Este parametro define el tamaño de los campos de texto de la
 * estructura \ref alumno_s "alumno_s"
 */
#define FIELD_SIZE 50

/**
 * @brief Define el numero de estructuras de alumnos a generar
 *
 * Este parametro define el numero de estructuras
 * del tipo \ref alumno_s "alumno_s"
 */
#define NUMBER_OF_STRUCTS 50

/* === Public data type declarations =========================================================== */

//! Estructura anonima para almacenar datos del alumno con campos desconocidos
typedef struct alumno_s * alumno_t;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

//! Funcion que recibe los campos del alumno
alumno_t CrearAlumno(char * apellido, //!< Puntero que recibe el apellido del alumno
                     char * nombre,   //!< Puntero que recibe el nombre del alumno
                     int documento /*!< Entero que recibe el documento del alumno */);

//! Funcion para obtener el apellido del alumno
int * GetApellido(alumno_t alumno, //!< Puntero a la estructura de datos del alumno
                char cadena[] /*!< Puntero a la cadena del apellido del alumno */ );

//! Funcion para obtener el nombre del alumno
int * GetNombre(alumno_t alumno, //!< Puntero a la estructura de datos del alumno
                char cadena[] /*!< Puntero a la cadena del nombre del alumno */ );

//! Funcion para obtener el documento del alumno
int * GetDocumento(alumno_t alumno, //!< Puntero a la estructura de datos del alumno
                int documento /*!< Documento del alumno */ );

//! Funcion para serializar los datos del alumno
int Serializar(alumno_t alumno, //!< Puntero a la estructura de datos del alumno
               char cadena[],   //!< Puntero a la cadena de resultado
               uint32_t espacio /*!< Espacio disponible en la cadena de resultado */);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif /* ALUMNO_H */