#ifndef WINDOWTEST_H_DEFINED
#define WINDOWTEST_H_DEFINED

#include "../entities/Window.hpp"

class WindowTestCase {
public:
    WindowTestCase();
    ~WindowTestCase();
    void main_test(void);
    void details(Window* win);
    void assertion_test(Window* win);
};

#endif