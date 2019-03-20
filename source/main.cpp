#include "../includes/core.hpp"

// type conversion;
// try catch for data types;
// check for overlap (big value)

int		main(void)
{
	Core core("./test_file/opensm-subnet.lst"); /* init of the core class */

	core.main_cycle(); /* start of the main routine */

	#if defined(__unix__) || defined(__unix) || \
		(defined(__APPLE__) && defined(__MACH__))
			system("leaks -q infiniBand_network_graph"); /* leaks detection */
	#endif

	return (0);
}

// error management:
// - not unique NodeGUID
// - check if node exists;
// - full confirmity with the line structure for every parameter (error: CA-SW);
// - SW -> CA, SW, RT || or other stuff -> line 33;
// - left in string type in order to save place;
// - unordered map -> 0(1) for insert, find, delete, do not adds the items which are already in the container;
// - use of std::string for data saving; char *
// - 924 => list
// - memory: for unix type systems;

// - explain logic in lines;
// edge + vertex