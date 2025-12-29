#pragma once
#include <core/shared/interfaces/popup_controller.h>
#include <infrastructure/display.h>
#include <core/presets/data_transfer_objects/selectors.h>
#include <core/performance/interfaces/performance_respository.h>
#include <core/shared/data_transfer_objects/selector.h>

class RecordsModalModal : public IPopupController<int>
{
private:
    Display &display;
    IPerformanceRepository &repository;
    InterfaceState state = InterfaceState::HIDDEN;
    Selector selector;

public:
    explicit RecordsModalModal(
        Display &_display,
        IPerformanceRepository &_repository) : display(_display),
                                               repository(_repository) {}
    void render() override {}
    void hide() override { state = InterfaceState::HIDDEN; }
    void show() override { state = InterfaceState::VISIBLE; }
    InterfaceState getState() const override { return state; }
    const int &getSelector() const override { return selector.getSelector(); }
};