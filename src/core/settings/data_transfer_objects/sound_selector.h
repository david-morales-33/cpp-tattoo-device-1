#pragma once
#include <core/shared/data_transfer_objects/selector.h>
#include <core/settings/interfaces/sound_state.h>

class SoundSelector
{
private:
    SoundState activation_list[2] = {SoundState::OFF, SoundState::ON};

    Selector selector = Selector(2);

public:
    SoundState getSound() const { return activation_list[selector.getSelector()]; }
    int getSelector() const { return selector.getSelector(); }

    void switchSound() { selector.getSelector() == 0 ? selector.setSelector(1) : selector.setSelector(0); }
    void setSelector(SoundState sound) { sound == SoundState::OFF ? selector.setSelector(0) : selector.setSelector(1); }
};