#pragma once

#include "../model/ICommander.h"
#include "../model/IInput.h"

namespace controller {

class Controller
{
private:
    model::ICommander *commander;
    model::IInput *input;

    Controller(Controller&) = delete;
    Controller(Controller&&) = delete;

public:

    Controller(model::ICommander*, model::IInput*);

    virtual void onNextButtonPress(int value) const;
    virtual void onSortByttonPress() const;
};

} // namespace controller
