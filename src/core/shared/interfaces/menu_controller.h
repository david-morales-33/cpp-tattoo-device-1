#pragma once
#include <optional>
#include <core/main/data_transfer_objects/date_time_format.h>
#include <core/shared/interfaces/menu_state.h>

class IMenuController
{
public:
    virtual void next() = 0;
    virtual void previous() = 0;
    virtual void hide() = 0;
    virtual void show() = 0;
    virtual const MenuState getState() const = 0;
    virtual const int getSelector() const = 0;
    virtual ~IMenuController() {}
};