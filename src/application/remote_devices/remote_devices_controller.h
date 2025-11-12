#pragma once
#include <infrastructure/input.h>
#include <infrastructure/display.h>
#include <application/remote_devices/remote_devices_menu.h>
#include <application/remote_devices/linked_devices_window_menu.h>
#include <application/remote_devices/available_devices_window_menu.h>

class RemoteDevicesController
{
private:
    Display &display;
    Input input;
    DevicesListData devices_list;
    LinkedDevicesData devices_linked;

    RemoteDevicesMenu remoteDevicesMenu;

    LinkedDevicesWindowMenu linkedDevicesWindow;
    AvailableDevicesWindowMenu availableDevicesWindow;

    bool state = LOW;

    void setLinkedDevices()
    {
        remoteDevicesMenu.setDevSelector(0);
        remoteDevicesMenu.setSelectorSize(devices_list.linked_devices.size());
        remoteDevicesMenu.left();
    }
    void setAvailableDevices()
    {
        remoteDevicesMenu.setDevSelector(0);
        remoteDevicesMenu.setSelectorSize(devices_list.available_devices.size());
        remoteDevicesMenu.right();
    }
    void setEnterLinkedDevices()
    {
        remoteDevicesMenu.hide();
        linkedDevicesWindow.show();
    }
    void setEnterAvailableDevices()
    {
        remoteDevicesMenu.hide();
        availableDevicesWindow.show();
    }
    void setBack()
    {
        remoteDevicesMenu.show();
        linkedDevicesWindow.hide();
        availableDevicesWindow.hide();
    }

public:
    explicit RemoteDevicesController(Display &disp, DevicesListData dev_list, LinkedDevicesData dev_link) : display(disp), devices_list(dev_list), devices_linked(dev_link), remoteDevicesMenu(disp, dev_list), linkedDevicesWindow(disp, dev_list), availableDevicesWindow(disp, dev_list, dev_link) {}

    void begin()
    {
        input.begin();
        remoteDevicesMenu.setSelectorSize(devices_list.linked_devices.size());
    }

    void execute()
    {
        if (remoteDevicesMenu.getState())
        {
            if (input.isPressed(UP))
                remoteDevicesMenu.up();
            if (input.isPressed(DOWN))
                remoteDevicesMenu.down();
            if (input.isPressed(RIGHT) && devices_list.available_devices.size() != 0)
                setAvailableDevices();
            if (input.isPressed(LEFT) && devices_list.linked_devices.size() != 0)
                setLinkedDevices();
            if (input.isPressed(ENTER))
                remoteDevicesMenu.getTypSelector() == 0 ? setEnterLinkedDevices() : setEnterAvailableDevices();
            
            remoteDevicesMenu.render();
        }

        if (linkedDevicesWindow.getState())
        {
            if (input.isPressed(BACK))
                setBack();
            linkedDevicesWindow.render();
        }

        if (availableDevicesWindow.getState())
        {
            if (input.isPressed(BACK))
                setBack();
            availableDevicesWindow.render();
        }
    }
    void show() { state = HIGH; }
    void hide() { state = LOW; }
};