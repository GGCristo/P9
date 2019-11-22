
/**************************************************************************************************************
 * Universidad de La Laguna
 * Escuela Superior de Ingerniería y Tecnología
 * Grado en Ingenieria Informática 
 * Asignatura Computabilidad y Algoritmia (CyA)
 * Curso: 2º
 * Práctica 7 CyA - La construcción de subconjuntos
 * Autor: Cristo García González
 * Correo: alu0101204512@ull.edu.es
 * Archivo Fichero.h
 *         Fichero de cabecera de la clase que controla el flujo de entrada y salida
 * Referencia: Enunciado de la práctica (PDF en el mismo .zip)
 * Historial de Revisiones:
 * - Creación: 31-10-19
 * - Ultima modificación: 04-11-19 
 * *************************************************************************************************************/
#pragma once
#include <iostream> //Porque no lo pilla del main directamente
#include <fstream>
#include <cassert>
#include <string>
/**
  * @brief Ficheros generales
  * Fichero.h
  * @version 1.0
  * @date 03/11/2019
  * @author Cristo García González
  * @code
  * int main (int argc, char **argv) {
  *   Fichero file(argv);
  *   file.get_file_out() << "Estoy escribiendo en un fichero" << std::endl; 
  *   return 0;
  * }
  * @endcode
  */


class Fichero{
  private:
    // Atributo que recibo por linea de comando
    char **argv_;
    // Archivo de entrada
    std::ifstream file_in;
    // Atributo Archivo de salida
    std::ofstream file_out;
  public:
    /**
    * \brief Paso el argv, que pasa a ser un atributo de la clase e invoco a la funcion stream
    */
    Fichero(char**);
    /**
    * \brief Si no recibo parametro me crea dos ficheros atributos, en caso de recibir close 
    *        los cierra
    */
    void stream (std::string eleccion = "abrir");
    /**
    * \return Fichero de entrada
    */
    std::ifstream& get_file_in ();
    /**
    * \return Fichero de salida
    */
    std::ofstream& get_file_out ();
};

