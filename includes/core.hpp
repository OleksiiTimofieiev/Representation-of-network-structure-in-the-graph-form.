#ifndef CORE_HPP
#define CORE_HPP

#include <fstream>
#include <functional>
#include <vector>

#include "lexer.hpp"
#include "parser.hpp"
#include "visualizer.hpp"
#include "vertex.hpp"

typedef enum var 
{
	SHOW_NODES_ALL = 0,
	SHOW_NODE,
	SHOW_NODE_NEIGHBOURS,
	SHOW_NODE_REG_EXP,
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

		void 						menu(void) const;
		void						show_nodes_all(void) const;
		void 						show_node(void) const;
		void 						show_node_neighbors(void) const;
		void						show_node_reg_exp(void) const;
		void 						console_input_handler(void);

		std::function<void(void)> 	funcs[4];

	public: 
		Core						(const std::string path);
		~Core						();
		
		void						main_cycle(void);
};

#endif