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

#include <stack>

#include "../lib/automaton.h"

std::set<int> Automaton::EpsilonClosure(const int state) {
  std::stack<int> stack;
  std::set<int> visited;
  stack.push(state);
  visited.insert(state);
  while(!stack.empty()) {
    int current = stack.top();
    stack.pop();
    std::pair<std::multimap<symbol, int>::const_iterator, std::multimap<symbol, int>::const_iterator> epsilon_range = states_[current].getTransitions().equal_range(EMPTY_STRING);
    for(auto it = epsilon_range.first; it != epsilon_range.second; it++) {
      int next = it->second;
      if(visited.find(next) == visited.end()) continue;
      visited.insert(next);
      stack.push(next);
    }
  }
  return visited;
}

std::set<int> Automaton::EpsilonClosure(const std::set<int>& states) {
  std::set<int> full_closure;
  for(int state : states) {
    std::set<int> closure = EpsilonClosure(state);
    full_closure.insert(closure.begin(), closure.end());
  }
  return full_closure;
}

bool Automaton::VerifyString(const std::string& string) {
  std::set<int> current_states;
  current_states.insert(starter_state_);
  current_states = EpsilonClosure(current_states);
  for(symbol c : string) {
    if(c == EMPTY_STRING) continue;
    if(alphabet_.CheckSymbol(c)) {
      return false;
    }
    std::set<int> new_states;
    for(int state : current_states) {
      std::multimap<symbol, int> transitions = states_[state].getTransitions();
      std::pair<std::multimap<symbol, int>::const_iterator, std::multimap<symbol, int>::const_iterator> range = transitions.equal_range(c);
      for(auto it = range.first; it != range.second; it++) {
        new_states.insert(it->second);
      }
    }
    if(new_states.empty()) {
      return false;
    }
    current_states = EpsilonClosure(new_states);
  }
  for(int state : current_states) {
    if(states_[state].getIsAceptation()) {
      return true;
    }
  }
  return false;
}