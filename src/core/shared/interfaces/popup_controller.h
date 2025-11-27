#pragma once

template <typename D>
class IPopupController
{
public:
    virtual void left() = 0;
    virtual void ritgh() = 0;
    virtual void up() = 0;
    virtual void down() = 0;
    virtual void render(const D &data) = 0;
    virtual const int getSelector() const = 0;
    virtual ~IPopupController() {}
};