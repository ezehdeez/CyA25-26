/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * 
 * @subject: CyA 25-26
 *           P04 - Expresiones regulares en C++
 * 
 * @file functions.cc
 * @author Ezequiel Hernández Poleo (alu0101735399@ull.edu.es)
 * @date 2025-10-05
 * @brief This file contains utility functions used by the main program, such as 
 *        format checkers for files or parameters. Besides we have the OpSelector
 *        which dceides the operation that is going to be written in the output
 *        file.
 */

#include <iostream>
#include <fstream>
#include <regex>

#include "functions.h"

const std::regex variable_regex(R"(^\s*(int|double)\s+(\w+)\s?((=)\s?(\d+(.\d+)?))?;$)");
const std::regex statement_regex(R"(^\s*(while|for)[\s\S]*$)");
const std::regex single_line_regex(R"(^\/\/[\w\W]*?$)");
const std::regex multi_start_regex(R"(^\/\*[\w\W]*$)");
const std::regex multi_end_regex(R"(^[\w\W]*\*\/$)");
const std::regex main_regex(R"(^int main([\s\S]*)\W*\{$)");

/**
 * @brief This functions checks if the given number of arguments is ok.
 * 
 * @param argc 
 * @param kCorrectNumber 
 */
void CheckCorrectParameters(int argc, const int kCorrectNumber) {
  if(argc != kCorrectNumber) {
    std::cerr << "Modo de empleo: ./p02_strings <input_file> <output_file> opcode\n"
    << "Pruebe './p02_strings --help' para más información" << std::endl;
    exit(1);
  }
}

/**
 * @brief This functions checks if the given files are available for 
 *        reading/writing.
 * 
 * @param input_file 
 * @param output_file 
 */
void FileCheck(std::ifstream& input_file, std::ofstream& output_file) {
  if(!input_file) {
    std::cerr << "El archivo de entrada no se ha podido leer correctamente." << std::endl;
    exit(1);
  } else if(!output_file) {
    std::cerr << "El archivo de salida no se ha podido leer correctamente." << std::endl;
    exit(1);
  }
}

/**
 * @brief If the argument in the program is "--help" this function is going to
 *        print the help message.
 * 
 * @param argv 
 */
void HelpMessage(char* argv[]) {
  if(std::string(argv[1]) == "--help") {
    std::cout << "Este programa aceptará como parámetros un primer archivo de entrada" <<
    ".txt, un segundo archivo de salida .txt y un código de operación (opcode).\n" <<
    "Modo de empleo: ./p02_strings <input_file> <output_file> opcode\n\n" <<
    "Códigos de operación:\n" <<
    "\t[1] Alfabeto -> Escribe en el fichero salida el alfabeto de cada una de las cadenas de entrada.\n" <<
    "\t[2] Longitud -> Escribe en el fichero de salida la longitud de cada una de las cadenas de entrada.\n"
    "\t[3] Inversa -> Escribe en el fichero de salida la inversa de cada una de las cadenas de entrada.\n"
    "\t[4] Prefijos -> Escribe en el fichero de salida todos los prefijos de sus cadenas correspondientes.\n"
    "\t[5] Sufijos -> Escribe en el fichero de salida todos los sufijos de sus cadenas correspondientes.\n" << std::endl;
    exit(1);
  }
}

void FillCodeStructure(std::ifstream& input_file, CodeStructure& code_structure) {
  std::string line;
  int line_counter = 0;
  bool first_comment = true;
  while(std::getline(input_file, line)) {
    line_counter++;
    std::smatch matches;
    if(std::regex_search(line, matches, variable_regex)) {
      code_structure.AddVariable(Variable (line_counter, matches));
    } else if(std::regex_search(line, matches, statement_regex)) {
      code_structure.AddStatement(Statement (line_counter, matches));
    } else if(std::regex_search(line, matches, single_line_regex)) {
      code_structure.AddComment(Comment (line_counter, line_counter, matches, false));
    } else if(std::regex_search(line, matches, multi_start_regex)) {
      int start = line_counter;
      std::string comment_content = line;
      while(std::getline(input_file, line)) {
        line_counter++;
        comment_content += "\n" + line;
        if(std::regex_search(line, matches, multi_end_regex)) {
          break;
        }
      }
      code_structure.AddComment(Comment (start, line_counter, comment_content, true, first_comment));
      first_comment = false;
    } else if(std::regex_search(line, matches, main_regex)) {
      code_structure.setMain(true);
    }
  }
}