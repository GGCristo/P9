/**************************************************************************************************************
 * Universidad de La Laguna
 * Escuela Superior de Ingerniería y Tecnología
 * Grado en Ingenieria Informática 
 * Asignatura Computabilidad y Algoritmia (CyA)
 * Curso: 2º
 * Práctica 8 CyA - Gramáticas Regulares y Autómatas Finitos
 * Autor: Cristo García González
 * Correo: alu0101204512@ull.edu.es
 * Archivo NFA2DFA.cpp archivo principal donde voy construyendo el NFA
 *         Fichero de desarrollo del automata con su tupla.
 * Referencia: Enunciado de la práctica (PDF en el mismo .zip)
 * Historial de Revisiones:
 * - Creación: 31-10-19
 * - Ultima modificación: 04-11-19 
 * *************************************************************************************************************/

#pragma once

#include "Produccion.h"

#include <set>
#include <fstream>
#include <iostream>
#include <cassert>
#include <cctype>

typedef std::set<std::string> Conjunto;
/**
  * @brief Gramatica con todas sus características
  * CFG.h
  * @version 1.0
  * @date 11/11/2019
  * @author Cristo García González
  * @code
  * int main () {
  *   CFG CFG_ (ifstream);
  *   CFG_.write.terminales_ (std::cout);
  *   return 0;
  * }
  * @endcode
  */
class CFG {
  private:        
    // Set de strings que guarda el conjunto de terminales 
    Conjunto terminales_;
    // Set de strings que guarda el conjunto de no_terminales 
    Conjunto no_terminales_;
    // string que guarda el Lado izquierdo de la produccion de arranque
    std::string arranque_;
    // Set de strings que guarda el conjunto de producciones 
    Produccion producciones_;
    /**
    * \brief Mira si el string tiene todos los elementos en minuscula
    */
    bool escadena (std::string);
  public:
   /*
   * \brief Constructor a partir de un fichero de entrada
   */
    CFG (std::ifstream&);
    /*
    * \brief Intenta encontrar un string de un set<string>
    */
    bool Encontrar (std::string, const Conjunto&);
    void CFGtoCNF (std::ofstream& os);
    const int tamano (const std::string&); 
    // GETTERS //
    /*
    * \brief Devuelve el conjunto de terminales
    */
    Conjunto get_terminales_ ();
    /*
    * \brief Devuelve el Conjunto de no terminales
    */
    Conjunto get_no_terminales_ ();
    /*
    * \brief Devuelve el arranque_
    */
    std::string get_arranque_ ();
    // WRITE //
    /*
    * \brief Imprime por pantalla los atributos de la grámatica
    */
    std::ostream& write (std::ostream&);
    /*
    * \brieg Escribo la gramatica en un fichero dado
    */
    std::ofstream& write_file (std::ofstream&);
    /*
    * \brief Imprime los terminales
    */
    std::ostream& write_terminales_ (std::ostream&);
    /*
    * \brief Imprime los no terminales
    */
    std::ostream& write_no_terminales_ (std::ostream&);
    /*
    * \brief Imprime el de arranque
    */
    std::ostream& write_arranque_ (std::ostream&);
    /*
    * \brief Imprime las produciiones
    */
    std::ostream& write_producciones_ (std::ostream&);
};
