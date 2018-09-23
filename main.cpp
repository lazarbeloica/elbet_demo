
#include "controller/controller.h"
#include "ui/IUi.h"
#include "ui/ui.h"
#include "model/model.h"
#include "model/ICommander.h"
#include "model/IInput.h"

int main(int argc, char** argv) {

    ui::IUi *ui= new ui::Ui();

    model::Model *model = new model::Model();
    model->setUi(ui);
    controller::Controller *controller = new controller::Controller(model, model);
    ui->setController(controller);
    ui->start();
    return 0;
}