#include "../includes/core.hpp"

// TODO: delete debug variables from lexer ;
// TODO: explain error manager;
// TODO: explain data structure selection;
// TODO: handle errors with input;
// TODO: visualization class;

// try catch for data types;
// check for overlap (bigge value)
// obligatory parameters for the input;

// void	print_node(const Vertex & vertex)
// {
// 	std::cout << vertex.Node_type << std::endl;
// 	std::cout << vertex.Number_of_ports << std::endl;
// 	std::cout << vertex.Node_GUID << std::endl;
// 	std::cout << vertex.Port_GUID << std::endl;
// 	std::cout << vertex.SystemGUID << std::endl;
// 	std::cout << vertex.Node_description << std::endl;
// 	std::cout << vertex.LID << std::endl;
// 	std::cout << vertex.Vendor_ID << std::endl;
// 	std::cout << vertex.DeviceID << std::endl;
// 	std::cout << vertex.Revision << std::endl;
// 	std::cout << vertex.Link_State << std::endl;
// }

int		main(void)
{
	Core core("./test_file/opensm-subnet.lst"); /* init of the core class */

	core.main_cycle(); /* start of the main routine */

	system("leaks -q infiniBand_network_graph");

	return (0);
}