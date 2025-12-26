#pragma once
#include <infrastructure/display.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <core/shared/interfaces/menu_controller_params.h>
#include <core/shared/interfaces/interface_state.h>
#include <core/presets/interfaces/presets_repository.h>
#include <core/presets/views/voltages_list_modal.h>
#include <core/presets/data_transfer_objects/selectors.h>

class PresetsVoltagesListModal : public IPopupController<PresetsSelectors>
{
private:
    Display &display;
    IPresetsRepository &repository;
    VoltagesListModal view;
    Selector selector;
    InterfaceState state = InterfaceState::HIDDEN;
    PresetsSelectors selectors;
    VoltageList voltages_list;

public:
    explicit PresetsVoltagesListModal(Display &_display, IPresetsRepository &_repository) : display(_display), repository(_repository), view(_display), selector(4) {}
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
        Presets *device_presets = repository.getPresets().getPresetsList()[_selectors.devices_selector];
        voltages_list = device_presets->getVoltageList();
    }
    void up() override { selector.decrement(); }
    void down() override { selector.increment(); }
    void show() override { state = InterfaceState::VISIBLE; }
    void hide() override { state = InterfaceState::HIDDEN; }
    InterfaceState getState() const override { return state; }
    const int &getSelector() const override { return selector.getSelector(); }
};