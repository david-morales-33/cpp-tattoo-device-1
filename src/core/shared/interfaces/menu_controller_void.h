#pragma once
#include <core/shared/interfaces/menu_controller.h>

class IMenuControllerVoid : public IMenuController
{
public:
    virtual void render() = 0;
    virtual void load() {}

};