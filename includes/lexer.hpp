#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <regex>
#include <utility>

typedef enum 	vertex_option
{
	left = 1,
	right
}				options_of_construction; 		

class 	Vertex // uses
{
	public:
		std::string 	Node_type;
		std::string 	Number_of_ports;
		std::string 	Node_GUID;
		std::string 	Port_GUID;
		std::string 	SystemGUID;
		std::string 	Node_description;
		std::string 	LID;
		std::string 	Vendor_ID;
		std::string 	DeviceID;
		std::string 	Revision;
		std::string 	Link_State;

	  	Vertex(void);
		Vertex(const std::smatch &result, options_of_construction var);
		~Vertex(void);
};

class Lexer
{
	public:
		Lexer(void);
		~Lexer(void);

		std::pair<Vertex, Vertex> regex_check(std::string str, int *not_ok, int line_number);
};

#endif
