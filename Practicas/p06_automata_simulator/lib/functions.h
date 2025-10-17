/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * 
 * @subject: CyA 25-26
 *           P06 - Diseño e implemetación de un simulador de autómatas finitos
 * 
 * @file functions.h
 * @author Ezequiel Hernández Poleo (alu0101735399@ull.edu.es)
 * @date 2025-10-16
 * @brief Functions declarations.
 */

#pragma once

#include <fstream>

void CheckCorrectParameters(int argc, const int kCorrectNumber);
void FileCheck(std::ifstream& input_file, std::ifstream& input_fa);
void HelpMessage(char* argv[]);