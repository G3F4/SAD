#include <iostream>
#include <typeinfo>

#include "../utils/test-tools.hpp"
#include "BaseObjectTest.hpp"



void BaseObjectTestCase::test_obj_details(BaseObject* test_obj) {
    std::cout.width(20);
    std::cout << "BaseObject details \n#";
    std::cout.width(15);
    std::cout << "Type: ";
    std::cout << typeid(test_obj).name() << std::endl << "#";
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

void BaseObjectTestCase::BaseObject_assertion_test(BaseObject* test_obj, std::string ID, int x, int y, int width, int height, bool state)
{
    static int test_index = 1;
    std::cout << "### ASSERTION NR " << test_index << std::endl;
    ASSERT(test_obj->get_x_position() == x, "x position");
    ASSERT(test_obj->get_y_position() == y, "x position");
    ASSERT(test_obj->get_width() == width, "width");
    ASSERT(test_obj->get_height() == height, "height");
    ASSERT(test_obj->get_ID() == ID, "ID");
    ASSERT(test_obj->is_active() == state, "state");
    std::cout << "Assertion test completed. \nAll test completed with no errors." << std::endl;
    test_index++;
}

bool BaseObjectTestCase::BaseObjectTest(void) {
    std::cout << "### BaseObject class test ###" << std::endl;
    // test object creation
    BaseObject* test_obj1 = new BaseObject("TestObject1", 100, 100, 100, 100, true);
    std::cout << "Checking the contructor..." << std::endl;
    ASSERT(test_obj1 != nullptr, "Undefined ocject!");
    std::cout << "Contructor WORKS!" << std::endl;
    test_obj_details(test_obj1);
    BaseObject_assertion_test(test_obj1, "TestObject1", 100, 100, 100, 100, true);
    std::cout << "changing object properties" << std::endl;
    test_obj1->set_x_position(200);
    test_obj1->set_y_position(200);
    test_obj1->set_width(200);
    test_obj1->set_height(200);
    test_obj1->disable();
    std::cout << "Testing object setters" << std::endl;
    test_obj_details(test_obj1);
    BaseObject_assertion_test(test_obj1, "TestObject1", 200, 200, 200, 200, false);
    SDL_Point* p1 = new SDL_Point();
    p1->x = 100;
    p1->y = 100;
    SDL_Point* p2 = new SDL_Point();
    p2->x = 200;
    p2->y = 200;
    BaseObject* test_obj2 = new BaseObject("TestObject2", p1, p2, false);
    test_obj_details(test_obj2);
    BaseObject_assertion_test(test_obj2, "TestObject2", 100, 100, 100, 100, false);
    std::cout << "changing test object nr 2" << std::endl;
    test_obj2->set_position(200, 200, 200, 200);
    test_obj_details(test_obj2);
    BaseObject_assertion_test(test_obj2, "TestObject2", 200, 200, 200, 200, false);
    p1->x = 100;
    p1->y = 100;
    p2->x = 200;
    p2->y = 200;
    test_obj2->set_size(p1, p2);
    test_obj2->enable();
    test_obj_details(test_obj2);
    BaseObject_assertion_test(test_obj2, "TestObject2", 100, 100, 100, 100, true);
    p2 = test_obj2->get_position();
    test_obj2->set_size(p1, p2);
    test_obj_details(test_obj2);
    BaseObject_assertion_test(test_obj2, "TestObject2", 100, 100, 0, 0, true);
    p2->x = 200;
    p2->y = 200;
    test_obj2->set_position(p2);
    test_obj_details(test_obj2);
    BaseObject_assertion_test(test_obj2, "TestObject2", 200, 200, 0, 0, true);
    test_obj2->set_position(100, 100);
    test_obj_details(test_obj2);
    BaseObject_assertion_test(test_obj2, "TestObject2", 100, 100, 0, 0, true);
    std::cout << "Base Object Test COMPLETED!!@@@###" << std::endl;
    return true;
}


