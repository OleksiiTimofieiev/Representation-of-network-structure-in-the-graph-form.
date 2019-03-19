#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP

#include "database.hpp"

class Visualizer
{
	public:
		Visualizer();
		~Visualizer();

		void	show_nodes_all(const Database & database) const;
		void 	show_node(const Database &database, const std::string str) const;
		void	show_node_neighbors(const Database &database, const std::string str) const;
		void	show_node_reg_exp(const Database &database, const std::string regex) const;
};

#endif