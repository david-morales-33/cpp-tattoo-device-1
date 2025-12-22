#pragma once
#include <core/presets/data_transfer_objects/presets.h>

class PresetsList
{
private:
    Presets presets_line_machine{MachineType::LINE};
    Presets presets_shade_machine{MachineType::SHADE};

public:
    Presets &getPresetsLineMachine() { return presets_line_machine; }
    Presets &getPresetsShadeMachine() { return presets_shade_machine; }
};