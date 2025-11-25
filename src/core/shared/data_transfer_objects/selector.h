#pragma once

class Selector
{
private:
    int elements;
    int selector;

public:
    explicit Selector(int _elements, int _selector = 0) : elements(_elements), selector(_selector) {}
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
};