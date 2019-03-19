#include "../includes/visualizer.hpp"

Visualizer::Visualizer() {}

Visualizer::~Visualizer() {}

void	Visualizer::show_nodes_all(const Database & database) const
{
	std::for_each(database.hash.begin(), database.hash.end(), [](std::pair<std::string, Vertex> element) {
		std::cout << element.second << std::endl;
	});
};

void	Visualizer::show_node(const Database & database, const std::string str) const 
{
	auto hash = database.hash;

	std::cout << hash[str] << std::endl;

};

void	Visualizer::show_node_neighbors(const Database & database, const std::string str) const
{
	auto hash = database.hash;

	auto edges = hash[str].edges;

	std::for_each(edges.begin(), edges.end(), [](std::pair<std::string, std::string> element) {
		std::cout << element.second << std::endl;
	});
}

void	Visualizer::show_node_reg_exp(const Database & database, const std::string str) const
{
	auto hash = database.hash;

	std::for_each(hash.begin(), hash.end(), [str](std::pair<std::string, Vertex> element)
	{

		std::cout << element.second << str << std::endl;
	});
}
