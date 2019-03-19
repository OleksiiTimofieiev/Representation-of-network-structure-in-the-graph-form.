#include "../includes/core.hpp"

Core::Core(const std::string var) : path(var) {}
Core::~Core(){}

void Core::console_input_handler(void)
{
	while (42)
	{
		std::cout << "\x1b[36mPlease, select an option:\x1B[0m" << std::endl << std::endl;

		if (std::getline(std::cin, input))
		{
			std::cout << "selected -> " << input << std::endl;


			if (input == "4")
				break;
			else if (input == "1")
			{
				// std::cout << "\x1b[36mPlease, select correct option.\x1B[0m" << std::endl << std::endl;
				continue ;
			}
			else if (input == "2")
			{
				continue ;
			}
			else if (input == "3")
			{
				continue;
			}
		};
	}
	std::cout << "\x1B[35mThank you for using the program.\x1B[0m" << std::endl;
}

void Core::main_cycle()
{
	// int lines = 0;
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

			// line_number++;

			line = lexer.regex_check(input);

			if (line.first.Node_type != "empty_str") // add validation func
			{
				// std::cout << "test" << std::endl;
				// lines++;
				// correct_lines(line.first);
				// correct_lines(line.second);

				parser.parse(line, database);
			}
			// std::cout << "---------------------"  << std::endl;
			// print_node(line.second);
		}
		// std::for_each(database.hash.begin(), database.hash.end(), [](std::pair<std::string, Vertex> element) {
		// 	std::cout << element.second.edges[0] << std::endl;
		// });
	}
	fin.close();

	this->console_input_handler();

	// std::cout << "total not valid lines -> " << not_ok << std::endl;
	// std::cout << "total lines 			-> " << lines << std::endl;

	// for (const auto & pair : database.hash)
	// {
	// 	std::cout << pair.second.Node_GUID << '\n';
	// }

	// std::string str = "NodeGUID:248a0703005ed970";


	/* testing */

	// visualizer.show_nodes_all(database);
	// visualizer.show_node(database, "NodeGUID:7cfe900300f21aa0");
	// visualizer.show_node_neighbors(database, "NodeGUID:7cfe9003004b0700");
	// visualizer.show_node_reg_exp(database, "NodeGUID:[A-Za-z0-9]+" /*, "(NodeGUID:[A-Za-z0-9]+)"*/);

}