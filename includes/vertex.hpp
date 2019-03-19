#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
#include <regex>

typedef enum 	vertex_option
{
	left_node = 1,
	right_node
}				options_of_construction; 		

class 			Vertex // uses
{
	public:
		std::string 			Node_type;
		std::string 			Number_of_ports;
		std::string 			Node_GUID;
		std::string 			Port_GUID;
		std::string 			SystemGUID;
		std::string 			Node_description;
		std::string 			LID;
		std::string 			Vendor_ID;
		std::string 			DeviceID;
		std::string 			Revision;
		std::string 			Link_State;
		std::vector<std::string> edges;

	  	Vertex(void);
		Vertex(const std::smatch &result, options_of_construction var);
		~Vertex(void);
};

#endif