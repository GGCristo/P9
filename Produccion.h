/************************************************************************************************************************
 * Universidad de La Laguna
 * Escuela Superior de Ingerniería y Tecnología
 * Grado en Ingenieria Informática 
 * Asignatura Computabilidad y Algoritmia (CyA)
 * Curso: 2º
 * Práctica 7 CyA - La construcción de subconjuntos
 * Autor: Cristo García González
 * Correo: alu0101204512@ull.edu.es
 * Archivo Estado.h
 *         Fichero de cabecera de la clase que gestiona los Estados
 * Referencia: Enunciado de la práctica (PDF en el mismo .zip)
 * Historial de Revisiones:
 * - Creación: 31-10-19
 * - Ultima modificación: 04-11-19 
 * *************************************************************************************************************/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <utility>
typedef std::vector<std::pair<std::string, std::string>> vpss;
/**
  * @brief Clase para las producciones
  * Estado.h
  * @version 1.0
  * @date 11/11/2019
  * @author Cristo García González
  * @code
  * int main () {
  *   NFA_.get_producciones_().write(std::cout);
  *   return 0;
  * }
  * @endcode
  */
class Produccion {
  private:
    vpss producciones__;
  public:
    /*
    * \brief Plantilla para el constructor
    */
    Produccion ();
    /*
    * \return producciones_ (vector de pares de strings)
    */
    // Producciones en un vector de pares de string donde un string es 
    // el lado izquierdo y el otro el lado derecho
    vpss& get_producciones_();
    /*
    * \brief Devuelve el numero de producciones
    */
    const size_t size();
    /*
    * \brief Hace push_back en el vector producciones_
    */
    void insert (std::string, std::string);
    /*
    * \brief Me devuelve el lado derecho de la produccion, pasandole el indice de la misma
    */
    std::string& LD (int); 
    /*
    * \brief Me devuelve el lado derecho de la produccion, pasandole el indice de la misma
    */
    std::string& LI (int); 
    /*
    * \brief Imprime las producciones en el flujo de salida que se le pasa
    */
    std::ostream& write (std::ostream&);

};
