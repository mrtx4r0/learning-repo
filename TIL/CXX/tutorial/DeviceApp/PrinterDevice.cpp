#include "PrinterDevice.h"

PrinterDevice::PrinterDevice(const std::string& name,
                             		       const std::string& serialNumber)
    : Device(name, serialNumber)
{
}

bool PrinterDevice::initialize()
{
	isPoweredOn_ = true;
	isConnected_ = true;
	std::cout << "PrinterDevice is initialized!" << std::endl;
	return true;
}

void PrinterDevice::shutdown()
{
	isPoweredOn_ = false;
	isConnected_ = false;
	std::cout << "PrinterDevice shutdown.." << std::endl;
}
