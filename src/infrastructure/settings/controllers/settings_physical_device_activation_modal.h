#pragma once
#include <core/shared/interfaces/popup_controller.h>
#include <core/main/data_transfer_objects/slider.h>
#include <core/main/interfaces/main_date_time_repository.h>
#include <core/settings/interfaces/settings_device_activation_repository.h>
#include <core/settings/data_transfer_objects/settings_selectors.h>
#include <core/settings/views/device_physical_activation_modal.h>
#include <core/settings/interfaces/physical_device_activation.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <infrastructure/display.h>

class SettingsPhysicalDeviceActivationModal : public IPopupController<SettingsSelectors>
{
private:
    Display &display;
    ISettingsDeviceActivationRepository &repository;
    DevicesPhysicalActivationModal view;
    InterfaceState state = InterfaceState::HIDDEN;
    SettingsSelectors selectors;
    Selector selector;
    PhysicalDeviceActivation activation_list[3] = {
        PhysicalDeviceActivation::NO_PEDAL,
        PhysicalDeviceActivation::PULSES,
        PhysicalDeviceActivation::CONTINUOUS};

public:
    explicit SettingsPhysicalDeviceActivationModal(
        Display &_display,
        ISettingsDeviceActivationRepository &_repository) : display(_display),
                                                            repository(_repository),
                                                            view(_display),
                                                            selector(2)
    {
    }
    void render() override
    {
        display.firstPage();
        do
        {
            view.show(selectors.side_selector, selectors.value_selector, activation_list[selector.getSelector()]);
        } while (display.nextPage());
    }
    void left() override { selector.getSelector() == 0 ? selector.setSelector(2) : selector.decrement(); }
    void right() override {selector.getSelector() == 2 ? selector.setSelector(0) : selector.increment(); }
    void enter() override { repository.updatePhysicalDeviceActivation(activation_list[selector.getSelector()]); }
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    void load(const SettingsSelectors &_selectors) override { selectors = _selectors; }
    InterfaceState getState() const override { return state; }
    const int &getSelector() const override { return selector.getSelector(); }

};