#include <iostream>
#include "WSDON/WSDONSerializer.h"
#include "DocumentManagement/Docuemnts/CommonUtility/DocumentUtility.h"
#include "DocumentManagement/Docuemnts/Data/DataDocumentManager.h"

int main() {
    DocumentUtility::initialise();
    std::cout << "Hello, World!" << std::endl;
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

    auto dDoc = std::make_shared<structure::DataDocument>();
    dDoc->documentData = obj;
    dDoc->primaryIndexValue = "0";
    dDoc->primaryIndexIdentifier = "id";
    dDoc->tableIdentifier = "tings";

    DataDocumentManager docManager = DataDocumentManager();
    docManager.writeDocument(dDoc);


    return 0;
}