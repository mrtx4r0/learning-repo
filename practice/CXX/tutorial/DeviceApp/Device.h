#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include <iostream>

class Device {
public:
	Device(const std::string& name,
		   const std::string& serialNumber);
	virtual ~Device();
	
	virtual bool initialize() = 0;
	virtual void shutdown() = 0;
	//virtual std::string kind() const = 0;
	
	//std::string description() const;
	bool isPoweredOn() const;
	bool isConnected() const;
	
protected:
	std::string name_;
	std::string serialNumber_;
	bool isPoweredOn_;
	bool isConnected_;
};

#endif // DEVICE_H