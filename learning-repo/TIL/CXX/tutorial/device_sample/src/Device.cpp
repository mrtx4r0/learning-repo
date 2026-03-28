#include "Device.h"

Device::Device(const std::string& id,
               const std::string& name,
               const std::string& serialNumber,
               const std::string& firmwareVersion)
    : id_(id)
    , name_(name)
    , serialNumber_(serialNumber)
    , isPoweredOn_(false)
    , isConnected_(false)
    , batteryLevel_(100)
    , temperature_(25)
    , mode_(0)
    , firmwareVersion_(firmwareVersion)
{
}

std::string Device::description() const
{
    return kind() + "[id=" + id_ + ", name=" + name_ + ", serial=" + serialNumber_ + "]";
}

bool Device::isPoweredOn() const
{
    return isPoweredOn_;
}

bool Device::isConnected() const
{
    return isConnected_;
}
