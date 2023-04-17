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
 ** \date 17/04/23
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

/* === Public data type declarations =========================================================== */

//! Estructura para almacenar datos del alumno
typedef struct alumno_s {
    char apellido[FIELD_SIZE]; //!< Almacena el apellido del alumno
    char nombre[FIELD_SIZE];   //!< Almacena el nombre del alumno
    uint32_t documento;        //!< Almacena el documento del alumno
} const * alumno_t;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

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