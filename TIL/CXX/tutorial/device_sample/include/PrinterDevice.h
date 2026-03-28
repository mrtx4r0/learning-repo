#ifndef DEVICE_SAMPLE_PRINTERDEVICE_H
#define DEVICE_SAMPLE_PRINTERDEVICE_H

#include "Device.h"

class PrinterDevice : public Device {
public:
    PrinterDevice(const std::string& id,
                  const std::string& name,
                  const std::string& serialNumber,
                  int paperRemaining);

    bool initialize() override;
    void shutdown() override;
    std::string kind() const override;

    int paperRemaining() const;

private:
    int paperRemaining_;
};

#endif
