/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * 
 * @subject: CyA 25-26
 *           P06 - Diseño e implemetación de un simulador de autómatas finitos
 * 
 * @file automaton.h
 * @author Ezequiel Hernández Poleo (alu0101735399@ull.edu.es)
 * @date 2025-10-16
 * @brief 
 */

#pragma once

#include <map>
#include <cassert>

#include "../lib/alphabet.h"
#include "../lib/state.h"
#include "../lib/string.h"

const char EMPTY_STRING = '&';

class Automaton{
 public:
  Automaton(const Alphabet& alphabet, const int starter_state, const int num_states, 
  const std::map<int, State>& states) : alphabet_{alphabet}, starter_state_{starter_state},
  num_states_{num_states}, states_{states} {}
  std::set<int> EpsilonClosure(const int state);
  std::set<int> EpsilonClosure(const std::set<int>& states);
  Alphabet getAlphabet() const {return alphabet_;}
  int getStarterState() const {return starter_state_;}
  int getNumStates() const {return num_states_;}
  std::map<int, State> getStates() const {return states_;}
  bool VerifyString(const String& string); //TODO Most important method
 private:
  Alphabet alphabet_;
  int starter_state_;
  int num_states_;
  std::map<int, State> states_;
};