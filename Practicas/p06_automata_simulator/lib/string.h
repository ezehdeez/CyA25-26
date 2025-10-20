/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * 
 * @subject: CyA 25-26
 *           P06 - Diseño e implemetación de un simulador de autómatas finitos
 * 
 * @file string.h
 * @author Ezequiel Hernández Poleo (alu0101735399@ull.edu.es)
 * @date 2025-10-16
 * @brief 
 */

#pragma once

#include <string>
#include "alphabet.h"

typedef char symbol;

class String{
 public:
  // Default constructor 
  String() : alphabet_{Alphabet ("")}, string_{"&"}, size_{0} {}
  // Constructor from a string and an alphabet
  String(const std::string& string, const Alphabet& alphabet) : alphabet_(alphabet), 
  string_(string), size_(string.size()) {}
  // Copy constructor
  String(const String& string) : alphabet_{string.alphabet_}, string_{string.string_}, 
  size_{string.size_} {}
  // Getters
  size_t getSize() const {return size_;}
  std::string getString() const {return string_;}
  Alphabet getAlphabet() const {return alphabet_;}
  // Methods
  String Inverse();
  
  bool operator<(const String& other) const; 
 private:
  Alphabet alphabet_;
  std::string string_;
  size_t size_;
};

String operator+(String& String1, String& String2);
std::ostream& operator<<(std::ostream& out, const String& String);