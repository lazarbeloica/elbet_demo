#pragma once

#include <functional>

namespace ui {

typedef void(*uiCallback)(int);

class IUiActions
{
public:
    virtual void registerOnNextButtonPress() = 0;
    virtual void registerOnSortButtonPress() = 0;
    virtual void registerOnContinueButtonPress() = 0;
};

} // namespace ui