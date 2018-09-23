
#include "ui.h"

namespace {
// incredably ugly, sorry
ui::Ui *globalUi = nullptr;

static void control_cb_global( GLUI_Control* control ) {
    if(globalUi) {
        globalUi->control_cb(control);
    }
}

}

namespace ui {

const int NEXT_BUTTON = 100;
const int SORT_BUTTON = 200;
const int ERR_OK_BUTTON = 300;
const int CONTINUE_BUTTON = 300;

// ui
const char* NEXT_BUTTON_LABEL = "Next number";
const char* SORT_BUTTON_LABEL = "Execute sort";
const char* CONTINUE_BUTTON_LABEL = "Continue?";
const char* OK_BUTTON_LABEL = "OK";

const char* ERR_WINDOW_LABEL = "Error";
const char* NEWGAME_WINDOW_LABEL = "New game";
const char* MAIN_WINDOW_LABEL = "Game";

const char* ERR_MSG = "Invalid input";
const char* NEWGAME_MSG = "Do you wish to start new game?";

const char* INPUT_FIELD_LABEL = "Input number:";
const char* RESULT_LABEL = "Result:";

void Ui::control_cb( GLUI_Control* control )
{
    if (control->get_id() == NEXT_BUTTON ||
        (control->get_id() == SORT_BUTTON && inputField != "")) {
        try {
            LOG_INFO(inputField);
            int in = std::stoi(inputField);
            if(controler) {
                controler->onNextButtonPress(in);
            }
            clearInputField();

        } catch (std::invalid_argument e) {
            displayError(ERR_MSG);
            return;
          }
    }

    if (control->get_id() == SORT_BUTTON ) {
        if (controler) {
            controler->onSortByttonPress();
        }
    }

    if (control->get_id() == ERR_OK_BUTTON ) {
        clearErrorMessage();
    }

    if (control->get_id() == CONTINUE_BUTTON ) {
        startNewGame();
    }
}

Ui::Ui() {
    ::globalUi = this;
}

Ui::~Ui() {
    ::globalUi = nullptr;
}

void Ui::start() {
    int argc = 1;
    char *argv[1] = {(char*)"Something"};
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowPosition( 50, 50 );
    glutInitWindowSize( 600, 300 );

    GLfloat light0_ambient[] =  {0.1f, 0.1f, 0.3f, 1.0f};
    GLfloat light0_diffuse[] =  {.6f, .6f, 1.0f, 1.0f};
    GLfloat light0_position[] = {1.0f, 1.0f, 1.0f, 0.0f};

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

    glEnable(GL_DEPTH_TEST);

    GLUI *mainWindow = GLUI_Master.create_glui( MAIN_WINDOW_LABEL );
    input = new GLUI_EditText( mainWindow, INPUT_FIELD_LABEL, inputField, 3);

    nextButton = mainWindow->add_button( NEXT_BUTTON_LABEL, NEXT_BUTTON, control_cb_global);
    sortButton = mainWindow->add_button( SORT_BUTTON_LABEL, SORT_BUTTON, control_cb_global);

    result = new GLUI_EditText( mainWindow, RESULT_LABEL, resultField, 3);
    result->disable();

    glutMainLoop();
}

void Ui::disableMainWindow() {
    nextButton->disable();
    sortButton->disable();
    input->disable();
}

void Ui::enableMainWindow() {
    nextButton->enable();
    sortButton->enable();
    input->enable();
}

void Ui::displayError(std::string msg) {
    error_gui = GLUI_Master.create_glui( ERR_WINDOW_LABEL );
    error_gui->add_statictext(msg);
    error_gui->add_button( OK_BUTTON_LABEL, ERR_OK_BUTTON, control_cb_global);
    disableMainWindow();
}

void Ui::clearErrorMessage() {
    enableMainWindow();
    clearInputField();

    if (error_gui) {
        error_gui->close();
    }

    error_gui = nullptr;
}

void Ui::reportResult(std::string res) {
    if (result) {
        result->set_text(res);
    }
}

void Ui::clearInputField() {
    if (input) {
        input->set_text("");
    }
}

void Ui::reset() {
    clearInputField();
    if (result) {
        result->set_text("");
    }
}

void Ui::askForNewGame() {
    disableMainWindow();
    newgame_gui = GLUI_Master.create_glui( NEWGAME_WINDOW_LABEL );
    newgame_gui->add_statictext(NEWGAME_MSG);
    newgame_gui->add_button( CONTINUE_BUTTON_LABEL, CONTINUE_BUTTON, control_cb_global);
}

void Ui::startNewGame() {
    reset();

    if(newgame_gui) {
        newgame_gui->close();
    }

    newgame_gui = nullptr;
}

void Ui::setController(controller::Controller *cnt) {
    controler = cnt;
}

} // namespace ui
/*
int main() {
    ui::Ui *ui = new ui::Ui();
    ui->start();
    int a;
    std::cin >> a;
    ui->displayError("error");
}
*/