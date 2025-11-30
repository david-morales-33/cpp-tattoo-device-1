#pragma once
#include <core/shared/interfaces/menu_controller.h>

template <typename D>
class IMenuControllerParams : public IMenuController
{
public:
    virtual void load(const D &data) {}
    virtual void render() = 0;
};