#pragma once
#include <core/shared/interfaces/popup_controller.h>
#include <core/main/data_transfer_objects/slider.h>
#include <core/main/interfaces/main_date_time_repository.h>
#include <core/settings/interfaces/settings_device_activation_repository.h>
#include <core/settings/data_transfer_objects/settings_selectors.h>
#include <core/settings/views/device_physical_activation_modal.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <infrastructure/display.h>
#include <core/settings/data_transfer_objects/physical_acttivation_selector.h>

class SettingsPhysicalDeviceActivationModal : public IPopupController<SettingsSelectors>
{
private:
    Display &display;
    ISettingsDeviceActivationRepository &repository;
    DevicesPhysicalActivationModal view;
    InterfaceState state = InterfaceState::HIDDEN;
    SettingsSelectors selectors;
    PhysicalActivationSelector activation_selector;

public:
    explicit SettingsPhysicalDeviceActivationModal(
        Display &_display,
        ISettingsDeviceActivationRepository &_repository) : display(_display),
                                                            repository(_repository),
                                                            view(_display)
    {
    }
    void render() override
    {
        display.firstPage();
        do
        {
            view.show(selectors.side_selector, selectors.value_selector, activation_selector);
        } while (display.nextPage());
    }
    void left() override { activation_selector.left(); }
    void right() override { activation_selector.right(); }
    void enter() override { repository.updatePhysicalDeviceActivation(activation_selector.getBoot()); }
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    void load(const SettingsSelectors &_selectors) override { selectors = _selectors; }
    InterfaceState getState() const override { return state; }
    const int &getSelector() const override { return activation_selector.getSelector(); }
};