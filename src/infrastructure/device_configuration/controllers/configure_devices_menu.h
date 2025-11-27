#pragma once
#include <infrastructure/display.h>
#include <core/device_configuration/views/device_configuration_view.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <core/shared/interfaces/menu_controller_void.h>
#include <core/device_configuration/interfaces/device_configuration_repository.h>

class ConfigureDevicesMenu : public IMenuControllerVoid
{
private:
    Display &display;
    IDeviceConfigurationRepository &repository;
    DeviceConfigurationView view;
    Selector selector;
    InterfaceState state = InterfaceState::VISIBLE;

public:
    explicit ConfigureDevicesMenu(Display &disp, IDeviceConfigurationRepository &_repository) : display(disp), repository(_repository), view(disp), selector(2) {}

    void render() override
    {
        display.firstPage();
        do
        {
            view.show(selector.getSelector() == 0 ? repository.getLineDevices() : repository.getShadeDevices());
        } while (display.nextPage());
    }
    void previous() override { selector.decrement(); }
    void next() override { selector.increment(); }
    void show() override { state = InterfaceState::VISIBLE; }
    void hide() override { state = InterfaceState::HIDDEN; }
    const InterfaceState  getState() const override { return state; }
    const int getSelector() const override { return selector.getSelector(); }
};