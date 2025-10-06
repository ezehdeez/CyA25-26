/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * 
 * @subject: CyA 25-26
 *           P04 - Expresiones regulares en C++
 * 
 * @file comment.h
 * @author Ezequiel Hernández Poleo (alu0101735399@ull.edu.es)
 * @date 2025-10-05
 * @brief 
 */

#pragma once

#include <regex>

enum class CommentType{
    SINGLE_LINE,
    MULTI_LINE,
}; 

class Comment{
 public:
  Comment(const int start_line, const int end_line, const std::smatch& content, 
  bool is_multiline, bool is_description = false) : start_line_{start_line}, 
  end_line_{end_line}, body_{content[0]}, is_description_{is_description} {
    comment_type_ = (is_multiline) ? CommentType::MULTI_LINE : CommentType::SINGLE_LINE;
  }

  Comment(const int start_line, const int end_line, const std::string& body, 
  bool is_multiline, bool is_description = false) : start_line_{start_line}, 
  end_line_{end_line}, body_{body}, is_description_{is_description} {
    comment_type_ = (is_multiline) ? CommentType::MULTI_LINE : CommentType::SINGLE_LINE;
  }
  // ^\/\/[\w\W]*?$      REGEX Single Line Comment
  //
  CommentType getCommentType() const {return comment_type_;}
  int getStartLine() const {return start_line_;}
  int getEndLine() const {return end_line_;}
  std::string getBody() const {return body_;}
  bool GetIsDescription() const {return is_description_;}

 private:
  CommentType comment_type_;
  int start_line_;
  int end_line_;
  std::string body_;
  bool is_description_;
};

std::ostream& operator<<(std::ostream& out, Comment& comment);

//TODO: en el main para detectar los multilinea uso regex, y para guardarlo todo
//      en un string hago un while anidado pa q siga pillando lineas, y voy 
//      concatenando "\n + la linea nueva".