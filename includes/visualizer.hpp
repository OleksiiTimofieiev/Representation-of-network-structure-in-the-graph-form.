#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP

#include "database.hpp"

class Visualizer
{
private:
	/* data */
public:
	Visualizer(/* args */);
	~Visualizer();

	void	show_nodes_all(const Database & database) const;
	void 	show_node(const Database &database) const;
};

#endif