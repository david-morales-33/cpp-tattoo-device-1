#pragma once
#include <core/shared/interfaces/popup_controller.h>
#include <infrastructure/display.h>
#include <core/presets/data_transfer_objects/activation_selector.h>
#include <core/presets/data_transfer_objects/selectors.h>
#include <core/presets/interfaces/presets_repository.h>
#include <core/presets/views/device_activation_modal.h>

class PresetsDeviceActivationModal : public IPopupController<PresetsSelectors>
{
private:
    Display &display;
    IPresetsRepository &repository;
    DeviceActivationModal view;
    InterfaceState state = InterfaceState::HIDDEN;
    PresetsSelectors selectors;
    ActivationSelector activation_selector;

public:
    explicit PresetsDeviceActivationModal(
        Display &_display,
        IPresetsRepository &_repository) : display(_display),
                                           repository(_repository),
                                           view(_display)
    {
    }
    void render() override
    {
        display.firstPage();
        do
        {
            view.show(activation_selector, selectors.devices_selector, selectors.options_selector);
        } while (display.nextPage());
    }
    void enter() override
    {
        MachineType type = static_cast<MachineType>(selectors.devices_selector);
        DeviceActivationPresets new_device_activation = DeviceActivationPresets(type, activation_selector.getActivation());
        repository.updateDeviceActivation(new_device_activation);
    }
    void load(const PresetsSelectors &_selectors) override
    {
        selectors = _selectors;
        Presets *device_presets = repository.getPresets().getPresetsList()[_selectors.devices_selector];
        DeviceActivation device_activation = device_presets->getActivation();
    }
    void left() override { activation_selector.left(); }
    void right() override { activation_selector.right(); }
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    InterfaceState getState() const override { return state; }
    const int &getSelector() const override { return activation_selector.getSelector(); }
};