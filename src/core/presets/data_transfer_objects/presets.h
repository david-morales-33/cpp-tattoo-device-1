#pragma once
#include <array>
#include <core/presets/data_transfer_objects/voltage.h>
#include <core/presets/data_transfer_objects/voltage_list.h>
#include <core/shared/interfaces/machine_type.h>
#include <core/presets/interfaces/device_boot.h>
#include <core/presets/interfaces/device_activation.h>
#include <core/shared/data_transfer_objects/remote_device.h>
#include <vector>

class Presets
{
private:
    MachineType type;
    DeviceBoot boot;
    DeviceActivation activation;
    VoltageList voltage_list;
    std::vector<RemoteDevice> remote_devices;

public:
    Presets(
        MachineType _type,
        DeviceBoot _boot,
        DeviceActivation _activation,
        VoltageList _voltage_list,
        std::vector<RemoteDevice> _remote_devices)
        : type(_type),
          boot(_boot),
          activation(_activation),
          voltage_list(_voltage_list),
          remote_devices(_remote_devices) {}

    Presets(MachineType _type)
        : type(_type), voltage_list() {}

    MachineType getType() const { return type; }
    DeviceBoot getBoot() const { return boot; }
    DeviceActivation getActivation() const { return activation; }
    const VoltageList &getVoltageList() const { return voltage_list; }
    VoltageList &getVoltageList() { return voltage_list; }
    const std::vector<RemoteDevice> &getRemoteDevices() const { return remote_devices; }
    std::vector<RemoteDevice> &getRemoteDevices() { return remote_devices; }

    bool setBoot(DeviceBoot _boot)
    {
        if (boot == _boot)
            return false;
        boot = _boot;
        return true;
    }
    bool setActivation(DeviceActivation _activation)
    {
        if (activation == _activation)
            return false;
        activation = _activation;
        return true;
    }
    bool connectRemoteDevice(RemoteDevice remote_device)
    {
        if (!remote_devices.empty())
            return false;
        remote_devices.push_back(remote_device);
        return true;
    }
    bool disconnectRemoteDevice()
    {
        if (remote_devices.empty())
            return false;
        remote_devices.clear();
        return true;
    }
};
