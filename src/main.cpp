#include "tests/BaseObjectTest.hpp"
#include "tests/WindowTest.hpp"

int main()
{
//    BaseObjectTestCase* test1 = new BaseObjectTestCase();
//    test1->BaseObjectTest();
    WindowTestCase* window_test = new WindowTestCase();
    window_test->main_test();
    return 0;
}
