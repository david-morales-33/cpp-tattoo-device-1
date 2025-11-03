#include <core/main/views/main_view.h>
#include <persistence/main/data.h>
#include <core/shared/utils/_timer_.h>

class LetterView : public MainView
{
private:
    Display display;

    void setLetter(int posx, String text)
    {
        display.setFontMode(1);
        display.setColor(1);
        display.setFont(u8g2_font_courB08_tf);
        display.drawBox(28, 24, 74, 20);
        display.setColor(0);
        display.drawFrame(27, 23, 76, 22);

        display.setColor(1);
        display.setFontMode(1);
        display.setColor(0);
        display.setCursor(posx, 37);
        display.print(text);
    }

public:
    LetterView(Display &disp) : MainView(disp), display(disp) {}

    void show(int slider[], LetterData data)
    {
        MainView::show(slider);

        setLetter(data.position, data.text);
    }
};