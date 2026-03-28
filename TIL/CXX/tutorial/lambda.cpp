#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[])
{
	auto func = [](int a, int b) -> int { return a + b; };
	
	int result = func(4,6);
	std::cout << result << std::endl;

	exit(0);
}
