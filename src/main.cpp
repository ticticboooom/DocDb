#include <iostream>
#include "WSDON/WSDONSerializer.h"
#include "DocumentManagement/Documents/Data/DataDocumentManager.h"
#include "DocumentManagement/Documents/Indexing/IndexSignatureDocumentManager.h"
#include "IO/CommonUtility/PathUtility.h"
#include "Tables/Table.h"

int main() {
    PathUtility::initialise();
    auto createData = std::make_shared<structure::tables::TableCreateData>();
    createData->indices = std::vector<structure::tables::TableCreateIndex>();
    createData->indices.push_back({"id", "id"});
    createData->name = "tings";
    auto table = std::make_unique<Table>(createData);
    table->doStuff();

    return 0;
}