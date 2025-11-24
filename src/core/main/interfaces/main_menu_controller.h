#pragma once

#include <core/main/data_transfer_objects/date_time_format.h>

class IMainMenuController
{
public:
    virtual void left() = 0;
    virtual void right() = 0;
    virtual void render(DateTimeFormat data) = 0;
    virtual const int getSelector() const = 0;
    virtual ~IMainMenuController() {}
};