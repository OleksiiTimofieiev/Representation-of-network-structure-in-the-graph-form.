#include "../includes/lexer.hpp"

/*
***************************************************** constructors left empty as the object is a functor type **********************************************
*/

Lexer::Lexer() {}
Lexer::~Lexer() {}

/*
***************************************************** input validation function  **********************************************
*/

std::pair<Vertex, Vertex> Lexer::regex_check(std::string str)
{
	const std::regex regex_rule("^\\{ (CA|SW|RT) (Ports:[0-9]+) (SystemGUID:[A-Za-z0-9]+) (NodeGUID:[A-Za-z0-9]+) (PortGUID:[A-Za-z0-9]+) (VenID:[A-Za-z0-9]+) (DevID:[A-Za-z0-9]+) (Rev:[A-Za-z0-9]+) (\\{.+?\\}) (LID:[A-Za-z0-9]+) (PN:[A-Za-z0-9]+) \\} \\{ (CA|SW|RT) (Ports:[0-9]+) (SystemGUID:[A-Za-z0-9]+) (NodeGUID:[A-Za-z0-9]+) (PortGUID:[A-Za-z0-9]+) (VenID:[A-Za-z0-9]+) (DevID:[A-Za-z0-9]+) (Rev:[A-Za-z0-9]+) (\\{.+?\\}) (LID:[A-Za-z0-9]+) (PN:[A-Za-z0-9]+) \\} (PHY=(1x|2x|4x)) (LOG=(DWN|INIT|ARM|ACT)) (SPD=(5|10|20|14|25))$");

	std::smatch 	result;
	options_of_construction option;

	if (std::regex_match(str, result, regex_rule))
	{
		option = left_node;
		Vertex left(result, option);

		option = right_node;
		Vertex right(result, option);
		
		line_number++;

		return (std::make_pair(left, right));
	}
	else
	{
		std::cout << RED << "line № " << RESET << line_number << " -> not valid input, according to regex" << std::endl;
		
		line_number++;

		return (std::make_pair(Vertex(), Vertex()));
	}
}