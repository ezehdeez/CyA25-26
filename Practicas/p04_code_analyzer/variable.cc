/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * 
 * @subject: CyA 25-26
 *           P04 - Expresiones regulares en C++
 * 
 * @file variable.cc
 * @author Ezequiel Hernández Poleo (alu0101735399@ull.edu.es)
 * @date 2025-10-05
 * @brief 
 */

#include <regex>
#include "variable.h"

Variable::Variable(const int line, const std::smatch& content) {
  /**     ^\s*(int|double)\s+(\w+)\s?((=)\s?(\d+(.\d+)?))?;$    REGEX
   * content[1] -> var type
   * content[2] -> var name
   * content[3] -> example: (= 18723817)
   * content[4] -> "="
   * content[5] -> var value
   */
  line_ = line;
  initialized_ = (content[4] == "=") ? 1 : 0;
  value_ = (initialized_) ? content[5].str() : "";
  var_name_ = content[2];
  variable_type_ = (content[1] == "int") ? 0 : 1;
}

std::ostream& operator<<(std::ostream& out, Variable& variable) {
  out << "[Line " << variable.getLine() << "] " << ((variable.getVariableType()) ?
  "DOUBLE: " : "INT: ") << variable.getVarName() << ((variable.getInitialized()) ?
  " = " : "") << ((variable.getInitialized()) ? variable.getValue() : "");
  return out;
}