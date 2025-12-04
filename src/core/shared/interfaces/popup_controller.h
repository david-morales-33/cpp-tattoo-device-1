#pragma once
#include <core/shared/interfaces/interface_state.h>

template <typename D>
class IPopupController
{
public:
    virtual void left() {}
    virtual void right() {}
    virtual void up() {}
    virtual void down() {}
    virtual void enter() = 0;
    virtual void hide() = 0;
    virtual void show() = 0;
    virtual void load(const D &data) {};
    virtual void render() = 0;
    virtual InterfaceState getState() const = 0;
    virtual const int &getSelector() const = 0;
    virtual ~IPopupController() = default;
};