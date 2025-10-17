/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * 
 * @subject: CyA 25-26
 *           P06 - Diseño e implemetación de un simulador de autómatas finitos
 * 
 * @file cadena.cc
 * @author Ezequiel Hernández Poleo (alu0101735399@ull.edu.es)
 * @date 2025-10-16
 * @brief 
 */

#include <iostream>
#include <string>

#include "../lib/chain.h"

typedef char symbol;

/**
 * @brief When applied to a chain, this method returns the inverse.
 * 
 * @return Chain 
 */
Chain Chain::Inverse() {
  std::string inversed_string;
  for(int i = getSize() - 1; i >= 0; i--) {
    inversed_string.push_back(getChain()[i]);
  }
  Chain inverse(inversed_string, alphabet_);
  return inverse;
}

/**
 * @brief This operator overloading is used for set sorting.
 * 
 * @param other 
 * @return bool 
 */
bool Chain::operator<(const Chain& other) const{
  return chain_ < other.chain_;
}

/**
 * @brief Operator overloading that is used as a chain concatenation, they should
 *        have the same alphabet.
 * 
 * @param chain1 
 * @param chain2 
 * @return Chain 
 */
Chain operator+(Chain& chain1, Chain& chain2) {
  std::string concatenated_string = chain1.getChain() + chain2.getChain();
  Alphabet alphabet = chain1.getAlphabet();
  Chain concatenated(concatenated_string, alphabet);
  return concatenated;
}

/**
 * @brief Operator overloading for chains.
 * 
 * @param out 
 * @param chain 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, const Chain& chain) {
  std::string chain_content = chain.getChain();
  out << chain_content;
  return out;
}