#include <iostream>

void HelloWorld(int n); // 前方宣言することで、定義をmainより下に記述してもコンパイルエラーにならない

int main(int argc, char* argv[])
{
	HelloWorld(3);

	return 0;
}

void HelloWorld(int n)
{
	for (int i=0; i < n; i++) {
		std::cout << "[" << i << "]" << "Hello, World!" << std::endl;
	}
}
