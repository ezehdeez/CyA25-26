/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * 
 * @subject: CyA 25-26
 *           P06 - Diseño e implemetación de un simulador de autómatas finitos
 * 
 * @file main.cc
 * @author Ezequiel Hernández Poleo (alu0101735399@ull.edu.es)
 * @date 2025-10-16
 * @brief 
 */

#include <iostream>

#include "../lib/automata.h"
#include "../lib/automata_loader.h"
#include "../lib/functions.h"
#include "../lib/alphabet.h"

int main(int argc, char* argv[]) {
  if(argc == 2) {
    HelpMessage(argv);
  }
  CheckCorrectParameters(argc, 3);
  std::ifstream input_fa{argv[1]};
  std::ifstream input_file{argv[2]};
  FileCheck(input_file, input_fa);
  AutomataLoader::AutomataData data = AutomataLoader::Loader(argv[1]);
  std::cout << "Post Loader" << std::endl;
  Automata automata(data.alphabet, data.starter_state, data.num_states, data.states);
  std::cout << "Automata loaded" << std::endl;
  std::cout << "######## AUTOMATA DATA ########" << std::endl;
  std::cout << automata.getAlphabet() << std::endl;
  std::cout << automata.getNumStates() << std::endl;
  std::cout << automata.getStarterState() << std::endl;
  std::cout << automata.getStates().size() << std::endl;
  std::map<int, State>::iterator it1;
  std::cout << "STATES:" << std::endl;
  std::map<int, State> states = automata.getStates();
  for(it1=states.begin(); it1 != states.end(); it1++) {
    std::cout << "Estado: " << it1->second.getState() << " con estas transiciones: " << it1->second.getNumTransitions() << std::endl;
  }
  return 0;
}