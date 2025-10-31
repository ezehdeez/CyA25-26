/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * 
 * @subject: 
 * 
 * @file grammar_loader.cc
 * @author Ezequiel Hernández Poleo (alu0101735399@ull.edu.es)
 * @date 2025-10-29
 * @brief 
 */

#include <fstream>
#include <sstream>

#include "../include/grammar_loader.h"

GrammarLoader::GrammarData GrammarLoader::Loader(const std::string& file_name) {
  std::ifstream input_file{file_name};
  std::string line;
  Alphabet alphabet;
  std::set<NTSymbol> non_terminal_symbols;
  NTSymbol start_symbol;
  std::multimap<NTSymbol, std::string> productions;
  // Alphabet
  getline(input_file, line);
  int terminal_symbol_number = stoi(line);
  for(int i = 0; i < terminal_symbol_number; i++) {
    getline(input_file, line);
    alphabet.InsertSymbol(line[0]);
  }
  // Non terminal symbols
  getline(input_file, line);
  int non_terminal_symbol_number = stoi(line);
  for(int i = 0; i < non_terminal_symbol_number; i++) {
    getline(input_file, line);
    if(i == 0) start_symbol = line;
    non_terminal_symbols.insert(line);
  }
  // Productions
  getline(input_file, line);
  int production_number = stoi(line);
  for(int i = 0; i < production_number; i++) {
    getline(input_file, line);
    std::stringstream sstream(line);
    NTSymbol ntsymbol;
    std::string production;
    sstream >> ntsymbol >> production;
    productions.insert({ntsymbol, production});
  }
  return GrammarData(alphabet, non_terminal_symbols, start_symbol, productions);
}