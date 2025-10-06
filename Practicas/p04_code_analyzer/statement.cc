/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * 
 * @subject: CyA 25-26
 *           P04 - Expresiones regulares en C++
 * 
 * @file loop.cc
 * @author Ezequiel Hernández Poleo (alu0101735399@ull.edu.es)
 * @date 2025-10-05
 * @brief 
 */

#include "statement.h"

std::ostream& operator<<(std::ostream& out, Statement& statement) {
  if(statement.getTypeStr() == "for" || statement.getTypeStr() == "while") {
    out << "[Line " << statement.getLine() << "] LOOP: " << statement.getTypeStr();
  }
  return out;
}