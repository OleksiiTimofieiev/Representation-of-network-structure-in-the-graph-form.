#include "../includes/core.hpp"

// validation: SW -> CA, SW, RT;
// type conversion;
// try catch for data types;
// check for overlap (big value)

int		main(void)
{
	Core core("./test_file/opensm-subnet.lst"); /* init of the core class */

	core.main_cycle(); /* start of the main routine */

	system("leaks -q infiniBand_network_graph"); /* leaks detection */

	return (0);
}

// error management: 
// explain logic in lines;
// - not unique NodeGUID
// - check if node exists;
// - full confirmity with the line structure for every parameter
// - left in string type in order to save place;
// - unordered map -> 0(1) for insert, find, delete, do not adds the items which are already in the container;
// - use of std::string for data saving; char *
// - 924 => list

// edge + vertex
// no leaks;
// error: CA-SW