#include "../includes/core.hpp"

// type conversion;
// try catch for data types;
// check for overlap (big value)

int		main(void)
{
	Core core("./test_file/opensm-subnet.lst"); /* init of the core class */

	core.main_cycle(); /* start of the main routine */

	return (0);
}


// - left in string type in order to save place;
