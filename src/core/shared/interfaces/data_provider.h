#pragma once

template <typename D, typename R>
class IDataProvider
{
public:
    virtual void persist(const D &data) = 0;
    virtual void load() {}
    virtual void reset() {}
    virtual void remove(const D &data) {}
    virtual const R &get() const = 0;
    virtual ~IDataProvider() {};
};