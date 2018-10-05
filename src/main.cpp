#include <iostream>
#include "WSDON/WSDONSerializer.h"
#include "DocumentManagement/Documents/CommonUtility/DocumentUtility.h"
#include "DocumentManagement/Documents/Data/DataDocumentManager.h"

int main() {
    DocumentUtility::initialise();
    auto obj = structure::WSDONDocument();
    obj.object = std::make_shared<structure::WSDONObject>();
    auto map = std::make_shared<structure::WSDONObject::object_type>();
    (*map)["id"] = structure::WSDONObject();

    (*map)["id"].setBasic("tings");
    auto myObject = structure::WSDONObject();
    auto map2 = std::make_shared<structure::WSDONObject::object_type>();
    (*map2)["id2"] = structure::WSDONObject();
    (*map2)["id2"].setBasic("apples\nnewline tings");
    (*map)["myObject"].setObject(map2);
    (*map)["back"] = structure::WSDONObject();
    (*map)["back"].setBasic("apples back");
    obj.object->setObject(map);


    auto dDoc = std::make_shared<structure::DocumentMetaData>();
    dDoc->primaryIndexValue = "0";
    dDoc->tableIdentifier = "tings";

    auto document = std::make_shared<structure::DataDocument>();
    document->primaryIndexValue = "0";
    document->tableIdentifier = "tings";
    document->documentData = obj;
    document->primaryIndexIdentifier = "id";


    DataDocumentManager docManager = DataDocumentManager();
    docManager.writeDocument(document);

    auto data = docManager.readDocument(dDoc);
    data->primaryIndexValue = "1";
    docManager.writeDocument(data);

    return 0;
}