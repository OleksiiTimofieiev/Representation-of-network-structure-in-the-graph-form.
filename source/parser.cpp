#include "../includes/parser.hpp"

Parser::Parser() {}
Parser::~Parser(){}

void Parser::parse(const std::pair<Vertex, Vertex> & line, Database & database)
{
	database.hash.insert({line.first.Node_GUID, line.first});
	database.hash[line.first.Node_GUID].edges.push_back("12345");
}

	// hash.insert(std::make_pair(std::to_string(i), test(i, i)));
	// // hash.insert(std::make_pair("2", test(2)));
	// // hash.insert(std::make_pair("3", test(3)));

	// std::for_each(hash.begin(), hash.end() , [](std::pair<std::string, test> element){
	// 			std::cout << element.first << " :: "<< element.second.param1 << std::endl;
	// 			});