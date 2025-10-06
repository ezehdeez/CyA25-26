/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * 
 * @subject: 
 * 
 * @file code_struc.cc
 * @author Ezequiel Hernández Poleo (alu0101735399@ull.edu.es)
 * @date 2025-10-06
 * @brief 
 */

#include "code_struc.h"

std::ostream& operator<<(std::ostream& out, const CodeStructure code_structure) {
  out << "PROGRAM: " << code_structure.getInputFile() << std::endl;
  out << "DESCRIPTION: " << std::endl;
  if(code_structure.getComments()[0].GetIsDescription() == true) {
    out << code_structure.getComments()[0].getBody();
  }
  out << "\n\n";
  out << "VARIABLES: \n";
  for(size_t i = 0; i < code_structure.getVariables().size(); i++) {
    out << code_structure.getVariables()[i] << std::endl;
  }
  out << "\n";
  out << "STATEMENTS: \n";
  for(size_t i = 0; i < code_structure.getStatements().size(); i++) {
    out << code_structure.getStatements()[i] << std::endl;
  }
  out << "\n";
  out << "MAIN: \n";
  out << ((code_structure.getHasMain()) ? "True" : "False") << std::endl;
  out << "\n";
  out << "COMMENTS: \n";
  for(size_t i = 0; i < code_structure.getComments().size(); i++) {
    out << code_structure.getComments()[i] << std::endl;
  }
  return out;
}