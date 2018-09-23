
#pragma once

#include "ICommander.h"
#include "IInput.h"

#include "algorithm/ISortAlgorithm.h"
#include "algorithm/sortAlgorithmFactory.h"
#include "db/IDBDriver.h"
#include "db/dbDriverFactroy.h"

#include "../ui/IUi.h"

#include "../common/configuration.h"
#include "../common/logger.h"

#include <vector>


namespace model {

class Model: public ICommander, public IInput
{
private:
    std::vector<int> inputRecord;

    algorithm::ISortAlgorithm<int> *algorithm;
    db::IDBDriver<int> *db;

    Model(Model&) = delete;
    Model(Model&&) = delete;

    ui::IUi *ui = nullptr;
    std::string parseResult(const std::vector<int>& res);
public:
    Model();
    virtual ~Model();
    void setUi(ui::IUi *);

    virtual void inputNumber(int) override;

    virtual void Reset() override;
    virtual void Sort() override;

};

} // namespace model