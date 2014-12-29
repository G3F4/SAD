#include "tests/BaseObjectTest.hpp"
#include "tests/WindowTest.hpp"
#include "tests/ApplicationTest.hpp"
#include "tests/TextureManagerTest.hpp"


int main()
{
//    BaseObjectTestCase* base_object_test = new BaseObjectTestCase();
//    base_object_test->BaseObjectTest();
//    delete base_object_test;
//    WindowTestCase* window_test = new WindowTestCase();
//    window_test->main_test();
//    delete  window_test;
//    AppicationTestCase* app_test = new AppicationTestCase();
//    app_test->main_test();
//    delete app_test;
    TextureManagerTestCase *txs_test = new TextureManagerTestCase();
    txs_test->main_test();
    delete txs_test;
    return 0;
}
