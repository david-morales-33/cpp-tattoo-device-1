#pragma once

class Selector
{
private:
    int elements;
    int selector = 0;

public:
    explicit Selector(int elmt) : elements(elmt) {}
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
    int getSelector() { return selector; }
};