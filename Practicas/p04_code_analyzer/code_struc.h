/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * 
 * @subject: 
 * 
 * @file code_struc.h
 * @author Ezequiel Hernández Poleo (alu0101735399@ull.edu.es)
 * @date 2025-10-06
 * @brief 
 */

#pragma once

#include <fstream>
#include <string>
#include "comment.h"
#include "variable.h"
#include "statement.h"

class CodeStructure{
 public:
  CodeStructure(const std::string& input_file) : input_file_{input_file} {};

  std::string getInputFile() const {return input_file_;}

  std::vector<Variable> getVariables() const {return variables_;}
  void AddVariable(const Variable& variable) {variables_.push_back(variable);}

  std::vector<Statement> getStatements() const {return statements_;}
  void AddStatement(const Statement& statement) {statements_.push_back(statement);}

  std::vector<Comment> getComments() const {return comments_;}
  void AddComment(const Comment& comment) {comments_.push_back(comment);}

  bool getHasMain() const {return has_main_;}
  void setMain(bool val) {has_main_ = val;}
 private:
  std::string input_file_ = "";
  std::vector<Variable> variables_;
  std::vector<Statement> statements_;
  std::vector<Comment> comments_;
  bool has_main_ = false;
};

std::ostream& operator<<(std::ostream& out, const CodeStructure code_structure);