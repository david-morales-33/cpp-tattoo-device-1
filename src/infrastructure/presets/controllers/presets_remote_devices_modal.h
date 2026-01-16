#pragma once
#include <core/shared/interfaces/popup_controller.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <core/shared/data_transfer_objects/remote_device.h>
#include <core/presets/data_transfer_objects/selectors.h>
#include <infrastructure/display.h>
#include <core/presets/interfaces/presets_repository.h>
#include <core/presets/views/remote_devices_modal.h>
#include <vector>

class PresetsRemoteDevicesModal : public IPopupController<PresetsSelectors>
{
private:
    Display &display;
    IPresetsRepository &repository;
    RemoteDevicesModal view;
    InterfaceState state = InterfaceState::HIDDEN;
    PresetsSelectors selectors;
    Selector selector;
    std::vector<RemoteDevice> remote_devices_list;
    std::vector<RemoteDevice> remote_device_connected;

public:
    explicit PresetsRemoteDevicesModal(
        Display &_display,
        IPresetsRepository &_repository) : display(_display),
                                           repository(_repository),
                                           view(_display),
                                           selector() {}
    void render() override
    {
        display.firstPage();
        do
        {
            view.show(
                remote_devices_list,
                remote_device_connected,
                selectors.devices_selector,
                selectors.options_selector,
                selector.getSelector());

        } while (display.nextPage());
    }

    void enter() override
    {
        hide();
        if (remote_device_connected.empty() && !remote_devices_list.empty())
        {
            RemoteDeviceMachine remote_device{
                remote_devices_list[selector.getSelector()].getName(),
                remote_devices_list[selector.getSelector()].getMacAddressId(),
                static_cast<MachineType>(selectors.devices_selector)

            };
            repository.connect(remote_device);
        }
        else if (!remote_device_connected.empty())
        {
            RemoteDeviceMachine remote_device{
                remote_device_connected[0].getName(),
                remote_device_connected[0].getMacAddressId(),
                static_cast<MachineType>(selectors.devices_selector)

            };
            repository.disconnect(remote_device);
        }
    }

    void listener() override
    {
        remote_devices_list = repository.searchRemoteDevices();
        selector.setElements(remote_devices_list.size());
    }

    void load(const PresetsSelectors &_selectors) override
    {
        selectors = _selectors;
        remote_device_connected = repository.getPresets().getPresetsList()[_selectors.devices_selector]->getRemoteDevices();
    }

    void up() override { selector.decrement(); }
    void down() override { selector.increment(); }
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    InterfaceState getState() const override { return state; }
    const int &getSelector() const override { return selector.getSelector(); }
};