#pragma once
#include <infrastructure/input.h>
#include <infrastructure/display.h>
#include <application/configure_devices/configure_devices_menu.h>
#include <application/configure_devices/configure_values_menu.h>
#include <application/configure_devices/configure_values_window.h>

class ConfigureDevicesController
{
private:
    Display &display;
    Input input;
    ConfigureDevicesMenu devicesMenu;
    ConfigureValuesMenu valuesMenu;
    ConfigureValuesWindow valuesWindow;
    
    bool state = HIGH;

    void setEnterDevices(){
        devicesMenu.hide();
        valuesMenu.show();
    }
    void setEnterValues(){
        valuesWindow.setDevSelector(devicesMenu.getSelector());
        valuesWindow.setValSelector(valuesMenu.getSelector());
        valuesWindow.setValue();
        valuesMenu.hide();
        valuesWindow.show();
    }
    void setBackValues(){
        devicesMenu.show();
        valuesMenu.hide();
    }
    void setBackWindow(){
        valuesWindow.hide();
        valuesMenu.show();
    }

public:
    explicit ConfigureDevicesController(Display &disp, VoltageData volt) : 
    display(disp), devicesMenu(disp, volt), valuesMenu(disp, volt), valuesWindow(disp, volt) {}

    void begin() { input.begin(); }

    void execute()
    {
        if (devicesMenu.getState())
        {
            if (input.isPressed(UP)) devicesMenu.up();
            if (input.isPressed(DOWN)) devicesMenu.down();
            if (input.isPressed(ENTER)) setEnterDevices();
            devicesMenu.render();
        }
        if (valuesMenu.getState())
        {
            if (input.isPressed(UP)) valuesMenu.up();
            if (input.isPressed(DOWN)) valuesMenu.down();
            if (input.isPressed(ENTER)) setEnterValues();
            if (input.isPressed(BACK)) setBackValues();
            valuesMenu.render(devicesMenu.getSelector());
        }
        if(valuesWindow.getState())
        {
            if(input.isPressed(LEFT)) valuesWindow.left();
            if(input.isPressed(RIGHT)) valuesWindow.right();
            if(input.isPressed(UP)) valuesWindow.increment();
            if(input.isPressed(DOWN)) valuesWindow.decrement();
            if(input.isPressed(BACK)) setBackWindow();
            valuesWindow.render(valuesWindow.getSelector());
        }
    }
    void show() { state = HIGH; }
    void hide() { state = LOW; }
    bool getState() { return state; }
};