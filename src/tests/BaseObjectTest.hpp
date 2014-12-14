#ifndef BASEOBJECTTEST_H_DEFINED
#define BASEOBJECTTEST_H_DEFINED

#include "../entities/base/BaseObject.hpp"

class BaseObjectTestCase {
public:
    static void test_obj_details(BaseObject* test_obj);
    void BaseObject_assertion_test(BaseObject* test_obj,
            std::string ID = "TestObject",
            int x = 100,
            int y = 100,
            int width = 100,
            int height = 100,
            bool state = true);
    bool BaseObjectTest(void);
};




#endif
