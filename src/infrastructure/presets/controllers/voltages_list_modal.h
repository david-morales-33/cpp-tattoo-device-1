#pragma once
#include <infrastructure/display.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <core/shared/interfaces/menu_controller_params.h>
#include <core/shared/interfaces/interface_state.h>
#include <core/presets/interfaces/presets_repository.h>
#include <core/presets/view/presets_voltages_modal.h>
#include <core/presets/data_transfer_objects/selectors.h>

class VoltagesListModal : public IMenuControllerParams<PresetsSelectors>
{
private:
    Display &display;
    IPresetsRepository &repository;
    PresetsVoltagesModal view;
    Selector selector;
    InterfaceState state = InterfaceState::HIDDEN;
    PresetsSelectors selectors;
    VoltageList voltages_list;

public:
    explicit VoltagesListModal(Display &_display, IPresetsRepository &_repository) : display(_display), repository(_repository), view(_display), selector(3) {}
    void render() override
    {
        display.firstPage();
        do
        {
            view.show(voltages_list, selectors.devices_selector, selectors.options_selector, selector.getSelector());
        } while (display.nextPage());
    }
    void load(const PresetsSelectors &_selectors) override
    {
        selectors = _selectors;
        selectors.devices_selector == 0 ? voltages_list = repository.getPresets().getPresetsLineMachine().getVoltageList() : voltages_list = repository.getPresets().getPresetsShadeMachine().getVoltageList();
    }
    void previous() override { selector.decrement(); }
    void next() override { selector.increment(); }
    void show() override { state = InterfaceState::VISIBLE; }
    void hide() override { state = InterfaceState::HIDDEN; }
    const InterfaceState getState() const override { return state; }
    const int getSelector() const override { return selector.getSelector(); }
};