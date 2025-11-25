#pragma once

#include <core/main/data_transfer_objects/date_time_format.h>

class IMenuController
{
public:
    virtual void next() = 0;
    virtual void previous() = 0;
    virtual void render() = 0;
    virtual const int getSelector() const = 0;
    virtual ~IMenuController() {}
};