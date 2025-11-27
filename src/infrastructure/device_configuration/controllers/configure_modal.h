#pragma once
#include <infrastructure/display.h>
#include <core/device_configuration/views/device_configuration_modal.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <core/shared/interfaces/popup_controller.h>
#include <core/device_configuration/interfaces/device_configuration_repository.h>
#include <core/device_configuration/data_transfer_objects/selectors.h>

class ConfigureModal : public IPopupController<ConfigurationSelectors>
{
private:
    Display &display;
    IDeviceConfigurationRepository &repository;
    DeviceConfigurationModal modal;

    Selector unit_selector;
    ConfigurationSelectors selectors;
    VoltageGroup devices = VoltageGroup();
    Voltage voltage = Voltage();
    InterfaceState state = InterfaceState::HIDDEN;

public:
    explicit ConfigureModal(
        Display &_display,
        IDeviceConfigurationRepository &_repository) : display(_display), repository(_repository), modal(_display), unit_selector(2) {}

    void render(const ConfigurationSelectors &_selectors) override
    {
        selectors = _selectors;
        display.firstPage();
        do
        {
            modal.show(devices, voltage.getValue(), selectors.values_selector, unit_selector.getSelector());
        } while (display.nextPage());
    }

    // set =>
    void enter() override { repository.update(voltage); }
    void load() override
    {
        voltage.setType(devices.getAll()[selectors.values_selector].getType());
        voltage.setElement(devices.getAll()[selectors.values_selector].getElement());
        voltage.setValue(devices.getAll()[selectors.values_selector].getValue());
        devices = selectors.devices_selector == 0 ? repository.getLineDevices() : repository.getShadeDevices();
    }

    // increment =>
    void up() override
    {
        float value = voltage.getValue();

        int uni = int(value);
        float dec = value - uni;
        if (unit_selector.getSelector() == 0)
        {
            if (value <= 11)
            {
                uni = uni + 1;
                voltage.setValue((uni + dec));
            }
        }
        else
        {
            if (value < 12)
            {
                dec = dec + 0.1;
                voltage.setValue((uni + dec));
            }
        }
    }

    // Decrement =>
    void down() override
    {
        float value = voltage.getValue();
        int uni = int(value);
        float dec = value - uni;

        if (unit_selector.getSelector() == 0)
        {
            if (value > 2)
            {
                uni = uni - 1;
                voltage.setValue((uni + dec));
            }
        }
        else
        {
            if (value > 2)
            {
                dec = dec - 0.1;
                voltage.setValue((uni + dec));
            }
        }
    }

    void right() override { unit_selector.increment(); } // Select unid
    void left() override { unit_selector.decrement(); }  // Select unid
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    InterfaceState getState() const override { return state; }
    const int &getSelector() const { return unit_selector.getSelector(); }
};