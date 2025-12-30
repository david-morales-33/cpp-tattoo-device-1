#pragma once
#include <application/shared/controller.h>

class OperationController : public IController
{
private:
    InterfaceState state = InterfaceState::HIDDEN;

public:
    void execute() override {}
    void hide() override {}
    void show() override {}
    InterfaceState getState() const override { return state; }
};