#include <iostream>
#include <fstream>
#include <regex>

void	regex_check(std::string str) 
{
	const std::regex regex_rule("\\{ (CA) (Ports:01) (SystemGUID:7cfe9003004b0700) (NodeGUID:7cfe9003004b0700) (PortGUID:7cfe9003004b0700) (VenID:0002C9) (DevID:1013) (Rev:00000000) (\\{ime5 HCA-1\\}) (LID:0032) (PN:01) \\} \\{ (SW) (Ports:25) (SystemGUID:7cfe900300992080) (NodeGUID:7cfe900300f2da60) (PortGUID:7cfe900300f2da60) (VenID:000002C9) (DevID:CF080000) (Rev:000000A0) (\\{MF0;cs7500:CS7500/L17/U2\\}) (LID:00F9) (PN:0C) \\} (PHY=4x) (LOG=ACT) (SPD=25)");

	std::smatch result;

	if (std::regex_match(str, result, regex_rule))
	{
		std::cout << "------ cool ------" << std::endl;

		std::cout << "Whole match : " << result.str(0) << std::endl;
		std::cout << "First capturing group is '" << result.str(1)
			 << "' which is captured at index " << result.position(1)
			 << std::endl;
		std::cout << "Second capturing group is '" << result.str(2)
			 << "' which is captured at index " << result.position(2)
			 << std::endl;
	}
	else
	{
		std::cout << "****** not cool ******" << std::endl;
	}


	
}

int		main(void)
{
	std::string		input = "";
	std::string 	path = "./test_file/opensm-subnet.lst";
	std::ifstream 	fin;

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

			regex_check(input);
			std::cout << input << std::endl;
		}
	}
	fin.close();

	return (0);
}