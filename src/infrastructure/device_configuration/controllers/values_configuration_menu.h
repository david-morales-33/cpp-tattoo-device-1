#pragma once
#include <infrastructure/display.h>
#include <core/device_configuration/views/device_configuration_selector.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <core/shared/interfaces/menu_controller_params.h>
#include <core/shared/interfaces/interface_state.h>
#include <core/device_configuration/interfaces/device_configuration_repository.h>

class ValuesConfigurationMenu : public IMenuControllerParams<int>
{
private:
    Display &display;
    IDeviceConfigurationRepository &repository;
    DeviceConfigurationSelector view;
    Selector val_selector;
    VoltageGroup voltages{};
    InterfaceState state = InterfaceState::HIDDEN;

public:
    explicit ValuesConfigurationMenu(Display &_display, IDeviceConfigurationRepository &_repository) : display(_display), repository(_repository), view(_display), val_selector(4) {}
    void render() override
    {
        display.firstPage();
        do
        {
            view.show(voltages, val_selector.getSelector());
        } while (display.nextPage());
    }
    void load(const int &dev_selector = 0) override
    {
        voltages = dev_selector == 0 ? repository.getLineDevices() : repository.getShadeDevices();
    }
    void previous() override { val_selector.decrement(); }
    void next() override { val_selector.increment(); }
    void show() override { state = InterfaceState::VISIBLE; }
    void hide() override { state = InterfaceState::HIDDEN; }
    const InterfaceState getState() const override { return state; }
    const int getSelector() const override { return val_selector.getSelector(); }
};