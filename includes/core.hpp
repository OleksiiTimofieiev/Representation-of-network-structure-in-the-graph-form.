#ifndef CORE_HPP
#define CORE_HPP

#include <fstream>

#include "lexer.hpp"
#include "parser.hpp"

class Core
{
private:
	Lexer		lexer; /* class to validate input */
	Parser		parser; /* class to push input to memory */
	Database	database; /* class to keep the information */

	std::ifstream fin; /* file descriptor to the input file */
	std::string input; /* container for the line read */
	std::string path;

	std::pair<Vertex, Vertex> line; /* buffer container for the line read */

	int line_number = 0;
	int not_ok = 0;
public:
	Core(const std::string path);
	~Core();
	void	main_cycle(void);
};




#endif