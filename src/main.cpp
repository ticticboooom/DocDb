#include <iostream>
#include "WSDON/WSDONSerializer.h"
int main() {
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
    auto result = WSDONSerializer::serialize(obj);


    std::cout << result << std::endl;

    return 0;
}