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
	
	if (hash[str].Node_type != "empty_str")
		std::cout << hash[str] << std::endl;
	else
		std::cout << MAGENTA << "Node not found." << RESET << std::endl;
};

void	Visualizer::show_node_neighbors(const Database & database, const std::string str) const
{
	auto hash = database.hash;

	auto edges = hash[str].edges;

	auto size = hash[str].edges.size();

	if (size > 0)
	{
		for (auto & it : edges)
		{
			std::cout << YELLOW << "Local_Port       \x1b[35m-> " << GREEN << &hash[str].Port[3] << RESET << std::endl;
			std::cout << YELLOW << "Local_Port_GUID  \x1b[35m-> " << GREEN << "0x" << &hash[str].Port_GUID[9] << RESET << std::endl;

			std::cout << YELLOW << "Peer_Port        \x1b[35m-> " << GREEN << &it.Port[3] << RESET << std::endl;
			std::cout << YELLOW << "Peer_Port_GUID   \x1b[35m-> " << GREEN << "0x" << &it.Port_GUID[9] << RESET << std::endl;

			std::cout << YELLOW << "Link_State       \x1b[35m-> " << GREEN << it.Link_State << RESET << std::endl
						<< std::endl;
		}
	}
	else
		std::cout << MAGENTA << "Node not found." << RESET << std::endl;
}

void	Visualizer::show_node_reg_exp(const Database & database, const std::string regex) const
{
	auto 		hash = database.hash;
	const 		std::regex regex_rule(regex);
	std::smatch result;
	bool		found = false;

	for (auto & it : database.hash)
	{
		if (std::regex_match(it.second.Node_GUID, result, regex_rule))
		{
			found = true;
			std::cout << it.second  << std::endl;
		}
	}
	if (!found)
		std::cout << MAGENTA << "Node not found." << RESET << std::endl;
}
