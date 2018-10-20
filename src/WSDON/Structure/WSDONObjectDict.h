//
// Created by kyle on 20/10/18.
//

#ifndef DOCDB_WSDONOBJECTDICT_H
#define DOCDB_WSDONOBJECTDICT_H

#include "WSDONObject.h"

namespace structure {
    struct WSDONObjectDict {
        WSDONObjectDict(std::shared_ptr<structure::WSDONObject> &obj) {
            object = obj;
        }

        WSDONObjectDict() {
            init();
        }

        void init() {
            if (!object) {
                object = std::make_shared<structure::WSDONObject>();
            }
        }

        std::shared_ptr<structure::WSDONObject> object;

        WSDONObjectDict operator[](std::string key) {
            init();
            auto type = object->getType();
            if (type == structure::WSDONObject::Object) {
                auto obj = object->getObject();
                structure::WSDONObject::object_type::iterator posIt = (*obj).find(key);
                if (posIt == obj->end()) {
                    (*obj)[key] = std::make_shared<structure::WSDONObject>();
                    return structure::WSDONObjectDict((*obj)[key]);
                }
                return structure::WSDONObjectDict((*obj)[key]);

            }
            auto obj = std::make_shared<structure::WSDONObject::object_type>();
            (*obj)[key] = std::make_shared<structure::WSDONObject>();
            object->setObject(obj);
            return structure::WSDONObjectDict((*obj)[key]);
        }

        WSDONObjectDict operator[](unsigned int key) {
            init();
            auto type = object->getType();
            if (type == structure::WSDONObject::Array) {
                auto obj = object->getArray();
                return WSDONObjectDict(obj->at(key));
            }
            return structure::WSDONObjectDict();
        }

        void operator=(WSDONObjectDict &dict) {
            init();
            object = dict.object;
        }

        void operator=(std::string str) {
            init();
            object->setBasic(str);
        }

        void operator=(std::shared_ptr<structure::WSDONObject::object_type> obj) {
            init();
            object->setObject(obj);
        }

        void operator=(std::shared_ptr<structure::WSDONObject::array_type> arr) {
            init();
            object->setArray(arr);
        }

        std::string getBasic() {
            auto type = object->getType();
            if (type == structure::WSDONObject::Basic) {
                return object->getBasic();
            }
            return "";
        }
    };
}

#endif //DOCDB_WSDONOBJECTDICT_H
