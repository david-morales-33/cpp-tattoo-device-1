#pragma once

#include <core/shared/interfaces/popup_controller.h>
#include <core/remote_devices/data_transfer_objects/device.h>
#include <infrastructure/display.h>
#include <core/remote_devices/interfaces/remote_devices_repository.h>

class RemoteDevicesDisconnectedDevicesModal : public IPopupController<Device>
{
private:
    Display &display;
    IRemoteDevicesRepository &repository;
    InterfaceState state = InterfaceState::HIDDEN;
    int selector = 0;

public:
    explicit RemoteDevicesDisconnectedDevicesModal(
        Display &_display,
        IRemoteDevicesRepository &_repository) : display(_display), repository(_repository) {}
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
