#include "../includes/core.hpp"

// TODO: explain logic in lines;
// TODO: no such node;
// TODO: show error om line while lexer works; => Lexer && Parser Started;
// TODO: type conversion;
// TODO: validation: SW -> CA, SW, RT;


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

// - not unique NodeGUID
// - full confirmity with the line structure for every parameter
// - left in string type in order to save place;
// - unordered map -> 0(1) for insert, find, delete, do not adds the items which are already in the container;
// - use of std::string for data saving; char *
// - 924 => list
// 793
// edge + vertex
// no leaks;
// error: CA-SW