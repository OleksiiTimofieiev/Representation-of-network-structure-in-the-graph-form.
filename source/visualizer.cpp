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

	std::for_each(edges.begin(), edges.end(), [&database, str](std::pair<std::string, Vertex> element) {
		
		auto vertex = database.hash;

		std::cout << element.second;
		std::cout << YELLOW << "Port             \x1b[35m-> " << GREEN << vertex[str].Port_GUID << RESET << std::endl;
		std::cout << YELLOW << "Peer_Port        \x1b[35m-> " << GREEN << vertex[str].Port_GUID << RESET << std::endl;
		std::cout << YELLOW << "Peer_Port_GUID   \x1b[35m-> " << GREEN << vertex[str].Port_GUID << RESET << std::endl;
	});
}

void	Visualizer::show_node_reg_exp(const Database & database, const std::string regex) const
{
	auto 		hash = database.hash;
	const 		std::regex regex_rule(regex);
	std::smatch result;

	for (auto & it : database.hash)
	{
		if (std::regex_match(it.second.Node_GUID, result, regex_rule))
			std::cout << it.second  << std::endl;
	}
}
