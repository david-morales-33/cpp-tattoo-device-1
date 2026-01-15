#pragma once
#include <core/presets/data_transfer_objects/presets.h>
#include <core/presets/data_transfer_objects/device_boot_presets.h>
#include <core/presets/data_transfer_objects/device_activation_presets.h>
#include <core/presets/data_transfer_objects/remote_device_machine.h>

class PresetsList
{
private:
    Presets presets_line_machine{MachineType::LINE};
    Presets presets_shade_machine{MachineType::SHADE};
    Presets *presets_list[2] = {&presets_line_machine, &presets_shade_machine};

public:
    PresetsList() {}
    PresetsList(Presets _presets_line_machine,
                Presets _presets_shade_machine) : presets_line_machine(_presets_line_machine), presets_shade_machine(_presets_shade_machine) {}

    const Presets &getPresetsLineMachine() const { return presets_line_machine; }
    const Presets &getPresetsShadeMachine() const { return presets_shade_machine; }
    Presets *const (&getPresetsList() const)[2] { return presets_list; }

    bool updateDeviceVoltage(DeviceVoltagePresets voltage)
    {
        return presets_list[getIndex(voltage.getType())]->getVoltageList().updateVoltage(voltage);
    }
    bool updateDeviceBoot(DeviceBootPresets device_boot)
    {
        return presets_list[getIndex(device_boot.getType())]->setBoot(device_boot.getBoot());
    }
    bool updateDeviceActivation(DeviceActivationPresets device_activation)
    {
        return presets_list[getIndex(device_activation.getType())]->setActivation(device_activation.getActivation());
    }
    bool connectRemoteDevice(RemoteDeviceMachine remote_device)
    {
        RemoteDevice new_remote_device{remote_device.getName(), remote_device.getMacAddressId()};
        return presets_list[getIndex(remote_device.getDeviceType())]->connectRemoteDevice(new_remote_device);
    }
    bool disconnectRemoteDevice(RemoteDeviceMachine remote_device)
    {
        return presets_list[getIndex(remote_device.getDeviceType())]->disconnectRemoteDevice();
    }

private:
    int getIndex(MachineType type) { return static_cast<int>(type); }
};