//
// Created by kyle on 14/10/18.
//

#ifndef DOCDB_TABLE_H
#define DOCDB_TABLE_H


#include <memory>
#include <map>
#include "Structure/TableInitData.h"
#include "../DocumentManagement/Documents/Structure/IndexDocument.h"
#include "../DocumentManagement/Documents/Data/DataDocumentManager.h"
#include "Structure/TableCreateData.h"

class Table {
public:
    Table(std::shared_ptr<structure::tables::TableCreateData> createData);
    void create(std::shared_ptr<structure::tables::TableCreateData> createData);
    void init(std::shared_ptr<structure::tables::TableInitData> initData);
    bool exists();
private:
    std::unique_ptr<std::map<std::string, std::shared_ptr<structure::IndexDocument>>> indexDocuments;
    std::unique_ptr<DataDocumentManager> dataDocumentManager;
    std::string name;
};


#endif //DOCDB_TABLE_H
