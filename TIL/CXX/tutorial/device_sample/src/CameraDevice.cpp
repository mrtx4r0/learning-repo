#include "CameraDevice.h"

CameraDevice::CameraDevice(const std::string& id,
                           const std::string& name,
                           const std::string& serialNumber,
                           int remainingShots)
    : Device(id, name, serialNumber, "2.1.0")
    , remainingShots_(remainingShots)
{
}

bool CameraDevice::initialize()
{
    isPoweredOn_ = true;
    isConnected_ = true;
    mode_ = 1;
    return true;
}

void CameraDevice::shutdown()
{
    isPoweredOn_ = false;
    isConnected_ = false;
    mode_ = 0;
}

std::string CameraDevice::kind() const
{
    return "CameraDevice";
}

int CameraDevice::remainingShots() const
{
    return remainingShots_;
}
