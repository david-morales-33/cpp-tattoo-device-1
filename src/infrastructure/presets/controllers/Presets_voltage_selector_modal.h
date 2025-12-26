#pragma once
#include <infrastructure/display.h>
#include <core/presets/views/voltage_selector_modal.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <core/shared/interfaces/popup_controller.h>
#include <core/presets/interfaces/presets_repository.h>
#include <core/presets/data_transfer_objects/selectors.h>
#include <core/presets/data_transfer_objects/voltage_selector.h>
#include <core/presets/data_transfer_objects/voltage_list.h>

class PresetsVoltageSelectorModal : public IPopupController<PresetsSelectors>
{
private:
    Display &display;
    IPresetsRepository &repository;
    VoltageSelectorModal view;

    VoltageSelector voltage_selector;
    PresetsSelectors selectors;
    InterfaceState state = InterfaceState::HIDDEN;

public:
    explicit PresetsVoltageSelectorModal(
        Display &_display,
        IPresetsRepository &_repository) : display(_display), repository(_repository), view(_display) {}

    void render() override
    {
        display.firstPage();
        do
        {
            view.show(voltage_selector.getValue(), selectors.devices_selector, selectors.options_selector, voltage_selector.getSelector());
        } while (display.nextPage());
    }

    // set =>
    void enter() override
    {
        MachineType type = static_cast<MachineType>(selectors.devices_selector);
        VoltageElement element = static_cast<VoltageElement>(selectors.voltage_selector);
        DeviceVoltagePresets new_voltage = DeviceVoltagePresets(type, element, voltage_selector.getValue());
        repository.updateVoltage(new_voltage);
    }

    void load(const PresetsSelectors &_selectors) override
    {
        selectors = _selectors;
        Presets *device_presets = repository.getPresets().getPresetsList()[_selectors.devices_selector];
        Voltage voltage = device_presets->getVoltageList().getData()[_selectors.voltage_selector];
        voltage_selector.setValue(voltage.getValue());
    }

    void up() override { voltage_selector.increment(); }
    void down() override { voltage_selector.decrement(); }
    void right() override { voltage_selector.setDecimal(); }
    void left() override { voltage_selector.setUnit(); }
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    InterfaceState getState() const override { return state; }
    const int &getSelector() const { return voltage_selector.getSelector(); }
};