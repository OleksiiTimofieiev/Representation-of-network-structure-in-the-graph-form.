#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class test
{
	private:
	public:
		int param1;
		int param2;
		int param3;
		int param4;
		int param5;
		int param6;
		int param7;
		int param8;
		int param9;
		int param10;

		test() {};
		test(int x, int y) : param1(x), param2(y), param3(x), param4(y), param5(x), param6(y), param7(x), param8(y), param9(x), param10(y)  {}
		~test() {};	
};

int	main(void)
{

	unordered_map<string, test> hash;

	for (int i = 0; i < 10000; ++i)
	{
		hash.insert(std::make_pair(std::to_string(i), test(i, i)));
		/* code */
	}
	// hash.insert(std::make_pair("2", test(2)));
	// hash.insert(std::make_pair("3", test(3)));

	std::for_each(hash.begin(), hash.end() , [](std::pair<std::string, test> element){
				std::cout << element.first << " :: "<< element.second.param1 << std::endl;
				});





	return (0);
}
