#pragma once

template <typename D>
class IListener
{
public:
    virtual void begin() = 0;
    virtual const D &listen() const = 0;
    virtual ~IListener() {};
};