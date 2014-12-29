#ifndef APPLICATIONTEST_HPP
#define APPLICATIONTEST_HPP

//#include "../SAD.hpp"
#include "../singletons/Application.hpp"


class AppicationTestCase {
public:
    void main_test();
    void details(Application& app);
    void assertion_test(Application& app);
};

#endif