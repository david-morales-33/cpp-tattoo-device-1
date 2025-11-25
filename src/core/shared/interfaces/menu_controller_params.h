#pragma once
#include <core/shared/interfaces/menu_controller.h>

template <typename D>
class IMenuControllerParams : public IMenuController
{
public:
    virtual void render(const D &data) = 0;
};