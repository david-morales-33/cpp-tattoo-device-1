#pragma once
#include <core/shared/interfaces/popup_controller.h>
#include <infrastructure/display.h>
#include <core/presets/data_transfer_objects/selectors.h>
#include <core/presets/views/device_boot_modal.h>
#include <core/presets/interfaces/presets_repository.h>
#include <core/presets/data_transfer_objects/device_boot_presets.h>

class PresetsDeviceBootModal : public IPopupController<PresetsSelectors>
{
private:
    Display &display;
    IPresetsRepository &repository;
    DeviceBootModal view;
    InterfaceState state = InterfaceState::HIDDEN;
    PresetsSelectors selectors;
    BootSelector boot_selector;

public:
    explicit PresetsDeviceBootModal(
        Display &_display,
        IPresetsRepository &_repository) : display(_display),
                                           repository(_repository),
                                           view(_display) {}
    void render() override
    {
        display.firstPage();
        do
        {
            view.show(boot_selector, selectors.devices_selector, selectors.options_selector);
        } while (display.nextPage());
    }
    void enter() override
    {
        MachineType type = static_cast<MachineType>(selectors.devices_selector);
        DeviceBootPresets device_boot = DeviceBootPresets(type, boot_selector.getBoot());
        repository.updateDeviceBoot(device_boot);
    }

    void load(const PresetsSelectors &_selectors) override
    {
        selectors = _selectors;
        Presets *device_presets = repository.getPresets().getPresetsList()[_selectors.devices_selector];
        DeviceBoot device_boot = device_presets->getBoot();
        boot_selector.setSelector(device_boot);
    }
    void left() override { boot_selector.left(); }
    void right() override { boot_selector.right(); }
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    InterfaceState getState() const override { return state; }
    const int &getSelector() const override { return boot_selector.getSelector(); }
};