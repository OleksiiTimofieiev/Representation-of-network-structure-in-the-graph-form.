#include "../includes/core.hpp"

Core::Core(const std::string var) : path(var) {}
Core::~Core(){}

void Core::main_cycle()
{

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

			if (line.first.Node_type != "empty_str") // add validation func
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

}