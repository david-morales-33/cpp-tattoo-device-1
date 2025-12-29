#pragma once
#include <infrastructure/shared/interfaces/input.h>
#include <infrastructure/display.h>
#include <core/shared/interfaces/popup_controller.h>
#include <core/shared/interfaces/menu_controller_void.h>

class PerformanceController
{
private:
    IInput &input;
    IMenuControllerVoid &view;
    IPopupController<int> &records_modal;
    InterfaceState state = InterfaceState::HIDDEN;

public:
    explicit PerformanceController(IInput &_input, IMenuControllerVoid &_view, IPopupController<int> &_records_modal) : input(_input), view(_view), records_modal(_records_modal) {}

    void execute()
    {
        if (view.getState() == InterfaceState::VISIBLE)
        {
            view.render();
            if (input.isPressed(ENTER))
                enterToModal();
        }
        else if (records_modal.getState() == InterfaceState::VISIBLE)
        {
            records_modal.render();
            if (input.isPressed(BACK))
                backToView();
        }
    }
    void show() { state = InterfaceState::VISIBLE; }
    void hide() { state = InterfaceState::HIDDEN; }
    InterfaceState getState() { return state; }

private:
    void enterToModal()
    {
        view.hide();
        records_modal.show();
    }
    void backToView()
    {
        view.show();
        records_modal.hide();
    }
};