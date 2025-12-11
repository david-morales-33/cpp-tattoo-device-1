#pragma once
#include <core/shared/interfaces/popup_controller.h>
#include <core/main/data_transfer_objects/slider.h>
#include <core/main/interfaces/main_date_time_repository.h>
#include <core/settings/interfaces/settings_device_activation_repository.h>
#include <core/settings/data_transfer_objects/settings_selectors.h>
#include <core/settings/views/device_remote_activation_modal.h>
#include <core/settings/interfaces/remote_device_activation.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <infrastructure/display.h>

class SettingsRemoteDeviceActivationModal : public IPopupController<SettingsSelectors>
{
private:
    Display &display;
    ISettingsDeviceActivationRepository &repository;
    DevicesRemoteActivationModal view;
    InterfaceState state = InterfaceState::HIDDEN;
    SettingsSelectors selectors;
    Selector selector;
    RemoteDeviceActivation activation_list[2] = {RemoteDeviceActivation::NO_PEDAL, RemoteDeviceActivation::PULSES};

public:
    explicit SettingsRemoteDeviceActivationModal(
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
    void left() override { switchActivation(); }
    void right() override { switchActivation(); }
    void enter() override { repository.updateRemoteDeviceActivation(activation_list[selector.getSelector()]); }
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    void load(const SettingsSelectors &_selectors) override { selectors = _selectors; }
    InterfaceState getState() const override { return state; }
    const int &getSelector() const override { return selector.getSelector(); }

private:
    void switchActivation() { selector.getSelector() == 0 ? selector.setSelector(1) : selector.setSelector(0); }
};