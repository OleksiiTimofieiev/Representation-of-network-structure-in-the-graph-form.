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

	// std::string str = "NodeGUID:248a0703005ed970";


	/* testing */

	// visualizer.show_nodes_all(database);
	// visualizer.show_node(database, "NodeGUID:7cfe900300f21aa0");
	// visualizer.show_node_neighbors(database, "NodeGUID:7cfe9003004b0700");

	fin.close();
}