#include "controller.h"

namespace controller {

Controller::Controller(model::ICommander *cmd, model::IInput *in):
            commander(cmd),
            input(in) {
                // Empty
            }

void Controller::onNextButtonPress(int value) const {
    input->inputNumber(value);
}

void Controller::onSortByttonPress() const {
    commander->Sort();
}

} // namespace controller