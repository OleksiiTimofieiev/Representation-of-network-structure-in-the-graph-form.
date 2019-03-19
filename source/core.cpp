#include "../includes/core.hpp"

Core::Core(const std::string var) : path(var)
{
	// x[0](&show_all);
	f[0] = [&](void) { show_all(); };
	f[1] = [&](void) { show_node(); };
	f[2] = [&](void) { show_all(); };
	f[3] = [&](void) { show_all(); };

	// x[1] = &Core::show_node;
}
Core::~Core(){}

void Core::menu(void) const
{
	std::cout << "\x1b[32m0.\x1b[0m show nodes all;" << std::endl;
	std::cout << "\x1b[32m1.\x1b[0m show node;" << std::endl;
	std::cout << "\x1b[32m2.\x1b[0m show node neighbors;" << std::endl;
	std::cout << "\x1b[32m3.\x1b[0m show node reg exp;" << std::endl;
	std::cout << "\x1b[32m4.\x1b[0m terminate the program;" << std::endl;
}

void Core::show_all(void) const
{
	visualizer.show_nodes_all(database);
}

void Core::show_node_neighbors(void) const
{
	std::string base("NodeGUID:");

	std::string node_guid;
	std::cout << "\x1b[36mPlease, enter the Node GUID. format: 7cfe900300f21aa0\x1B[0m" << std::endl;

	std::getline(std::cin, node_guid);
	std::string input_buf = base + node_guid;

	visualizer.show_node_neighbors(database, input_buf);
}

void Core::show_node(void) const
{
	std::string base("NodeGUID:");
	
	std::string node_guid;

	std::cout << "\x1b[36mPlease, enter the Node GUID. format: 7cfe900300f21aa0\x1B[0m" << std::endl;

	std::getline(std::cin, node_guid);
	std::string input_buf = base + node_guid;

	visualizer.show_node(database, input_buf);
}

void Core::console_input_handler(void)
{
	std::string base("NodeGUID:");

	while (42)
	{
		std::cout << "\x1b[36mPlease, select an option:[0 - 4] \x1B[0m" << std::endl;
		this->menu();

		if (std::getline(std::cin, input))
		{
			if (input == "4")
				break;
				
			if (input == "0")
			{
				this->f[0]();
				continue ;
			}
			else if (input == "1")
			{
				this->f[1]();
				continue ;
			}
			else if (input == "2")
			{
				this->f[2]();
				continue;
			}
			else if (input == "3")
			{
				std::string regex;
				std::cout << "\x1b[36mPlease, enter the Node GUID. format: regex\x1B[0m" << std::endl;
				
				std::getline(std::cin, regex);
				std::string input_buf = base + regex;
				
				visualizer.show_node_reg_exp(database, input_buf);
				
				continue;
			}
			else
			{
				std::cout << "selected -> " << input << std::endl;
				std::cout << "\x1b[33mPlease, select correct option.\x1B[0m" << std::endl;
				
				this->menu();
				
				continue ;
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