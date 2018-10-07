//
// Created by Kyle on 29/09/2018.
//

#ifndef DOCDB_WSDONOBJECT_H
#define DOCDB_WSDONOBJECT_H

#include <map>
#include <vector>
#include <memory>

namespace structure {
    struct WSDONObject {
        enum WSDONObjectType {
            Array = 0,
            Object = 1,
            Basic = 2
        };
        typedef std::map<std::string, WSDONObject> object_type;

        void setArray(std::shared_ptr<std::vector<structure::WSDONObject>> val) {
            array = val;
            type = WSDONObjectType::Array;
        }

        void setObject(std::shared_ptr<object_type> val) {
            object = val;
            type = WSDONObjectType::Object;
        }

        void setBasic(std::string val) {
            basic = val;
            type = WSDONObjectType::Basic;
        }

        std::string getBasic() const { return basic; };

        std::shared_ptr<std::vector<structure::WSDONObject>> getArray() const { return array; }

        std::shared_ptr<object_type> getObject() const { return object; }

        structure::WSDONObject::WSDONObjectType getType() const {return type;}
    private:
        WSDONObjectType type;
        std::string basic;
        std::shared_ptr<std::vector<structure::WSDONObject>> array;
        std::shared_ptr<object_type> object;
    };
}

#endif //DOCDB_WSDONOBJECT_H
