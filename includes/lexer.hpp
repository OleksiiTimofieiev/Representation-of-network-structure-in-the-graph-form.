#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <regex>
#include <utility>
#include "vertex.hpp"

class Lexer
{
	public:
		Lexer(void);
		~Lexer(void);
		void 						correct_lines( Vertex &vertex);
		std::pair<Vertex, Vertex> 	regex_check(std::string str);
};

#endif
