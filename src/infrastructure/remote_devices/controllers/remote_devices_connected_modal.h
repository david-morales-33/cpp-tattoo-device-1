#pragma once
#include <core/shared/interfaces/popup_controller.h>
#include <core/remote_devices/data_transfer_objects/device.h>

class RemoteDevicesConnectedDeviceModal : public IPopupController<Device>
{
private:
    InterfaceState state = InterfaceState::HIDDEN;
    int selector = 0;

public:
    void left() override {}
    void right() override {}
    void up() override {}
    void down() override {}
    void enter() override {}
    void hide() override {}
    void show() override {}
    void load(const Device &data) override {}
    void render() override {}
    InterfaceState getState() const override { return state; }
    const int &getSelector() const override { return selector; }
};