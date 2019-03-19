#include <fstream>

#include "../includes/lexer.hpp"

// TODO: operand class;
// TODO: parser ;
// TODO: change the name of the binary file ;
// TODO: check for leaks;
// TODO: delete debug from lexer ;
// TODO: explain error manager;
// TODO: explain data structure selection;

// TODO: handle errors with input;

// space complexity: o(v) + o(e);
// unordered_map;
// try catch for data types;
// check for overlap (bigge value)
// obligatory prameters;

int		main(void)
{
	Lexer lexer; /* class to parse and validate input */

	std::string		input;
	std::string 	path = "./test_file/opensm-subnet.lst";

	std::ifstream 	fin;

	int line_number = 0;

	// int ok = 0;
	int not_ok = 0;

	fin.open(path);

	if (!fin.is_open())
	{
		std::cout << "No such file. Program was terminated." << std::endl;
		exit(0);
	}
	else
	{
		while (!(fin.eof()))
		{
			getline(fin, input);

			line_number++;

			lexer.regex_check(input, &not_ok, line_number);
		}
	}

	std::cout << "total not valid lines -> " << not_ok << std::endl;

	fin.close();

	return (0);
}