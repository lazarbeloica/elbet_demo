#pragma once

#include "IUi.h"
//#include "IUiActions.h"

#include "../common/configuration.h"
#include "../common/logger.h"

#include <GL/glui.h>

#include <GL/glut.h>

#include <string>
#include <functional>

//namespace {
//
//static void control_cb_global( GLUI_Control* control);
//
//} // namesoace

namespace ui {


class Ui: public IUi //, public IUiActions
{
private:
    std::string inputField;
    std::string resultField;

    GLUI *mainWindow;
    GLUI *error_gui;
    GLUI *newgame_gui;

    GLUI_Button *nextButton;
    GLUI_Button *sortButton;

    GLUI_EditText *error;
    GLUI_EditText *result;
    GLUI_EditText *input;
/*
    uiCallback nextButtonCallback = nullptr;
    uiCallback sortButtonCallback = nullptr;
    uiCallback continueButtonCallback = nullptr;
*/
    controller::Controller *controler = nullptr;

    Ui(Ui&) = delete;
    Ui(Ui&&) = delete;

    Ui operator=(Ui&) = delete;
    Ui operator=(Ui&&) = delete;

    void clearErrorMessage();
    void disableMainWindow();
    void enableMainWindow();
    void startNewGame();
    //friend void ::control_cb_global(GLUI_Control* control);


public:
void control_cb(GLUI_Control*);
    Ui();
    virtual ~Ui();
    virtual void start() override;

    virtual void displayError(std::string) override;
    virtual void reportResult(std::string) override;
    virtual void clearInputField() override;
    virtual void reset() override;
    virtual void askForNewGame() override;

    virtual void setController(controller::Controller*) override;

//    virtual void registerOnNextButtonPress() override;
//    virtual void registerOnSortButtonPress() override;
//    virtual void registerOnContinueButtonPress() override;
};

} // namespace ui