/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * 
 * @subject: CyA 25-26
 *           P08 - Gramáticas en Forma Normal de Chomsky
 * 
 * @file main.cc
 * @author Ezequiel Hernández Poleo (alu0101735399@ull.edu.es)
 * @date 2025-10-29
 * @brief 
 */

#include <iostream>
#include <fstream>
#include <string>

#include "../include/grammar.h"
#include "../include/grammar_loader.h"
#include "../include/functions.h"

int main(int argc, char* argv[]) {
  if(argc == 2) {
    HelpMessage(argv);
  }
  CheckCorrectParameters(argc, 3);
  FileCheck(argv[1], argv[2]);
  GrammarLoader::GrammarData data = GrammarLoader::Loader(argv[1]);
  Grammar grammar(data.alphabet_, data.non_terminal_symbols_, data.start_symbol_, data.productions_);
  std::ofstream output_file{argv[2]};
  output_file << grammar.ChomskyNormalForm();
  std::cout << "### DEPURACION: GRAMMAR DATA ###" << std::endl;
  std::cout << "Alphabet: " << data.alphabet_ << std::endl;
  std::cout << "Non Terminal Symbols: ";
  for(auto symbol : data.non_terminal_symbols_) {
    std::cout << symbol << " ";
  }
  std::cout << std::endl;
  std::cout << "Start Symbol: " << data.start_symbol_ << std::endl;
  std::cout << "Productions: ";
  for(auto symbol : data.productions_) {
    std::cout << symbol.first << "->" << symbol.second << " ";
  }
  std::cout << std::endl;
}