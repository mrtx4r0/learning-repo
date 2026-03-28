#ifndef DEVICE_SAMPLE_CAMERADEVICE_H
#define DEVICE_SAMPLE_CAMERADEVICE_H

#include "Device.h"

class CameraDevice : public Device {
public:
    CameraDevice(const std::string& id,
                 const std::string& name,
                 const std::string& serialNumber,
                 int remainingShots);

    bool initialize() override;
    void shutdown() override;
    std::string kind() const override;

    int remainingShots() const;

private:
    int remainingShots_;
};

#endif
