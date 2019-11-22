#include "Produccion.h"

Produccion::Produccion () {
}
const size_t Produccion::size () {
return producciones__.size();
}
vpss& Produccion::get_producciones_ () {
return producciones__;
}
void Produccion::insert (std::string LI, std::string LD) {
  bool encontrado = false;
  for (int i = 0; i < producciones__.size(); i++) {
    if (LI == std::get<0> (producciones__[i]) && LD == std::get<1> (producciones__[i])) {
      encontrado = true;
      break;
    }
  }
  if (encontrado == false) producciones__.push_back (std::make_pair (LI, LD));
}
std::string& Produccion::LD (int i) {
  return std::get<1>(producciones__[i]);
}

std::string& Produccion::LI (int i) {
  return std::get<0>(producciones__[i]);
}

std::ostream& Produccion::write (std::ostream& os) {
  for (int i = 0; i < producciones__.size(); i++) {
    if (std::get<1>(producciones__[i]).size() == 1 && 
        std::isupper(std::get<1>(producciones__[i])[0])) {
      
      os << "La produccion " << std::get<0>(producciones__[i]) << " -> " 
         << std::get<1>(producciones__[i]) << " es unitaria" << std::endl; 
    }
    else if (std::get<1>(producciones__[i]).size() == 1 && std::get<1>(producciones__[i])[0] == '~') {
      
      os << "La produccion " << std::get<0>(producciones__[i]) << " -> " 
         << std::get<1>(producciones__[i]) << " es vacia" << std::endl; 
    }
    else {
      os << std::get<0>(producciones__[i]) << " -> " << std::get<1>(producciones__[i]) << std::endl;
    }
  }
return os;
}
