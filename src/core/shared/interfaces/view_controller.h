#pragma once
#include <optional>
#include <core/main/data_transfer_objects/date_time_format.h>
#include <core/shared/interfaces/interface_state.h>

class IViewController
{
public:
    virtual void render() = 0;
    virtual void hide() = 0;
    virtual void show() = 0;
    virtual const InterfaceState getState() const = 0;
    virtual ~IViewController() {}
};