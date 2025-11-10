#pragma once
#include <infrastructure/display.h>
#include <core/device_configuration/views/device_configuration_window.h>
#include <application/shared/selector.h>

class ConfigureValuesWindow
{
private:
    Display &display;
    VoltageData data;
    DeviceConfigurationWindow window;
    Selector selector;
    int dev_selector = 0;
    int val_selector = 0;
    int uni_selector = 0;
    float value = 0;
    bool state = LOW;

public:
    explicit ConfigureValuesWindow(Display &disp, VoltageData volt) : display(disp), window(disp, volt), data(volt), selector(2) {}
    void render(int selector = 0)
    {
        uni_selector = selector;
        display.firstPage();
        do
        {
            window.show(value, dev_selector, val_selector, selector);
        } while (display.nextPage());
    }
    void increment()
    {
        int uni = int(value);
        float dec = value - uni;
        if (uni_selector == 0)
        {
            if (value <= 11)
            {
                uni = uni + 1;
                value = uni + dec;
            }
        }
        else
        {
            if (value < 12)
            {
                dec = dec + 0.1;
                value = uni + dec;
            }
        }
    }
    void decrement()
    {
        int uni = int(value);
        float dec = value - uni;

        if (uni_selector == 0)
        {
            if (value > 2)
            {
                uni = uni - 1;
                value = uni + dec;
            }
        }
        else
        {
            if (value > 2)
            {
                dec = dec - 0.1;
                value = uni + dec;
            }
        }
    }
    void right() { selector.increment(); }
    void left() { selector.decrement(); }
    void hide() { state = LOW; }
    void show() { state = HIGH; }
    bool getState() { return state; }
    int getSelector() { return selector.getSelector(); }

    void setValue() { value = data.voltages[dev_selector][val_selector]; }
    void setDevSelector(int _dev_selector) { dev_selector = _dev_selector; }
    void setValSelector(int _val_selector) { val_selector = _val_selector; }
    void setUniSelector(int _uni_selector) { uni_selector = _uni_selector; }
};