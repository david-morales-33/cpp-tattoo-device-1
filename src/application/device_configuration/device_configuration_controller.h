#pragma once
#include <infrastructure/shared/interfaces/input.h>
#include <infrastructure/display.h>
#include <core/shared/interfaces/menu_controller_void.h>
#include <core/shared/interfaces/menu_controller_params.h>

class ConfigureDevicesController
{
private:
    IInput &input;
    IMenuControllerVoid &devices_menu;
    IMenuControllerParams<int> &values_menu;

    bool state = HIGH;

    void setEnterDevices()
    {
        devices_menu.hide();
        values_menu.show();
    }
    // void setEnterValues(){
    //     valuesWindow.setDevSelector(devicesMenu.getSelector());
    //     valuesWindow.setValSelector(valuesMenu.getSelector());
    //     valuesWindow.setValue();
    //     valuesMenu.hide();
    //     valuesWindow.show();
    // }
    void setBackValues()
    {
        devices_menu.show();
        values_menu.hide();
    }
    // void setBackWindow(){
    //     valuesWindow.hide();
    //     valuesMenu.show();
    // }

public:
    explicit ConfigureDevicesController(
        IInput &_input,
        IMenuControllerVoid &_devices_menu,
        IMenuControllerParams<int> &_values_menu) : input(_input), devices_menu(_devices_menu), values_menu(_values_menu) {}
    void execute()
    {
        if (devices_menu.getState() == InterfaceState::VISIBLE)
        {
            if (input.isPressed(UP))
                devices_menu.previous();
            if (input.isPressed(DOWN))
                devices_menu.next();
            if (input.isPressed(ENTER))
                setEnterDevices();
            devices_menu.render();
        }
        if (values_menu.getState() == InterfaceState::VISIBLE)
        {
            if (input.isPressed(UP))
                values_menu.previous();
            if (input.isPressed(DOWN))
                values_menu.next();
            // if (input.isPressed(ENTER)) setEnterValues();
            if (input.isPressed(BACK))
                setBackValues();
            values_menu.render(devices_menu.getSelector());
        }
        // if(valuesWindow.getState())
        // {
        //     if(input.isPressed(LEFT)) valuesWindow.left();
        //     if(input.isPressed(RIGHT)) valuesWindow.right();
        //     if(input.isPressed(UP)) valuesWindow.increment();
        //     if(input.isPressed(DOWN)) valuesWindow.decrement();
        //     if(input.isPressed(BACK)) setBackWindow();
        //     valuesWindow.render(valuesWindow.getSelector());
        // }
    }
    void show() { state = HIGH; }
    void hide() { state = LOW; }
    bool getState() { return state; }
};