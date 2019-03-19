#include <iostream>
#include <fstream>
#include <regex>

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
			std::cout << input << std::endl;
		}
	}
	fin.close();

	return (0);
}