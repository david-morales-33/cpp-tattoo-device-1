#pragma once
#include <core/shared/interfaces/popup_controller.h>
#include <core/settings/interfaces/settings_device_boot_repository.h>
#include <core/settings/data_transfer_objects/settings_selectors.h>
#include <core/settings/views/device_boot_modal.h>
#include <infrastructure/display.h>
#include <core/settings/data_transfer_objects/boot_selector.h>

class SettingsDeviceBootModal : public IPopupController<SettingsSelectors>
{
private:
    Display &display;
    ISettingsDeviceBootRepository &repository;
    DeviceBootModal view;
    InterfaceState state = InterfaceState::HIDDEN;
    SettingsSelectors selectors;
    BootSelector boot_selector;

public:
    explicit SettingsDeviceBootModal(
        Display &_display,
        ISettingsDeviceBootRepository &_repository) : display(_display),
                                                      repository(_repository),
                                                      view(_display) {}
    void render() override
    {
        display.firstPage();
        do
        {
            view.show(selectors.side_selector, selectors.value_selector, boot_selector);
        } while (display.nextPage());
    }
    void left() override { boot_selector.left(); }
    void right() override { boot_selector.right(); }
    void enter() override { repository.update(boot_selector.getBoot()); }
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    void load(const SettingsSelectors &_selectors) override
    {
        selectors = _selectors;
        boot_selector.setSelector(repository.get());
    }
    InterfaceState getState() const override { return state; }
    const int &getSelector() const override { return boot_selector.getSelector(); }
};