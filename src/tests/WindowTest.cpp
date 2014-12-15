#include "../utils/test-tools.hpp"
#include "../utils/comparator.hpp"
#include "BaseObjectTest.hpp"
#include "WindowTest.hpp"
#include <iostream>

using namespace std;

void WindowTestCase::main_test(void) {
    Window* win = new Window("Test Window", 100, 100 ,640, 480, true, SDL_WINDOW_SHOWN);
    win->clear();
    win->present();
    details(win);
    assertion_test(win);
}

WindowTestCase::WindowTestCase() {
    SDL_Init(SDL_INIT_EVERYTHING);
}

WindowTestCase::~WindowTestCase() {
    SDL_Quit();
}

void WindowTestCase::details(Window *win) {
    BaseObjectTestCase::test_obj_details(win);
    cout.width(30);
    cout << "Window Object specific properties" << endl << "#";
    std::cout.width(15);
    std::cout << "title: ";
    std::cout << win->get_title() << std::endl << "#";
    std::cout.width(15);
    std::cout << "color: ";
    /* SDL_Color is structure containing 4 Uint8. To cout values we need cast it to int */
    std::cout << "R:" << int(win->get_color().r) \
              << ", G:" <<  int(win->get_color().g) \
              << ", B:" <<  int(win->get_color().b) \
              << ", A:" <<  int(win->get_color().a) << std::endl << "#";
    std::cout << "#############################" << std::endl;
}

void WindowTestCase::assertion_test(Window *win) {
    ASSERT(win != NULL, "Checking if the object is not NULL");
    ASSERT(win->get_window() != NULL, "Checking SDL_Window");
    ASSERT(win->get_renderer() != NULL, "Checking SDL_Renderer");
    string new_title = "New title";
    win->set_title(new_title);
    ASSERT(win->get_title() == new_title, "Checking set and get title");
    SDL_Color new_color = {0,0,0,0};
    win->set_color(new_color);
    ASSERT(compare_SDL_Color(win->get_color(), new_color), "Checking set and get color");
//    ASSERT(true, "");
}
