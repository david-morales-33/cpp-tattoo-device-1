#include <core/linked_devices/views/linked_devices_view.h>
#include <infrastructure/display.h>

class LinkedDevicesWindow : public LinkedDevicesView
{
private:
    Display &display;
    DevicesListData devices;

public:
    explicit LinkedDevicesWindow(Display &disp, DevicesListData dev) : LinkedDevicesView(disp, dev), display(disp), devices(dev) {}

    void show(int dev_selector = 0)
    {
        LinkedDevicesView::show(0, dev_selector);

        display.setFontMode(1);
        display.setColor(0);
        display.drawBox(7, 6, 114, 52);
        display.setColor(1);
        display.drawFrame(8, 7, 112, 50);
        display.setFont(u8g_font_6x10);
        display.drawText(24, 18, "REMOVE DEVICE?");
        display.setFont(u8g_font_5x8);
        display.drawText(38, 30, devices.linked_devices[dev_selector].name);
        display.drawFrame(12, 38, 50, 15, 3);
        display.drawFrame(66, 38, 50, 15, 3);
        display.drawBox(13, 39, 48, 13);
        display.drawBox(67, 39, 48, 13);

        display.setColor(0);
        display.setFont(u8g_font_6x10);
        display.drawText(16, 49, "<ENTER>");
        display.drawText(73, 49, "<BACK>");
        display.setColor(1);
    }
};