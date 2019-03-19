#include "../includes/lexer.hpp"

/*
***************************************************** constructors left empty as the object is a functor type **********************************************
*/

Lexer::Lexer() {}
Lexer::~Lexer() {}

/*
***************************************************** input validation function  **********************************************
*/

void	Lexer::regex_check(std::string str, int *not_ok, int line_number)
{
	const std::regex regex_rule("^\\{ (CA|SW|RT) (Ports:[0-9]+) (SystemGUID:[A-Za-z0-9]+) (NodeGUID:[A-Za-z0-9]+) (PortGUID:[A-Za-z0-9]+) (VenID:[A-Za-z0-9]+) (DevID:[A-Za-z0-9]+) (Rev:[A-Za-z0-9]+) (\\{.+?\\}) (LID:[A-Za-z0-9]+) (PN:[A-Za-z0-9]+) \\} \\{ (CA|SW|RT) (Ports:[0-9]+) (SystemGUID:[A-Za-z0-9]+) (NodeGUID:[A-Za-z0-9]+) (PortGUID:[A-Za-z0-9]+) (VenID:[A-Za-z0-9]+) (DevID:[A-Za-z0-9]+) (Rev:[A-Za-z0-9]+) (\\{.+?\\}) (LID:[A-Za-z0-9]+) (PN:[A-Za-z0-9]+) \\} (PHY=(1x|2x|4x)) (LOG=(DWN|INIT|ARM|ACT)) (SPD=(5|10|20|14|25))$");

	std::smatch result;

	if (std::regex_match(str, result, regex_rule))
	{

		// std::cout << "Whole match : " << result.str(0) << std::endl;
		// std::cout << "First capturing group is '" << result.str(1) << "' which is captured at index " << result.position(1) << std::endl;
		// std::cout << "Second capturing group is '" << result.str(2) << "' which is captured at index " << result.position(2) << std::endl;
		// std::cout << "Second capturing group is '" << result.str(3) << "' which is captured at index " << result.position(3) << std::endl;
		// std::cout << "Second capturing group is '" << result.str(4) << "' which is captured at index " << result.position(4) << std::endl;
		// std::cout << "Second capturing group is '" << result.str(5) << "' which is captured at index " << result.position(5) << std::endl;
		// std::cout << "Second capturing group is '" << result.str(6) << "' which is captured at index " << result.position(6) << std::endl;
		// std::cout << "Second capturing group is '" << result.str(7) << "' which is captured at index " << result.position(7) << std::endl;
		// std::cout << "Second capturing group is '" << result.str(8) << "' which is captured at index " << result.position(8) << std::endl;
		// std::cout << "Second capturing group is '" << result.str(9) << "' which is captured at index " << result.position(9) << std::endl;
		// std::cout << "Second capturing group is '" << result.str(10) << "' which is captured at index " << result.position(10) << std::endl;

		// std::cout << "------ cool ------" << std::endl;

		for (std::smatch::iterator it = result.begin() + 1; it != result.end(); ++it)
			std::cout << *it << std::endl;
	}
	else
	{
		(*not_ok)++;
		std::cout << "line -> " << line_number << " ****** not cool ******" << std::endl;
	}
}