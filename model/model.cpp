#include "model.h"

namespace model {

Model::Model() {
    algorithm::SortAlgorithmFactory *algFactory = algorithm::SortAlgorithmFactory::getInstance();
    algorithm = algFactory->getAlgorithm<int>(SELECTED_SORT_ALGORITHM);

    db::DBDriverFactory *dbFactory = db::DBDriverFactory::getInstance();
    db = dbFactory->getDB<int>(SELECTED_DB_DRIVER);
}

Model::~Model() {
    delete algorithm;
    delete db;
}
void Model::inputNumber(int input) {
    inputRecord.push_back(input);
    if (ui) {
        ui->clearInputField();
    }
}

void Model::Reset() {
    inputRecord.clear();
}

std::string Model::parseResult(const std::vector<int>& res) {

    std::ostringstream parsedResult;

    for(int i = 0; i < res.size() - 1; parsedResult << res[i++] << RESULT_SCORE_DELIMITER);
    parsedResult << res[res.size() - 1];
    return parsedResult.str();
}

void Model::Sort() {
    if (inputRecord.size() == 0) {
        return;
    }

    std::cout << "path" << DB_PATH << std::endl;
    if (db->connect(DB_PATH)) {
        algorithm->sort(inputRecord);
        db->storeResult(inputRecord);
        db->disconnect();
    }

    if (ui) {
        ui->reportResult(parseResult(inputRecord));
        ui->askForNewGame();
    }

    std::cout << "clearing" << std::endl;
    inputRecord.clear();
    std::cout << "cleared" << std::endl;
}

void Model::setUi(ui::IUi *Ui) {
    ui = Ui;
}

} // namespace model