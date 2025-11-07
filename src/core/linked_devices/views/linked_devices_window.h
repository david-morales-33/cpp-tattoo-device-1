#include <core/linked_devices/views/linked_devices_view.h>
#include <infrastructure/display.h>

class LinkedDevicesWindow : public LinkedDevicesView
{
private:
    Display &display;
    const char *title;

public:
    explicit LinkedDevicesWindow(Display &disp, const char *ttl) : LinkedDevicesView(disp), display(disp), title(ttl) {}

    void show(const char *device)
    {
        LinkedDevicesView::show();

        display.setFontMode(1);
        display.setColor(0);
        display.drawBox(7, 6, 114, 52);
        display.setColor(1);
        display.drawFrame(8, 7, 112, 50);
        display.setFont(u8g_font_6x10);
        display.drawText(24, 18, title);
        display.setFont(u8g_font_5x8);
        display.drawText(38, 30, device);
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