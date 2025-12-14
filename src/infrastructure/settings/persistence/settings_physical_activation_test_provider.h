#pragma once
#include <core/shared/interfaces/data_provider.h>
#include <core/settings/interfaces/physical_device_activation.h>

class SettingsRemoteActivationTestProvider : public IDataProvider<PhysicalDeviceActivation, PhysicalDeviceActivation>
{
private:
    PhysicalDeviceActivation physical_activation = PhysicalDeviceActivation::PULSES;

public:
    void persist(const PhysicalDeviceActivation &data) override { physical_activation = data; }
    void load() override {}
    void reset() override { physical_activation = PhysicalDeviceActivation::PULSES; }
    void remove(const PhysicalDeviceActivation &data) override {}
    const PhysicalDeviceActivation &get() const override { return physical_activation; }
};