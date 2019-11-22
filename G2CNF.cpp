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

#include <iostream>
#include <string>
#include <cstring> // strcmp

#include "Fichero.h"
#include "CFG.h"

int main (int argc, char **argv) {
  if (argc < 3) {
    if (std::strcmp(argv[1], "--help") == 0) {
      std::cout << "Práctica 9 - Forma normal de chomsky"
	      	<< "de una gramática independiente del contexto" << std::endl;
      std::cout << "Uso: ./G2CNF [\"archivo\".gra] [\"archivo\".gra]" << "\n";
      std::cout << "Donde [\"archivo\".gra] es un fichero con la configuración "
                << "de un gramática\n";  
      std::cout << "Y donde [\"archivo\".gra] es un fichero donde se guarda la "
                << "configuracion del CNF";
      std::cout << "Ejemplo: \"./G2CNF input.gra output.gra\"" << std::endl;
      std::cout << "También se puede usar el comando \"make dot\" para generar "
                << "rápidamente el fichero DOT siempre y cuando el comando "
                << "sea igual al del ejemplo" << std::endl;

    }
    else {
      std::cerr << "Modo de empleo: ./C2CNF input.gra output.gra\n";
      std::cerr << "Pruebe 'C2CNF --help' para más información" << std::endl;
      assert (false);
    }
  }
  // Creo y abro los ficheros
  Fichero file (argv);
  // Leo y construyo la grámatica desde el  fichero
  CFG gramatica (file.get_file_in());
  // Muestro por pantalla la original
  std::cout << "Gramatica original: " << std::endl;
  gramatica.write(std::cout);
  
  gramatica.CFGtoCNF(file.get_file_out());
  gramatica.write_file (file.get_file_out()); 
  file.stream ("close");
  
  std::cout << "Gramatica CNF: " << std::endl;
  gramatica.write(std::cout);
  
  
  return 0;
}
