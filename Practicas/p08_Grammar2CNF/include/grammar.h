/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * 
 * @subject: 
 * 
 * @file grammar.h
 * @author Ezequiel Hernández Poleo (alu0101735399@ull.edu.es)
 * @date 2025-10-29
 * @brief 
 */

#pragma once

#include <map>
#include <set>
#include <string>

#include "../include/alphabet.h"

using NTSymbol = std::string;

class Grammar{
 public:
  Grammar(const Alphabet& alphabet, const std::set<NTSymbol>& non_terminal_symbols,
  const NTSymbol start_symbol, const std::multimap<NTSymbol, std::string>& productions) :
  alphabet_{alphabet}, non_terminal_symbols_{non_terminal_symbols}, start_symbol_{start_symbol},
  productions_{productions} {}

  // Getters
  Alphabet getAlphabet() const {return alphabet_;}
  std::set<NTSymbol> getNonTerminalSymbols() const {return non_terminal_symbols_;}
  NTSymbol getStartSymbol() const {return start_symbol_;}
  std::multimap<NTSymbol, std::string> getProductions() const {return productions_;}
  
  // Simplify checker
  bool NoEmptyProduction();
  bool NoUnitProduction();
  bool NoEmptyORUnitProductions();

  // CNF
  Grammar ChomskyNormalForm();
 private:
  // Alphabet used for storing the terminal symbols of the grammar.
  Alphabet alphabet_;

  // A set made of NTSymbol (char) which contains every single non terminal symbol written in the input .gra file.
  std::set<NTSymbol> non_terminal_symbols_;

  // NTSymbol (char) which represents the start symbol (símbolo de arranque)
  NTSymbol start_symbol_;
  
  // MultiMap used for storing the productions, (char -> string), I personally used this data
  // structure because there will be repeated keys, as there can be multiple productions asociated
  // with the same non termiinal symbol. So this is the perfect data structure for representing
  // productions.
  std::multimap<NTSymbol, std::string> productions_;
};

std::ostream& operator<<(std::ostream& out, const Grammar& grammar);