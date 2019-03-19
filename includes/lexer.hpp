#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <regex>

class Lexer
{
	public:
		Lexer(void);
		~Lexer(void);

	void	regex_check(std::string str, int *not_ok, int line_number);
};

#endif
