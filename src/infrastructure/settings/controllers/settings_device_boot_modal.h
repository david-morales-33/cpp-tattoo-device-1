#pragma once
#include <core/shared/interfaces/popup_controller.h>
#include <core/settings/interfaces/settings_device_boot_repository.h>
#include <core/settings/data_transfer_objects/settings_selectors.h>
#include <core/settings/views/device_boot_modal.h>
#include <core/settings/interfaces/device_boot.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <infrastructure/display.h>

class SettingsDeviceBootModal : public IPopupController<SettingsSelectors>
{
private:
    Display &display;
    ISettingsDeviceBootRepository &repository;
    DeviceBootModal view;
    InterfaceState state = InterfaceState::HIDDEN;
    SettingsSelectors selectors;
    Selector selector;
    DeviceBoot boot_list[4] = {
        DeviceBoot::CUSTOM_RAMP,
        DeviceBoot::INSTANT_POWER,
        DeviceBoot::LINEAR_RAMP,
        DeviceBoot::SOFT_START};

public:
    explicit SettingsDeviceBootModal(
        Display &_display,
        ISettingsDeviceBootRepository &_repository) : display(_display),
                                                      repository(_repository),
                                                      view(_display),
                                                      selector(4) {}
    void render() override
    {
        display.firstPage();
        do
        {
            view.show(selectors.side_selector, selectors.value_selector, boot_list[selector.getSelector()]);
        } while (display.nextPage());
    }
    void left() override { selector.getSelector() == 0 ? selector.setSelector(3) : selector.decrement(); }
    void right() override { selector.getSelector() == 3 ? selector.setSelector(0) : selector.increment(); }
    void enter() override { repository.update(boot_list[selector.getSelector()]); }
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    void load(const SettingsSelectors &_selectors) override
    {
        selectors = _selectors;
        resolveSelector(repository.get());
    }
    InterfaceState getState() const override { return state; }
    const int &getSelector() const override { return selector.getSelector(); }

private:
    void resolveSelector(DeviceBoot boot)
    {
        boot == DeviceBoot::CUSTOM_RAMP ? selector.setSelector(0) : boot == DeviceBoot::INSTANT_POWER ? selector.setSelector(1)
                                                                : boot == DeviceBoot::LINEAR_RAMP     ? selector.setSelector(2)
                                                                                                      : selector.setSelector(3);
    }
};