#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
	std::cout << "please type in something here: ";
	std::string buf;
	std::cin >> buf;
	std::cout << "you type in " << buf << std::endl;

	exit(0);
}
	
