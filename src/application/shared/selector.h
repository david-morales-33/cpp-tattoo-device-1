class Selector
{
private:
    int elements;
    int selector = 0;

public:
    explicit Selector(int elmt) : elements(elmt) {}
    void slideUp()
    {
        if (selector < elements)
            selector = selector + 1;
    }
    void slideDown()
    {
        if (selector > 0)
            selector = selector - 1;
    }
    int getSelector() { return selector; }
};