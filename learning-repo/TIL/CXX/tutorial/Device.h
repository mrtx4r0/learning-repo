#ifndef DEVICE_SAMPLE_DEVICE_H
#define DEVICE_SAMPLE_DEVICE_H

#include <string>

class Device {
public:
    Device(const std::string& id,
           const std::string& name,
           const std::string& serialNumber,
           const std::string& firmwareVersion = "1.0.0");
    virtual ~Device() = default;

    virtual bool initialize() = 0;
    virtual void shutdown() = 0;
    virtual std::string kind() const = 0;

    std::string description() const;
    bool isPoweredOn() const;
    bool isConnected() const;

protected:
    std::string id_;
    std::string name_;
    std::string serialNumber_;
    bool isPoweredOn_;
    bool isConnected_;
    int batteryLevel_;
    int temperature_;
    int mode_;
    std::string firmwareVersion_;
};

#endif
