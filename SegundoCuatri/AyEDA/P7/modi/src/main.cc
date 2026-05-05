/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * 
 * @subject: AyEDA - P7
 * 
 * @file main.cc
 * @author Ezequiel Hernández Poleo (alu0101735399@ull.edu.es)
 * @date 2026-04-16
 * @brief Main program entry point for the tree management application.
 */

#include "../include/functions.h"
#include "../include/nif.h"

#include <iostream>
#include <iomanip>

int main(int argc, char* argv[]) {
  std::srand(std::time(nullptr));
  std::cout << "\n";
  std::cout << "ABB vs AVL - Número de comparaciones en busqueda\n\n";
  std::cout << "| "
            << std::setw(8) << "N" << " | "
            << std::setw(6) << "Arbol" << " | "
            << std::setw(12) << "Primera" << " | "
            << std::setw(12) << "Media" << " | "
            << std::setw(12) << "Ultima" << " |\n";
  std::cout << "|----------|--------|--------------|--------------|--------------|\n";
  RunExperiment(100);
  RunExperiment(1000);
  RunExperiment(10000);
  std::cout << "\n";
  return 0;
}