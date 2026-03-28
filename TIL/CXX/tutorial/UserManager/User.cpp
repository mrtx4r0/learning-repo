#include "User.h"
#include <iostream>

// number of Users
int User::userCount = 0;

User::User(const std::string& id,
	          const  std::string& name)
	:id_(id)
	, name_(name)
{
	userCount++;
	std::cout << "以下のユーザを追加しました id: " << id_ << "ユーザ名 :" << name_ << std::endl;
}

User::~User()
{
	userCount--;
	std::cout << "以下のユーザを削除しました id: " << id_ << "ユーザ名 :" << name_ << "\n ユーザ総数: "<< userCount << std::endl;
}

std::string User::getID() const 
{
	return id_;
}

std::string User::getName() const
{
	return name_;
}

static int User::getUserCount()
{
	return userCount;
}