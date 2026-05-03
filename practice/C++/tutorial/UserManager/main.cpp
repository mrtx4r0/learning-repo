#include "User.h"
#include <iostream>

int main(int argc, char *argv[])
{
	std::string id;
	std::string name;
	
	std::cout << "追加するユーザーIDを入力してください===> ";
	std::cin >> id;
	
	std::cout << "追加するユーザー名を入力してください===> ";
	std::cin >> name;
	
	User *user1 = NULL;
	user1 = new User(id, name);
	
	std::cout << "現在のユーザ総数: "<< User.getUserCount() << std::endl;
	
	delete user1;
	
	return 0;
}