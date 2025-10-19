/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * 
 * @subject: CyA 25-26
 *           P06 - Diseño e implemetación de un simulador de autómatas finitos
 * 
 * @file automaton.cc
 * @author Ezequiel Hernández Poleo (alu0101735399@ull.edu.es)
 * @date 2025-10-16
 * @brief 
 */

#include "../lib/automaton.h"

//TODO EpsilonClosure
std::set<int> Automaton::EpsilonClosure(const std::set<int>& states) {
  for(int state : states) {
    for(auto symbol : getStates().at(state).getTransitions()) {
      
    }
  }
}