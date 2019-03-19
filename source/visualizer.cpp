#include "../includes/visualizer.hpp"

Visualizer::Visualizer() {}

Visualizer::~Visualizer() {}

void Visualizer::show_nodes_all(const Database &database) const
{
	std::for_each(database.hash.begin(), database.hash.end(), [](std::pair<std::string, Vertex> element) {
		std::cout << element.second << std::endl;
	});
};

void Visualizer::show_node(const Database & database, const std::string str) const 
{


	std::cout << database.hash[str] << std::endl;

};
