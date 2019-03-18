#include <iostream>
#include <unordered_map>

using namespace std;

class test
{
	private:
	public:
		int param;
		test() {};
		test(int x) : param(x) {}
		~test() {};	
};

int	main(void)
{

	unordered_map<string, test> hash;

	hash.insert(std::make_pair("1", test(1)));
	// hash.insert(std::make_pair("2", test(2)));
	// hash.insert(std::make_pair("3", test(3)));

	std::for_each(hash.begin(), hash.end() , [](std::pair<std::string, test > element){
				std::cout<<element.first << " :: "<<element.second.param<<std::endl;
				});





	return (0);
}
