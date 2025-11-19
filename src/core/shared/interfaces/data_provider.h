#include <core/shared/interfaces/data.h>
#include <core/shared/interfaces/response.h>

template <typename D, typename R>
class DataProvider
{
public:
    virtual void persist(const D &data) = 0;
    virtual void load() = 0;
    virtual void reset() = 0;
    virtual const R &get() const = 0;
    virtual ~DataProvider() = default;
};