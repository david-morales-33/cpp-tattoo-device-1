#pragma once
#include <infrastructure/display.h>
#include <core/performance/views/performance_view.h>
#include <core/performance/interfaces/performance_respository.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <core/shared/interfaces/menu_controller_void.h>

class PerformanceMenu : public IMenuControllerVoid
{
private:
    Display &display;
    IPerformanceRepository &repository;
    PerformanceView view;
    Selector selector;
    Performance performance;
    std::vector<PerformanceRecord> records_list;

    InterfaceState state = InterfaceState::VISIBLE;

public:
    explicit PerformanceMenu(Display &_display, IPerformanceRepository &_repository) : display(_display),
                                                                                       view(_display), repository(_repository) {}

    void render() override
    {
        display.firstPage();
        do
        {
            view.show(performance, records_list);
        } while (display.nextPage());
    }
    void load() override
    {
        performance = repository.find();
        records_list = repository.searchRecords();
    }
    void previous() override { selector.decrement(); }
    void next() override { selector.increment(); }
    void show() override { state = InterfaceState::VISIBLE; }
    void hide() override { state = InterfaceState::HIDDEN; }
    const InterfaceState getState() const override { return state; }
    const int getSelector() const override { return selector.getSelector(); }
};