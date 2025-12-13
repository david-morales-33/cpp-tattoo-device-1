#pragma once
#include <core/shared/data_transfer_objects/selector.h>
#include <core/settings/interfaces/reset_options.h>

class ResetSelector
{
private:
    ResetOptions activation_list[2] = {
        ResetOptions::ALL,
        ResetOptions::DEVICES};

    Selector selector = Selector(2);

public:
    ResetOptions getReset() const { return activation_list[selector.getSelector()]; }
    int getSelector() const { return selector.getSelector(); }

    void switchReset() { selector.getSelector() == 0 ? selector.setSelector(1) : selector.setSelector(0); }
    void setSelector(ResetOptions reset) { reset == ResetOptions::ALL ? selector.setSelector(0) : selector.setSelector(1); }
};