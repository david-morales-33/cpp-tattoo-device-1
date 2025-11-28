#pragma once
#include <core/shared/interfaces/interface_state.h>

template <typename R, typename L>
class IPopupController
{
public:
    virtual void left() = 0;
    virtual void right() = 0;
    virtual void up() = 0;
    virtual void down() = 0;
    virtual void enter() = 0;
    virtual void hide() = 0;
    virtual void show() = 0;
    virtual void load(const L &data) = 0;
    virtual void render(const R &data) = 0;
    virtual InterfaceState getState() const = 0;
    virtual const int &getSelector() const = 0;
    virtual ~IPopupController() = default;
};