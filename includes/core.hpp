#ifndef CORE_HPP
#define CORE_HPP

#include <fstream>
#include <functional>
#include <vector>

#include "lexer.hpp"
#include "parser.hpp"
#include "visualizer.hpp"

class Core;

// typedef std::function<void(void)> f;

enum 
{
	show_nodes_all = 0,
	show_node,
	show_node_neighbors,
	show_node_reg_exp,
}	func_option;

class Core
{
	private:
		Lexer						lexer; /* class to validate input */
		Parser						parser; /* class to push input to memory */
		Database					database; /* class to keep the information */
		Visualizer					visualizer; /* class for the data visualization */

		std::ifstream 				fin; /* file descriptor to the input file */
		std::string 				input; /* container for the line read */
		std::string 				path; /* path to the file for reading purposes */

		std::pair<Vertex, Vertex>	line; /* buffer container for the line read */
		void 						console_input_handler(void) ;
		void 						menu(void) const;
		void						show_all(void) const;
		void 						show_node(void) const;
		void 						show_node_neighbors(void) const;

		// f x[4];

		std::function<void(void)> f[4];

		public : 
			Core(const std::string path);
		~Core						();
		
		void						main_cycle(void);
};

#endif