#include "../includes/core.hpp"

Core::Core(const std::string var) : path(var)
{
	funcs[0] = [&] (void) { show_nodes_all(); };
	funcs[1] = [&] (void) { show_node(); };
	funcs[2] = [&] (void) { show_node_neighbors(); };
	funcs[3] = [&] (void) { show_node_reg_exp(); };
}
Core::~Core(){}

void Core::menu(void) const
{
	std::cout << "\x1b[36mPlease, select an option:[0 - 4] \x1B[0m" << std::endl
			  << std::endl;
	std::cout << "\x1b[32m0.\x1b[0m show nodes all;" << std::endl;
	std::cout << "\x1b[32m1.\x1b[0m show node;" << std::endl;
	std::cout << "\x1b[32m2.\x1b[0m show node neighbors;" << std::endl;
	std::cout << "\x1b[32m3.\x1b[0m show node reg exp;" << std::endl;
	std::cout << "\x1b[32m4.\x1b[0m terminate the program;" << std::endl;
}

void Core::show_nodes_all(void) const
{
	visualizer.show_nodes_all(database);
}

void Core::show_node(void) const
{
	std::string base("NodeGUID:");
	
	std::string node_guid;

	std::cout << "\x1b[36mPlease, enter the Node GUID. format: 7cfe900300f21b00\x1B[0m" << std::endl;

	std::getline(std::cin, node_guid);
	std::string input_buf = base + node_guid;

	visualizer.show_node(database, input_buf);
}

void Core::show_node_neighbors(void) const
{
	std::string base("NodeGUID:");

	std::string node_guid;
	std::cout << "\x1b[36mPlease, enter the Node GUID. format: 7cfe900300f21b00\x1B[0m" << std::endl;

	std::getline(std::cin, node_guid);
	std::string input_buf = base + node_guid;

	visualizer.show_node_neighbors(database, input_buf);
}

void Core::show_node_reg_exp(void) const
{
	std::string base("NodeGUID:");
	std::string regex;
	std::cout << "\x1b[36mPlease, enter the Node GUID. format: regex\x1B[0m" << std::endl;

	std::getline(std::cin, regex);
	std::string input_buf = base + regex;

	visualizer.show_node_reg_exp(database, input_buf);
}

void Core::console_input_handler(void)
{
	std::string base("NodeGUID:");
	func_option _func_option;
	bool 		read_error = true;

	while (42)
	{

		if (read_error)
			this->menu();

		if (std::getline(std::cin, input))
		{
			if (input == "4")
				break;
			else if (input != "0" && input != "1" && input != "2" && input != "3")
			{
				std::cout << "\x1b[33mPlease, select correct option.\x1B[0m" << std::endl;
				
				read_error = false;
				this->menu();

				continue ;
			}

			read_error = true;

			if (input == "0")
				_func_option = SHOW_NODES_ALL;
			else if (input == "1")
				_func_option = SHOW_NODE;
			else if (input == "2")
				_func_option = SHOW_NODE_NEIGHBOURS;
			else if (input == "3")
				_func_option = SHOW_NODE_REG_EXP;

			funcs[_func_option]();

			std::cout << "\u001b[36;1mDo you want to continue ? + / - \x1B[0m" << std::endl;

			if (std::getline(std::cin, input))
			{
				if (input == "+")
					continue;
				else if (input == "-")
					break ;
				else
					std::cout << "\x1b[33mPlease, select correct option.\x1B[0m" << std::endl;
			}
		}
		else 
			break ;
	}
	std::cout << "\x1B[35mThank you for using the program.\x1B[0m" << std::endl;
}

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
		std::cout << "\n";
		std::cout << GREEN << "Lexer && Parser running ...\n\n" << RESET;
		while (!(fin.eof()))
		{
			getline(fin, input);

			line = lexer.regex_check(input);

			if (line.first.Node_type != "empty_str")
			{
				parser.parse(line, database);
			}
		}
	}

	fin.close();

	std::cout << std::endl;

	this->console_input_handler();
}