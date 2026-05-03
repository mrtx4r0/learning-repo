#include "Device.h"

// コンストラクタ
Device::Device(const std::string& name, 
			  const std::string& serialNumber)
	:name_(name)
	 ,serialNumber_(serialNumber)
{
	std::cout << "オブジェクト生成" << std::endl;
}

// デストラクタ
Device::~Device()
{
	std::cout << "オブジェクト破棄" << std::endl;
}

bool Device::isPoweredOn() const
{
	return isPoweredOn_;
}

bool Device::isConnected() const
{
	return isConnected_;
}

