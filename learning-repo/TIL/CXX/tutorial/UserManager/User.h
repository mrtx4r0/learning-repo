#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
	// constructor
	User(const std::string& id, const std::string& name);
	// destructor
	~User();
	
	// getter
	std::string getID() const;
	std::string getName() const;
	static int getUserCount();
	
private:
	std::string id_;
	std::string name_;
	static int userCount;
};
	
#endif  // USER_H
	
	