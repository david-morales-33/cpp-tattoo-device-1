#pragma once

class Counter
{
private:
    int counter = 0;
    int limit = 1;

public:
    Counter(int _limit, int _init = 0) : limit(_limit), counter(_init) {}

    void count()
    {
        if (counter < limit)
            counter++;
    }
    void reset() { counter = 0; }
    bool isFinished() { return counter == limit; }
};