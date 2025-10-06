/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * 
 * @subject: CyA 25-26
 *           P04 - Expresiones regulares en C++
 * 
 * @file main.cc
 * @author Ezequiel Hernández Poleo (alu0101735399@ull.edu.es)
 * @date 2025-10-05
 * @brief 
 */

#include <fstream>
#include <string>
#include <regex>
#include "code_struc.h"
#include "functions.h"

int main(int argc, char* argv[]) {
  std::ifstream input_file(argv[1]);
  std::ofstream output_file(argv[2]);
  HelpMessage(argv);
  CheckCorrectParameters(argc, 3);
  FileCheck(input_file, output_file);
  std::string input_file_name(argv[1]);
  CodeStructure code_structure(input_file_name);
  FillCodeStructure(input_file, code_structure);
  output_file << code_structure;
  return 0;
}