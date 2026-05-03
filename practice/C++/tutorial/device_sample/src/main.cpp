#include <iostream>
#include <vector>

#include "CameraDevice.h"
#include "PrinterDevice.h"

int main()
{
    CameraDevice camera("CAM-001", "Travel Camera", "SN-CAM-1001", 128);
    PrinterDevice printer("PRN-001", "Desk Printer", "SN-PRN-2001", 50);

    std::vector<Device*> devices;
    devices.push_back(&camera);
    devices.push_back(&printer);

    for (std::vector<Device*>::iterator it = devices.begin(); it != devices.end(); ++it) {
        Device* device = *it;
        const bool ready = device->initialize();

        std::cout << device->description()
                  << ", initialized=" << (ready ? "true" : "false")
                  << ", power=" << (device->isPoweredOn() ? "on" : "off")
                  << ", connected=" << (device->isConnected() ? "yes" : "no")
                  << std::endl;

        device->shutdown();
    }

    return 0;
}
