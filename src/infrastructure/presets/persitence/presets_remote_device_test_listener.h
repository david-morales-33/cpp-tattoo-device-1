#pragma once
#include <core/shared/interfaces/listener.h>
#include <core/shared/data_transfer_objects/remote_device.h>
#include <vector>

class PresetsRemoteDeviceTestListener : public IListener<std::vector<RemoteDevice>>
{
private:
    std::vector<RemoteDevice> data = {
        RemoteDevice("Machine.86.AC", "AE:32:5C:EF:0A"),
        RemoteDevice("Machine.0F.AE", "AE:32:5C:EF:0A")};

public:
    void begin() override {}
    const std::vector<RemoteDevice> &listen() const override { return data; }
};