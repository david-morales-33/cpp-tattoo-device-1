#pragma once

class Selector
{
private:
    int elements;
    int selector;

public:
    explicit Selector(int _elements = 0, int _selector = 0) : elements(_elements), selector(_selector) {}
    void decrement()
    {
        if (selector > 0)
            selector = selector - 1;
    }
    void increment()
    {
        if (selector < (elements - 1))
            selector = selector + 1;
    }
    const int &getSelector() const { return selector; }
    void setElements(int _elements) { elements = _elements; }
    void setSelector(int _selector)
    {
        if (_selector < (elements - 1))
            elements = _selector;
    }
};