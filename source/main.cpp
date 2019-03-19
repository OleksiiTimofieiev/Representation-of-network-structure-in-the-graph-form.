#include "../includes/core.hpp"

// TODO: explain error management;
// TODO: explain data structure selection;
// TODO: explain logic in lines;


// try catch for data types;
// check for overlap (big value)

// obligatory parameters for the input;
// TODO: handle errors with input;

int		main(void)
{
	Core core("./test_file/opensm-subnet.lst"); /* init of the core class */

	core.main_cycle(); /* start of the main routine */

	system("leaks -q infiniBand_network_graph"); /* leaks detection */

	return (0);
}

// error management: 

// - not unique NodeGUID
// - full confirmity with the line structure for every parameter