#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "vertex.hpp"
#include <unordered_map>

class Database
{
	public:
		Database();
		~Database();

	std::unordered_map<std::string, Vertex> hash;
};

#endif