#include "CFG.h"

#include <stack>
#include <set>
#include <fstream>
#include <string>

const std::string unNT = "C";

bool CFG::escadena (std::string cadena) {
  for (int i = 0; i < cadena.size(); i++) {
    if (std::isupper(cadena[i])) return false;
  }
  return true;
}

CFG::CFG (std::ifstream& is) {
  std::string palabra;
  int numero = 0;
  while (is >> palabra) {
    if (palabra [0] == '/' && palabra[1] == '/') {
      std::string comentario;
      getline (is, comentario);
      continue;
    }
    if (palabra [0] == '/' && palabra [1] == '*') {
      while (is >> palabra && (palabra[0] != '*' && palabra[1] != '/')) {
        continue;
      }
      continue;
    }
    if (numero == 0) {
      int contador = std::stoi(palabra);
      for (int i = 0; i < contador; i++) {
        is >> palabra;
        terminales_.insert (palabra);
      }
    }
    else if (numero == 1) {
      int contador = std::stoi(palabra);
      for (int i = 0; i < contador; i++) {
        is >> palabra;
        no_terminales_.insert (palabra);
      }	
    }
    else if (numero == 2) {
      if (Encontrar (palabra, no_terminales_)) arranque_ =  palabra;
      else {
        std::cerr << "El simbolo de arranque no pertenece al conjunto de "
		  << "simbolos de los terminales" << std::endl;
	assert (false);
      }
    }
    else if (numero == 3) {
      std::string LI, flecha, LD;
      int contador = std::stoi(palabra);
      if (contador != 0) {
        is >> LI >> flecha >> LD;
	      producciones_.insert (LI, LD);
      }
      for (int i = 0; i < contador - 1; i++) {
        // flecha puede ser que haya cogido un "|" o LI
        is >> flecha;
        if (flecha == "|") {
          is >> LD;
          producciones_.insert (LI, LD);
        }
        else {
          LI = flecha;
          is >> flecha >> LD;
          producciones_.insert (LI, LD);
        }
      }	
    }
    numero++;
  }
}

bool CFG::Encontrar (std::string string, const Conjunto& conjunto) {
  for (Conjunto::iterator it = conjunto.begin(); 
       it != conjunto.end(); it++) {
    if (*it == string) return true;
  }
  return false;
}

void CFG::CFGtoCNF (std::ofstream& os) {
  for (int i = 0; i < producciones_.get_producciones_().size(); i++) {
    if (producciones_.LD(i).size() >= 2) {
      for (int j = 0; j < producciones_.LD(i).size(); j++) {
        if (Encontrar (std::string(1, producciones_.LD(i)[j]), terminales_)) {
          std::string caracter = std::string (1, producciones_.LD(i)[j]);
          std::string no_terminal = unNT + caracter;
          no_terminales_.insert(no_terminal);
          producciones_.insert(no_terminal, caracter);
          producciones_.LD(i).replace (j, 1, no_terminal);
          j++; // Itero "manualmente" para que me salte la "a" de "Ca"
        }
      } 
    }  
  }
  unsigned int contador_et = 0; // Contador para la etiqueta;
  unsigned int producciones__s = producciones_.get_producciones_().size();
  for (int i = 0; i < producciones__s; i++) {
    if (tamano(producciones_.LD(i)) >= 3) {
      std::string etiqueta = std::string(1, char('D' + contador_et++));
      
      std::stack<std::string> pila;
      for (int j = 0; j < producciones_.LD(i).size(); j++) {
      std::string termino = std::string (1, producciones_.LD(i)[j]);
        if (termino == unNT && Encontrar (std::string (1, producciones_.LD(i)[j+1]), terminales_)) {
          pila.push(termino + producciones_.LD(i)[j+1]);
          j++;
        }
        else {
          pila.push(termino);
        }
      }
      std::string LI_o = producciones_.LI(i); // Necesito el LI original para cuando queden
                                             // los dos últimos en la pila
      while (pila.size() != 2) {
        std::string LI = etiqueta + std::to_string(pila.size() - 2);
        no_terminales_.insert(LI);
        std::string volatil = pila.top();
        pila.pop();
        producciones_.insert(LI, pila.top() + volatil);
        pila.pop();
        pila.push (LI);
      }
      std::string volatil = pila.top();
      pila.pop();
      producciones_.LD(i) = pila.top() + volatil;
      pila.pop(); 
    } 
  } 
}
const int CFG::tamano (const std::string& string_) {
  int tamano = 0;
  for (int i = 0; i < string_.size(); i++) {
    if (string_[i] == unNT[0] && Encontrar (std::string(1, string_[i+1]), terminales_)){
      i++;
    }
    tamano++;
  }
  return tamano;
}
Conjunto CFG::get_terminales_ () {
  return terminales_;
}
Conjunto CFG::get_no_terminales_ () {
  return no_terminales_;
}
std::string CFG::get_arranque_ () {
  return arranque_;
}
std::ostream& CFG::write (std::ostream& os) {
  std::cout << "terminales_: " << std::endl;
  write_terminales_ (os);
  std::cout << "no terminales_: " << std::endl;
  write_no_terminales_ (os);
  std::cout << "arranque_: " << std::endl;
  std::cout << arranque_ << std::endl;
  std::cout << "producciones_: " << std::endl;
  write_producciones_ (os);
  return os;
}
std::ofstream& CFG::write_file (std::ofstream& os) {
  os << terminales_.size() << std::endl;
  write_terminales_(os);
  os << no_terminales_.size() << std::endl;
  write_no_terminales_(os);
  os << arranque_ << std::endl;
  os << producciones_.size() << std::endl;
  write_producciones_(os);
  return os;
}
std::ostream& CFG::write_terminales_ (std::ostream& os) {
  for (Conjunto::iterator it = terminales_.begin(); it != terminales_.end(); it++) {
    os << *it << std::endl;
  }
  return os;
}
std::ostream& CFG::write_no_terminales_ (std::ostream& os) {
  for (Conjunto::iterator it = no_terminales_.begin(); 
	it != no_terminales_.end(); it++) {
    os << *it << std::endl;
  }
  return os;
}
std::ostream& CFG::write_arranque_ (std::ostream& os) {
  os << arranque_; 
  return os;
}

std::ostream& CFG::write_producciones_ (std::ostream& os) {
  producciones_.write(os);
  return os;
}
