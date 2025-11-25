#pragma once
#include <vector>

class Slider
{

private:
    std::vector<int> icons_slider = {-29, 3, 35, 67, 99, 131};
    int icons_selector = 0;
    int view_selector = 1;

public:
    void left()
    {
        if (icons_selector > 0)
            icons_selector = icons_selector - 1;
        else if (icons_selector == 0 && view_selector > 0)
        {
            view_selector = view_selector - 1;
            for (int i = 0; i < 6; i++)
                icons_slider[i] = icons_slider[i] + 32;
        }
    }
    void right()
    {
        if (icons_selector < 3)
            icons_selector = icons_selector + 1;
        else if (icons_selector == 3 && view_selector < 2)
        {
            view_selector = view_selector + 1;
            for (int i = 0; i < 6; i++)
                icons_slider[i] = icons_slider[i] - 32;
        }
    }

    const std::vector<int> &getIconsSlider() const { return icons_slider; }
    const int getIconsSelector() const { return icons_selector; }
    const int getViewSelector() const { return view_selector; }
};