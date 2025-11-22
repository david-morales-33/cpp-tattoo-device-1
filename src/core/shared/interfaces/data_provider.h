#pragma once

template <typename D, typename R>
class IDataProvider
{
public:
    virtual void persist(const D &data) = 0;
    virtual void load() = 0;
    virtual void reset() = 0;
    virtual void remove(const D &data) = 0;
    virtual const R &get() const = 0;
    virtual ~DataProvider() = default;
};