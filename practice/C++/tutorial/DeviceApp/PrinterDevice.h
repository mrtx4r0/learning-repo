#ifndef PRINTERDEVICE_H
#define PRINTERDEVICE_H

#include "device.h"

class PrinterDevice : public Device {
public:
	PrinterDevice(const std::string& name,
		               const std::string& serialNumber);
	bool initialize() override;
	void shutdown() override;
};

#endif // PRINTERDEVICE_H