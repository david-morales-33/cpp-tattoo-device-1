#include <core/main/views/main_view.h>
#include <core/main/data_transfer_objects/slider.h>
#include <core/main/data_transfer_objects/modal_data.h>
#include <string>

class OperationMenuModal : public MainView
{
private:
    Display &display;

public:
    OperationMenuModal(Display &disp) : MainView(disp), display(disp) {}

    void show(const Slider &slider, const DateTimeFormat &date_time, int selector = 0)
    {
        MainView::show(slider, date_time);
        display.setFontMode(1);
        display.setColor(0);
        display.drawBox(25, 8, 76, 48);

        display.setColor(1);
        display.drawFrame(25, 8, 76, 48);

        display.setFont(u8g_font_5x7);
        display.drawText(32, 21, "START SESION");
        display.drawText(32, 35, "TEST");
        display.drawText(32, 49, "CANCEL");

        display.drawFrame(28, ((selector * 14) + 12), 70, 12, 2);
    }
};