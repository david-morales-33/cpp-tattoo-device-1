#pragma once
#include <vector>
#include <core/shared/interfaces/data_provider.h>
#include <core/remote_devices/data_transfer_objects/device.h>
#include <core/remote_devices/data_transfer_objects/device_list.h>
#include <infrastructure/persistence/shared/EEPROM_manager.h>

class RemoteDevicesEepromProvider : public IDataProvider<Device, std::vector<Device>>
{
private:
    DeviceList element_list;
    EEPROMManager &eeprom_manager;
    int memory_address_device[3] = {100, 120, 130};

public:
    explicit RemoteDevicesEepromProvider(EEPROMManager &memory) : eeprom_manager(memory) {}

    void begin() { load(); }
    void persist(const Device &device) override
    {
        if (element_list.connectDevice(device))
        {
            int addr = memory_address_device[device.getDeviceType()];
            eeprom_manager.writeByte(addr, 0xAA);
            eeprom_manager.writeObject(addr + 1, device);
        }
    }
    void reset() override
    {
        for (int addr : memory_address_device)
            eeprom_manager.writeByte(addr, 0x00);
    }
    void load() override
    {
        for (int i = 0; i < 3; i++)
        {
            int addr = memory_address_device[i];
            if (eeprom_manager.readByte(addr) == 0xAA)
            {
                Device device = eeprom_manager.readObject<Device>(addr + 1);
                element_list.getDevice(device.getDeviceType()).setName(device.getName());
                element_list.getDevice(device.getDeviceType()).setMacAddressId(device.getMacAddressId());
                element_list.getDevice(device.getDeviceType()).setDeviceState(CONNECTED);
            }
        }
    }
    void remove(const Device &device) override
    {
        if (element_list.disconnectDevice(device.getDeviceType()))
        {
            int addr = memory_address_device[device.getDeviceType()];
            eeprom_manager.writeByte(addr, 0x00);
        }
    }
    const std::vector<Device> &get() const override { return element_list.getConnectedDevices(); }
};