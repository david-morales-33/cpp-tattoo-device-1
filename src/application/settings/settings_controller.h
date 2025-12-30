#pragma once
#include <core/shared/interfaces/menu_controller_params.h>
#include <infrastructure/shared/interfaces/input.h>
#include <infrastructure/shared/pins.h>
#include <core/shared/interfaces/interface_state.h>
#include <core/shared/interfaces/popup_controller.h>
#include <core/settings/interfaces/sound_state.h>
#include <core/main/data_transfer_objects/slider.h>
#include <core/shared/data_transfer_objects/selector.h>
#include <core/settings/data_transfer_objects/settings_selectors.h>
#include <application/shared/controller.h>

class SettingsController : public IController
{
private:
    IInput &input;
    IMenuControllerParams<int> &menu;

    IPopupController<SettingsSelectors> &sound_modal;
    IPopupController<SettingsSelectors> &clock_modal;
    IPopupController<SettingsSelectors> &date_modal;
    IPopupController<SettingsSelectors> &reset_modal;

    IPopupController<SettingsSelectors> &pedal_dev_f_modal;
    IPopupController<SettingsSelectors> &pedal_dev_r_modal;

    Selector selector;
    InterfaceState state = InterfaceState::HIDDEN;
    SettingsSelectors selectors_list;

public:
    explicit SettingsController(
        IInput &_input,
        IMenuControllerParams<int> &_menu,
        IPopupController<SettingsSelectors> &_sound_modal,
        IPopupController<SettingsSelectors> &_clock_modal,
        IPopupController<SettingsSelectors> &_date_modal,
        IPopupController<SettingsSelectors> &_reset_modal,
        IPopupController<SettingsSelectors> &_pedal_dev_f_modal,
        IPopupController<SettingsSelectors> &_pedal_dev_r_modal) : input(_input),
                                                                   menu(_menu),
                                                                   sound_modal(_sound_modal),
                                                                   clock_modal(_clock_modal),
                                                                   date_modal(_date_modal),
                                                                   reset_modal(_reset_modal),
                                                                   pedal_dev_f_modal(_pedal_dev_f_modal),
                                                                   pedal_dev_r_modal(_pedal_dev_r_modal),
                                                                   selector(2) {}

    void execute() override
    {
        if (menu.getState() == InterfaceState::VISIBLE)
        {
            selectors_list.side_selector = selector.getSelector();
            selectors_list.value_selector = menu.getSelector();

            if (input.isPressed(BACK))
                hide();
            if (input.isPressed(UP))
                menu.previous();
            if (input.isPressed(DOWN))
                menu.next();
            if (input.isPressed(LEFT))
                left();
            if (input.isPressed(RIGHT))
                right();
            if (input.isPressed(ENTER))
                enterResolve(selector.getSelector(), menu.getSelector());

            menu.render();
        }

        else if (sound_modal.getState() == InterfaceState::VISIBLE && menu.getSelector() == 0 && selector.getSelector() == 0)
        {
            if (input.isPressed(BACK))
                resolveBack(selector.getSelector(), menu.getSelector());
            if (input.isPressed(ENTER))
                resolveSave(selector.getSelector(), menu.getSelector());
            if (input.isPressed(LEFT))
                sound_modal.left();
            if (input.isPressed(RIGHT))
                sound_modal.right();
            sound_modal.render();
        }
        else if (clock_modal.getState() == InterfaceState::VISIBLE && menu.getSelector() == 1 && selector.getSelector() == 0)
        {
            if (input.isPressed(BACK))
                resolveBack(selector.getSelector(), menu.getSelector());
            if (input.isPressed(ENTER))
                resolveSave(selector.getSelector(), menu.getSelector());
            if (input.isPressed(LEFT))
                clock_modal.left();
            if (input.isPressed(RIGHT))
                clock_modal.right();
            if (input.isPressed(UP))
                clock_modal.up();
            if (input.isPressed(DOWN))
                clock_modal.down();

            clock_modal.render();
        }
        else if (date_modal.getState() == InterfaceState::VISIBLE && menu.getSelector() == 2 && selector.getSelector() == 0)
        {
            if (input.isPressed(BACK))
                resolveBack(selector.getSelector(), menu.getSelector());
            if (input.isPressed(ENTER))
                resolveSave(selector.getSelector(), menu.getSelector());
            if (input.isPressed(LEFT))
                date_modal.left();
            if (input.isPressed(RIGHT))
                date_modal.right();
            if (input.isPressed(UP))
                date_modal.up();
            if (input.isPressed(DOWN))
                date_modal.down();
            date_modal.render();
        }
        else if (reset_modal.getState() == InterfaceState::VISIBLE && menu.getSelector() == 3 && selector.getSelector() == 0)
        {
            if (input.isPressed(BACK))
                resolveBack(selector.getSelector(), menu.getSelector());
            if (input.isPressed(ENTER))
                resolveSave(selector.getSelector(), menu.getSelector());
            if (input.isPressed(LEFT))
                reset_modal.left();
            if (input.isPressed(RIGHT))
                reset_modal.right();
            reset_modal.render();
        }
        else if (pedal_dev_f_modal.getState() == InterfaceState::VISIBLE && menu.getSelector() == 0 && selector.getSelector() == 1)
        {
            if (input.isPressed(BACK))
                resolveBack(selector.getSelector(), menu.getSelector());
            if (input.isPressed(ENTER))
                resolveSave(selector.getSelector(), menu.getSelector());
            if (input.isPressed(LEFT))
                pedal_dev_f_modal.left();
            if (input.isPressed(RIGHT))
                pedal_dev_f_modal.right();
            pedal_dev_f_modal.render();
        }
        else if (pedal_dev_r_modal.getState() == InterfaceState::VISIBLE && menu.getSelector() == 1 && selector.getSelector() == 1)
        {
            if (input.isPressed(BACK))
                resolveBack(selector.getSelector(), menu.getSelector());
            if (input.isPressed(ENTER))
                resolveSave(selector.getSelector(), menu.getSelector());
            if (input.isPressed(LEFT))
                pedal_dev_r_modal.left();
            if (input.isPressed(RIGHT))
                pedal_dev_r_modal.right();
            pedal_dev_r_modal.render();
        }
    }
    void show() override { state = InterfaceState::VISIBLE; }
    void hide() override { state = InterfaceState::HIDDEN; }
    InterfaceState getState() const override { return state; }

private:
    void right()
    {
        selector.increment();
        menu.load(selector.getSelector());
    }
    void left()
    {
        selector.decrement();
        menu.load(selector.getSelector());
    }
    void enterResolve(int side_selector, int value_selector)
    {
        if (side_selector == 0 && value_selector == 0)
            enterExecuter(sound_modal);
        else if (side_selector == 0 && value_selector == 1)
            enterExecuter(clock_modal);
        else if (side_selector == 0 && value_selector == 2)
            enterExecuter(date_modal);
        else if (side_selector == 0 && value_selector == 3)
            enterExecuter(reset_modal);
        else if (side_selector == 1 && value_selector == 0)
            enterExecuter(pedal_dev_f_modal);
        else if (side_selector == 1 && value_selector == 1)
            enterExecuter(pedal_dev_r_modal);
    }

    void resolveBack(int side_selector, int value_selector)
    {
        if (side_selector == 0 && value_selector == 0)
            backExecuter(sound_modal);
        else if (side_selector == 0 && value_selector == 1)
            backExecuter(clock_modal);
        else if (side_selector == 0 && value_selector == 2)
            backExecuter(date_modal);
        else if (side_selector == 0 && value_selector == 3)
            backExecuter(reset_modal);
        else if (side_selector == 1 && value_selector == 0)
            backExecuter(pedal_dev_f_modal);
        else if (side_selector == 1 && value_selector == 1)
            backExecuter(pedal_dev_r_modal);
    }
    void resolveSave(int side_selector, int value_selector)
    {
        if (side_selector == 0 && value_selector == 0)
            saveExecuter(sound_modal);
        else if (side_selector == 0 && value_selector == 1)
            saveExecuter(clock_modal);
        else if (side_selector == 0 && value_selector == 2)
            saveExecuter(date_modal);
        else if (side_selector == 0 && value_selector == 3)
            saveExecuter(reset_modal);
        else if (side_selector == 1 && value_selector == 0)
            saveExecuter(pedal_dev_f_modal);
        else if (side_selector == 1 && value_selector == 1)
            saveExecuter(pedal_dev_r_modal);
    }
    void enterExecuter(IPopupController<SettingsSelectors> &interface)
    {
        menu.hide();
        interface.load(selectors_list);
        interface.show();
    }
    void backExecuter(IPopupController<SettingsSelectors> &interface)
    {
        menu.show();
        interface.hide();
    }
    void saveExecuter(IPopupController<SettingsSelectors> &interface)
    {
        interface.enter();
        menu.show();
        interface.hide();
    }
};