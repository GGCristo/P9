/**************************************************************************************************************
 * Universidad de La Laguna
 * Escuela Superior de Ingerniería y Tecnología
 * Grado en Ingenieria Informática 
 * Asignatura Computabilidad y Algoritmia (CyA)
 * Curso: 2º
 * Práctica 7 CyA - La construcción de subconjuntos
 * Autor: Cristo García González
 * Correo: alu0101204512@ull.edu.es
 * Archivo Fichero.cpp
 *         Fichero de desarrollo de la clase que controla el flujo de entrada y salida
 * Referencia: Enunciado de la práctica (PDF en el mismo .zip)
 * Historial de Revisiones:
 * - Creación: 31-10-19
 * - Ultima modificación: 04-11-19 
 * *************************************************************************************************************/
#include "Fichero.h" 
Fichero::Fichero(char **texto) { 
argv_ = texto;
stream();
}

void Fichero::stream (std::string eleccion) {
  if (eleccion != "close"){
    file_in.open(argv_[1], std::ios::in);
    if (file_in.fail()) {
      std::cerr<<"No se ha podido abrir el archivo: "<<argv_[1]<<std::endl;
      assert(false);
    }
    else 
      file_out.open(argv_[2], std::ios::out);
      if (file_out.fail()) {
        std::cerr<<"No se ha podido abrir el archivo: "<<argv_[2]<<std::endl;
        assert(false);
      }
  }
  else { 
    file_in.close();
    std::cout << "Fichero de entrada cerrado correctamente." << std::endl;
    file_out.close();
    std::cout << "Fichero de salida cerrado correctamente." << std::endl;
  }
}

std::ifstream& Fichero::get_file_in () {
return file_in;
}
std::ofstream& Fichero::get_file_out () {
return file_out;
}
