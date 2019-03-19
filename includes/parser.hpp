#ifndef PARSER_HPP
#define PARSER_HPP

#include "database.hpp"

class Parser
{
	public:
		Parser();
		~Parser();

		void	parse(const std::pair<Vertex, Vertex> &line, Database & database);
};

#endif