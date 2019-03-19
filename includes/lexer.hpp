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

		std::pair<Vertex, Vertex> regex_check(std::string str, int *not_ok, int line_number);
};

#endif
