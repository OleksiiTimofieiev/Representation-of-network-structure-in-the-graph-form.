#include "../includes/core.hpp"

// TODO: explain error management;
// TODO: explain data structure selection;
// TODO: explain logic in lines;

// TODO: handle errors with input;

// -          show node neighbors <Node GUID>

// printing all neighbors of the node including DWN ports as follows:

// Local Port, Local Port GUID, Peer Port, Peer Port GUID, Link State

// try catch for data types;
// check for overlap (bigge value)
// obligatory parameters for the input;

int		main(void)
{
	Core core("./test_file/opensm-subnet.lst"); /* init of the core class */

	core.main_cycle(); /* start of the main routine */

	system("leaks -q infiniBand_network_graph"); /* leaks detection */

	return (0);
}