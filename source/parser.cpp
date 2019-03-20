#include "../includes/parser.hpp"

Parser::Parser() {}
Parser::~Parser(){}

void	Parser::parse(const std::pair<Vertex, Vertex> & line, Database & database)
{
	database.hash.insert({line.first.Node_GUID, line.first});
	database.hash.insert({line.second.Node_GUID, line.second});

	database.hash[line.first.Node_GUID].edges.push_front(line.second);
	database.hash[line.second.Node_GUID].edges.push_front(line.first);
}