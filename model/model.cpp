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
}

void Model::Reset() {
    inputRecord.clear();
}

void Model::Sort() {
    if (inputRecord.size() == 0) {
        return;
    }

    db->connect(DB_PATH);
    algorithm->sort(inputRecord);
    db->storeResult(inputRecord);
    db->disconnect();
}

} // namespace model