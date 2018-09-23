#pragma once

#include "../controller/controller.h"

#include <string>

namespace ui {

class IUi
{
public:
    virtual void displayError(std::string) = 0;
    virtual void reportResult(std::string) = 0;
    virtual void clearInputField() = 0;
    virtual void reset() = 0;
    virtual void askForNewGame() = 0;

    virtual void setController(controller::Controller*) = 0;
    virtual void start() = 0;
};

} // namespace ui