#pragma once
#include <optional>
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