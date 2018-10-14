//
// Created by kyle on 14/10/18.
//

#ifndef DOCDB_TABLECREATEDATA_H
#define DOCDB_TABLECREATEDATA_H

#include <string>
#include <vector>
#include "TableInitData.h"

namespace structure {
    namespace tables {
        struct TableCreateIndex{
            std::string columnName;
            std::string columnPath;
        };
        struct TableCreateData : public structure::tables::TableInitData {
            std::vector<TableCreateIndex> indices;
        };
    }
}
#endif //DOCDB_TABLECREATEDATA_H
