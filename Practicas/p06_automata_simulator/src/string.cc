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

#include "../lib/string.h"

typedef char symbol;

/**
 * @brief When applied to a string, this method returns the inverse.
 * 
 * @return String 
 */
String String::Inverse() {
  std::string inversed_string;
  for(int i = getSize() - 1; i >= 0; i--) {
    inversed_string.push_back(getString()[i]);
  }
  String inverse(inversed_string, alphabet_);
  return inverse;
}

/**
 * @brief This operator overloading is used for set sorting.
 * 
 * @param other 
 * @return bool 
 */
bool String::operator<(const String& other) const{
  return string_ < other.string_;
}

/**
 * @brief Operator overloading that is used as a String concatenation, they should
 *        have the same alphabet.
 * 
 * @param String1 
 * @param String2 
 * @return String 
 */
String operator+(String& string1, String& string2) {
  std::string concatenated_string = string1.getString() + string2.getString();
  Alphabet alphabet = string1.getAlphabet();
  String concatenated(concatenated_string, alphabet);
  return concatenated;
}

/**
 * @brief Operator overloading for Strings.
 * 
 * @param out 
 * @param String 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, const String& String) {
  std::string String_content = String.getString();
  out << String_content;
  return out;
}