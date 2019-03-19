#include <fstream>

#include "../includes/lexer.hpp"
#include "../includes/parser.hpp"

// TODO: ADT main class;
// TODO: change the name of the binary file ;
// TODO: check for leaks;
// TODO: delete debug variables from lexer ;
// TODO: explain error manager;
// TODO: explain data structure selection;
// TODO: handle errors with input;
// TODO: visualization class;
// TODO: no leaks

// space complexity: o(v) + o(e);
// unordered_map;
// try catch for data types;
// check for overlap (bigge value)
// obligatory parameters;
// not unique inode
// add to the both vertices
// if do not exists, add to edges;
// use binary black - red tree

void	print_node(const Vertex & vertex)
{
	std::cout << vertex.Node_type << std::endl;
	std::cout << vertex.Number_of_ports << std::endl;
	std::cout << vertex.Node_GUID << std::endl;
	std::cout << vertex.Port_GUID << std::endl;
	std::cout << vertex.SystemGUID << std::endl;
	std::cout << vertex.Node_description << std::endl;
	std::cout << vertex.LID << std::endl;
	std::cout << vertex.Vendor_ID << std::endl;
	std::cout << vertex.DeviceID << std::endl;
	std::cout << vertex.Revision << std::endl;
	std::cout << vertex.Link_State << std::endl;
}

int		main(void)
{
	Lexer 			lexer; /* class to parse and validate input */
	Parser 			parser;
	Database 		database;

	std::string		input;
	std::string 	path = "./test_file/opensm-subnet.lst";

	std::ifstream 	fin;

	std::pair<Vertex, Vertex> line;

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

			line = lexer.regex_check(input, &not_ok, line_number);

			if (line.first.Node_type != "empty_str")
			{
				// std::cout << "test" << std::endl;
				parser.parse(line, database);
			}

			// std::cout << "---------------------"  << std::endl;

			// print_node(line.second);

		}
			// std::for_each(database.hash.begin(), database.hash.end(), [](std::pair<std::string, Vertex> element) {
			// 	std::cout << element.second.edges[0] << std::endl;
			// });
	}

	std::cout << "total not valid lines -> " << not_ok << std::endl;

	// for (const auto & pair : database.hash)
	// {
	// 	std::cout << pair.second.Node_GUID << '\n';
	// }

	std::string str = "NodeGUID:248a0703005ed970";

	// std::cout << database.hash[str].Node_type << std::endl;

	// size_t len = database.hash[str].edges.size();

	// for(size_t i = 0; i < len; i++)
	// 	std::cout << database.hash[str].edges[i] << std::endl;

	// std::for_each(database.hash.begin(), database.hash.end(), [](std::pair<std::string, Vertex> element) {
	// 	std::cout << element.second.edges[0] << std::endl;
	// });

	for (auto &it : database.hash[str].edges)
	{
		// Do stuff
		std::cout << it.first << std::endl;
	}

	fin.close();

	system("leaks -q graph");

	return (0);
}