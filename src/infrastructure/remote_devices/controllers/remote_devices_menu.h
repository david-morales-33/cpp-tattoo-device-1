#pragma once
#include <infrastructure/display.h>
#include <core/remote_devices/views/remote_devices_view.h>
#include <core/shared/interfaces/menu_controller_params.h>
#include <core/remote_devices/interfaces/remote_devices_repository.h>
#include <core/shared/interfaces/interface_state.h>
#include <core/shared/data_transfer_objects/selector.h>

class RemoteDevicesMenu : public IMenuControllerParams<int>
{
private:
    Display &display;
    IRemoteDevicesRepository &repository;
    RemoteDevicesView view;
    InterfaceState state = InterfaceState::VISIBLE;
    std::vector<Device> disconnected_devices;
    std::vector<Device> connected_devices;
    Selector selector;

    int devices_case = 0;

public:
    explicit RemoteDevicesMenu(
        Display &disp,
        IRemoteDevicesRepository &_repository) : display(disp),
                                                 view(disp),
                                                 repository(_repository) {}

    void load(const int &_type_selector) override
    {
        disconnected_devices = repository.findDisconnectedDevices();
        connected_devices = repository.findConnetedDevices();

        if (!disconnected_devices.empty() && !connected_devices.empty() && _type_selector == 0) //->
        {                                                                                       // Elements full - set on the conneted devices
            devices_case = 1;
            selector.setSelector(0);
            selector.setElements(connected_devices.size());
        }

        else if (!disconnected_devices.empty() && !connected_devices.empty() && _type_selector == 1) //->
        {                                                                                            // Elements full - set on the disconneted devices
            devices_case = 2;
            selector.setSelector(0);
            selector.setElements(disconnected_devices.size());
        }

        else if (!connected_devices.empty()) // ->
        {                                    // Only Connected Devices - set selector on the Connected devices
            devices_case = 3;
            selector.setElements(connected_devices.size());
            selector.setSelector(0);
        }
        else if (!disconnected_devices.empty())
        { // Only Disconnected Devices - set selector on the disconnected devices
            devices_case = 4;
            selector.setElements(disconnected_devices.size());
            selector.setSelector(0);
        }
        else
        { // Emtpy elements - No selector
            devices_case = 5;
        }
    }

    void render() override
    {
        display.firstPage();
        do
        {
            view.show(disconnected_devices, connected_devices, devices_case, selector.getSelector());
        } while (display.nextPage());
    }

    void previous() override { selector.decrement(); }

    void next() override { selector.increment(); }

    void show() override { state = InterfaceState::VISIBLE; }
    void hide() override { state = InterfaceState::HIDDEN; }

    const int getSelector() const override { return selector.getSelector(); }
    const InterfaceState getState() const override { return state; }
};