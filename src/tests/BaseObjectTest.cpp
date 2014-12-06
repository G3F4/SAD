#include <iostream>
#include <string>

#include "../utils/test-tools.hpp"

#include "../entities/base/BaseObject.hpp"

static void test_obj_details(BaseObject* test_obj) {
    static int obj_count = 0;
    obj_count++;
    std::cout << "#";
    std::cout.width(20);
    std::cout << "Testing object #";
    std::cout << obj_count << "..." << std::endl << "#";
    std::cout.width(15);
    std::cout << "Test result: ";
    std::cout << std::endl << "#";
    std::cout.width(15);
    std::cout << "ID: ";
    std::cout << test_obj->get_ID() << std::endl << "#";
    std::cout.width(15);
    std::cout << "x position: ";
    std::cout << test_obj->get_x_position() << std::endl << "#";
    std::cout.width(15);
    std::cout << "y position: ";
    std::cout << test_obj->get_y_position() << std::endl << "#";
    std::cout.width(15);
    std::cout << "width: ";
    std::cout << test_obj->get_width() << std::endl << "#";
    std::cout.width(15);
    std::cout << "height: ";
    std::cout << test_obj->get_height() << std::endl << "#";
    std::cout.width(15);
    std::cout << "state: ";
    std::cout << test_obj->is_active() << std::endl << "#";
    std::cout << "#############################" << std::endl;
}

void baseObject_assertion_test(BaseObject* test_obj,
                               std::string ID = "TestObject",
                               int x = 100,
                               int y = 100,
                               int width = 100,
                               int height = 100,
                               bool state = true)
{
    ASSERT(test_obj->get_x_position() == x, "x position");
    ASSERT(test_obj->get_y_position() == y, "x position");
    ASSERT(test_obj->get_width() == width, "width");
    ASSERT(test_obj->get_height() == height, "height");
    ASSERT(test_obj->get_ID() == ID, "ID");
    ASSERT(test_obj->is_active(), "state");
    std::cout << "Assertion test completed. \nAll test completed with no errors." << std::endl;
}

bool BaseObjectTest(void) {
    std::cout << "### BaseObject class test ###" << std::endl;
    // test object creation
    BaseObject* test_obj1 = new BaseObject("TestObject1", 100, 100, 100, 100, true);
    test_obj_details(test_obj1);
    baseObject_assertion_test(test_obj1, "TestObject1", 100, 100, 100, 100, true);
//    SDL_Point* p1 = new SDL_Point();
//    p1->x = 100;
//    p1->y = 100;
//    SDL_Point* p2 = new SDL_Point();
//    p2->x = 200;
//    p2->y = 200;
//    BaseObject* test_obj2 = new BaseObject("TestObject2", p1, p2, false);
//    test_obj_details(test_obj2);
//    baseObject_assertion_test(test_obj1, "TestObject1", 100, 100, 100, 100, true);
    return true;
}


