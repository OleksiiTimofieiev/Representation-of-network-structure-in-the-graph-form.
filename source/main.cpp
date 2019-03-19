#include <iostream>
#include <fstream>
#include <regex>

void	regex_check(std::string str, int *not_ok) 
{
	const std::regex regex_rule("\\{ (CA|SW|RT) (Ports:[0-9]+) (SystemGUID:[A-Za-z0-9]+) (NodeGUID:[A-Za-z0-9]+) (PortGUID:[A-Za-z0-9]+) (VenID:[A-Za-z0-9]+) (DevID:[A-Za-z0-9]+) (Rev:[A-Za-z0-9]+) (\\{.+?\\}) (LID:[A-Za-z0-9]+) (PN:[A-Za-z0-9]+) \\} \\{ (CA|SW|RT) (Ports:[0-9]+) (SystemGUID:[A-Za-z0-9]+) (NodeGUID:[A-Za-z0-9]+) (PortGUID:[A-Za-z0-9]+) (VenID:[A-Za-z0-9]+) (DevID:[A-Za-z0-9]+) (Rev:[A-Za-z0-9]+) (\\{.+?\\}) (LID:[A-Za-z0-9]+) (PN:[A-Za-z0-9]+) \\} (PHY=(1x|2x|4x)) (LOG=(DWN|INIT|ARM|ACT)) (SPD=(5|10|20|14|25))");

	std::smatch result;

	if (std::regex_match(str, result, regex_rule))
	{

		// std::cout << "Whole match : " << result.str(0) << std::endl;
		// std::cout << "First capturing group is '" << result.str(1) << "' which is captured at index " << result.position(1) << std::endl;
		// std::cout << "Second capturing group is '" << result.str(2) << "' which is captured at index " << result.position(2) << std::endl;
		std::cout << "------ cool ------" << std::endl;
	}
	else
	{
		(*not_ok)++;
		std::cout << "****** not cool ******" << std::endl;
	}


	
}

int		main(void)
{
	std::string		input = "";
	std::string 	path = "./test_file/opensm-subnet.lst";
	std::ifstream 	fin;

	int line_number = 0;

	// int ok = 0;
	int not_ok = 0;

	fin.open(path);

	if (!fin.is_open())
	{
		std::cout << "No such file. Program was terminated." << std::endl;
		exit(0);
	}
	else
	{
		while (!(fin.eof()))
		{
			getline(fin, input);
			line_number++;

			std::cout << line_number << " -> ";
			regex_check(input, &not_ok);
		}
	}
			std::cout << not_ok << std::endl;
	fin.close();

	return (0);
}