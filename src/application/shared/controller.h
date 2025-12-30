#pragma once
#include <core/shared/interfaces/interface_state.h>

class IController
{
public:
    virtual void execute() = 0;
    virtual void hide() = 0;
    virtual void show() = 0;
    virtual InterfaceState getState() const = 0;
    virtual ~IController() {}
};