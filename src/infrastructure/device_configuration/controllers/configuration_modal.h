#pragma once
#include <infrastructure/display.h>
#include <core/device_configuration/views/device_configuration_modal.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <core/shared/interfaces/popup_controller.h>
#include <core/device_configuration/interfaces/device_configuration_repository.h>
#include <core/device_configuration/data_transfer_objects/selectors.h>
#include <core/device_configuration/data_transfer_objects/voltage_selector.h>

class ConfigurationModal : public IPopupController<ConfigurationSelectors>
{
private:
    Display &display;
    IDeviceConfigurationRepository &repository;
    DeviceConfigurationModal modal;

    VoltageSelector voltage_selector;
    ConfigurationSelectors selectors;
    VoltageGroup devices{};
    Voltage voltage{};
    InterfaceState state = InterfaceState::HIDDEN;

public:
    explicit ConfigurationModal(
        Display &_display,
        IDeviceConfigurationRepository &_repository) : display(_display), repository(_repository), modal(_display) {}

    void render() override
    {
        display.firstPage();
        do
        {
            modal.show(devices, voltage.getValue(), selectors.values_selector, voltage_selector.getSelector());
        } while (display.nextPage());
    }

    // set =>
    void enter() override { repository.update(voltage); }
    void load(const ConfigurationSelectors &_selectors) override
    {
        selectors = _selectors;
        devices = selectors.devices_selector == 0 ? repository.getLineDevices() : repository.getShadeDevices();
        voltage = devices.getAll()[selectors.values_selector];
    }

    // increment =>
    void up() override
    {
        voltage_selector.setValue(voltage.getValue());
        voltage_selector.increment();
        voltage.setValue(voltage_selector.getValue());
    }

    // Decrement =>
    void down() override
    {
        voltage_selector.setValue(voltage.getValue());
        voltage_selector.decrement();
        voltage.setValue(voltage_selector.getValue());
    }

    void right() override { voltage_selector.setDecimal(); }
    void left() override { voltage_selector.setUnit(); }
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    InterfaceState getState() const override { return state; }
    const int &getSelector() const { return voltage_selector.getSelector(); }
};