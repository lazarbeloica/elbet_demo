
#include "controller/controller.h"
#include "ui/IUi.h"
#include "ui/ui.h"
#include "model/model.h"
#include "model/ICommander.h"
#include "model/IInput.h"
#include "common/configuration.h"

std::string DB_PATH = DEFAULT_DB_PATH;

int main(int argc, char** argv) {

    if (argc == 2) {
        DB_PATH = argv[1];
    }

    ui::IUi *ui= new ui::Ui();

    model::Model *model = new model::Model();
    model->setUi(ui);
    controller::Controller *controller = new controller::Controller(model, model);
    ui->setController(controller);
    ui->start();
    return 0;
}