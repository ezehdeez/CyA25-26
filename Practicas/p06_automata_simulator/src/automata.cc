/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * 
 * @subject: CyA 25-26
 *           P06 - Diseño e implemetación de un simulador de autómatas finitos
 * 
 * @file automata.cc
 * @author Ezequiel Hernández Poleo (alu0101735399@ull.edu.es)
 * @date 2025-10-16
 * @brief 
 */

#include "../lib/automata.h"

//TODO EpsilonClosure
std::set<int> Automata::EpsilonClosure(const std::set<int>& states) {
  for(int state : states) {
    for(auto symbol : getStates().at(state).getTransitions()) {
      
    }
  }
}