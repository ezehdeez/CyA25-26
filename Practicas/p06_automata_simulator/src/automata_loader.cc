/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * 
 * @subject: 
 * 
 * @file automata_loader.cc
 * @author Ezequiel Hernández Poleo (alu0101735399@ull.edu.es)
 * @date 2025-10-17
 * @brief 
 */

#include <map>
#include <fstream>
#include <string>
#include <sstream>

#include "../lib/automata_loader.h"
#include "../lib/state.h"

AutomataLoader::AutomataData AutomataLoader::Loader(const std::string& file_name) {
  std::cout << "Entrada al loader" << std::endl;
  std::ifstream input_file{file_name};
  std::string line;
  std::map<int, State> states;
  // Alphabet made of the first line
  getline(input_file, line);
  Alphabet alphabet(line);
  // num_states taken from the second line
  getline(input_file, line);
  int num_states = stoi(line);
  // starter_state taken from the third line
  getline(input_file, line);
  int starter_state = stoi(line);
  while(getline(input_file, line)) {
    std::istringstream iss(line);
    int state_name, is_aceptation, num_transitions;
    iss >> state_name >> is_aceptation >> num_transitions;
    State state(state_name, is_aceptation, num_transitions);
    for(int i = 0; i < num_transitions; ++i) {
      char symbol;
      int destination;
      iss >> symbol >> destination;
      state.InsertTransition(symbol, destination);
    }
    states.insert({state_name, state});
  }
  std::cout << "Salida del loader" << std::endl;
  return AutomataData(states, starter_state, num_states, alphabet);
}