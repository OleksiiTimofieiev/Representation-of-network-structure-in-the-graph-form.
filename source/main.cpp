#include "../includes/core.hpp"

// TODO: delete debug variables from lexer ;
// TODO: explain error manager;
// TODO: explain data structure selection;
// TODO: handle errors with input;
// TODO: visualization class;
// TODO: core logic in lines;

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