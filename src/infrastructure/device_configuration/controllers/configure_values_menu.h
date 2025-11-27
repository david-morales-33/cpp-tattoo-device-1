#pragma once
#include <infrastructure/display.h>
#include <core/device_configuration/views/device_configuration_selector.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <core/shared/interfaces/menu_controller_params.h>
#include <core/shared/interfaces/interface_state.h>
#include <core/device_configuration/interfaces/device_configuration_repository.h>

class ConfigureValuesMenu : public IMenuControllerParams<int>
{
private:
    Display &display;
    IDeviceConfigurationRepository &repository;
    DeviceConfigurationSelector view;
    Selector val_selector;
    InterfaceState state = InterfaceState::HIDDEN;

public:
    explicit ConfigureValuesMenu(Display &_display, IDeviceConfigurationRepository &_repository) : display(_display), repository(_repository), view(_display), val_selector(4) {}
    void render(const int &dev_selector = 0) override
    {
        const VoltageGroup &devices = dev_selector == 0 ? repository.getLineDevices() : repository.getShadeDevices();
        display.firstPage();
        do
        {
            view.show(devices, val_selector.getSelector());
        } while (display.nextPage());
    }
    void previous() override { val_selector.decrement(); }
    void next() override { val_selector.increment(); }
    void show() override { state = InterfaceState::VISIBLE; }
    void hide() override { state = InterfaceState::HIDDEN; }
    const InterfaceState getState() const override { return state; }
    const int getSelector() const override { return val_selector.getSelector(); }
};