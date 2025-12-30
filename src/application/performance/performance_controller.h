#pragma once
#include <infrastructure/shared/interfaces/input.h>
#include <infrastructure/display.h>
#include <core/shared/interfaces/popup_controller.h>
#include <core/shared/interfaces/menu_controller_void.h>
#include <application/shared/controller.h>

class PerformanceController : public IController
{
private:
    IInput &input;
    IMenuControllerVoid &view;
    IPopupController<int> &records_modal;
    InterfaceState state = InterfaceState::HIDDEN;

public:
    explicit PerformanceController(IInput &_input, IMenuControllerVoid &_view, IPopupController<int> &_records_modal) : input(_input), view(_view), records_modal(_records_modal) {}

    void execute() override
    {
        if (view.getState() == InterfaceState::VISIBLE)
        {
            view.render();
            if (input.isPressed(BACK))
                hide();
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
    void show() override { state = InterfaceState::VISIBLE; }
    void hide() override { state = InterfaceState::HIDDEN; }
    InterfaceState getState() const override { return state; }

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