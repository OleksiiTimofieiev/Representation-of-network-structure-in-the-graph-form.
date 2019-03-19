#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <regex>
#include <utility>
#include "vertex.hpp"

class Lexer
{
	private:
		mutable size_t	line_number;
	public:
		Lexer(void);
		~Lexer(void);
		
		std::pair<Vertex, Vertex> regex_check(std::string str) const;
};

#endif
