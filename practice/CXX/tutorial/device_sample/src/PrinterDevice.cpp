#include "PrinterDevice.h"

PrinterDevice::PrinterDevice(const std::string& id,
                             const std::string& name,
                             const std::string& serialNumber,
                             int paperRemaining)
    : Device(id, name, serialNumber, "3.0.2")
    , paperRemaining_(paperRemaining)
{
}

bool PrinterDevice::initialize()
{
    isPoweredOn_ = true;
    isConnected_ = true;
    mode_ = 2;
    return paperRemaining_ > 0;
}

void PrinterDevice::shutdown()
{
    isPoweredOn_ = false;
    isConnected_ = false;
    mode_ = 0;
}

std::string PrinterDevice::kind() const
{
    return "PrinterDevice";
}

int PrinterDevice::paperRemaining() const
{
    return paperRemaining_;
}
