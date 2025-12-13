#pragma once
#include <core/shared/interfaces/popup_controller.h>
#include <core/settings/interfaces/settings_device_activation_repository.h>
#include <core/settings/data_transfer_objects/settings_selectors.h>
#include <core/settings/views/device_remote_activation_modal.h>
#include <core/settings/data_transfer_objects/remote_activation_selector.h>
#include <infrastructure/display.h>

class SettingsRemoteDeviceActivationModal : public IPopupController<SettingsSelectors>
{
private:
    Display &display;
    ISettingsDeviceActivationRepository &repository;
    DevicesRemoteActivationModal view;
    InterfaceState state = InterfaceState::HIDDEN;
    SettingsSelectors selectors;
    RemoteActivationSelector activation_selector;

public:
    explicit SettingsRemoteDeviceActivationModal(
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
    void left() override { activation_selector.switchActivation(); }
    void right() override { activation_selector.switchActivation(); }
    void enter() override { repository.updateRemoteDeviceActivation(activation_selector.getActivation()); }
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    void load(const SettingsSelectors &_selectors) override
    {
        selectors = _selectors;
        activation_selector.setSelector(repository.getRemoteDeviceActivation());
    }
    InterfaceState getState() const override { return state; }
    const int &getSelector() const override { return activation_selector.getSelector(); }
};