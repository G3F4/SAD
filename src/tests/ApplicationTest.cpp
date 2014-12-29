#include "ApplicationTest.hpp"
#include "../utils/test-tools.hpp" // because of weird Clion bug
#include "../utils/test-tools.hpp"



void AppicationTestCase::main_test() {
    Application& APP = Application::Instance();
    APP.create_window("TestWindow", 100, 100, 100, 100, true, SDL_WINDOW_HIDDEN, SDL_RENDERER_ACCELERATED);
    APP.create_window("TestWindow2", 800, 400, 100, 100, true, SDL_WINDOW_HIDDEN, SDL_RENDERER_ACCELERATED);
    details(APP);
    assertion_test(APP);
}

void AppicationTestCase::details(Application& APP) {
    std::cout << "Application Test Details" << std::endl;
    std::cout << "Windows count: " << APP.get_windows().size() << std::endl;
}

void AppicationTestCase::assertion_test(Application& APP) {
    ASSERT(!APP.is_running(), "Application m_running flag initilized with wrong flag");
    APP.start();
    ASSERT(APP.is_running(), "Application m_running flag wrong value after start");
    APP.stop();
    ASSERT(!APP.is_running(), "Application m_running flag wrong value after stop");
    APP.show();
    SDL_Delay(1000);
    for (auto win: APP.get_windows()) {
        ASSERT(win.second->is_visible(), "Checking windows visibility");
    }
    APP.hide();
    for (auto win: APP.get_windows()) {
        ASSERT(!win.second->is_visible(), "Checking windows visibility");
    }
    ASSERT(APP.get_window("TestWindow") != nullptr, "Failed getting Window instance.");
    APP.show();
    int x = 100;
    int y = 100;
    SDL_Point p1 = {500,400};
    SDL_Point p2 = {1000,800};
    for (int i = 0 ; i < 200 ; i++) {
        x++;
        y++;
        APP.get_window("TestWindow")->set_x_position(x);
        APP.get_window("TestWindow")->set_y_position(y);
        APP.get_window("TestWindow")->set_width(x);
        APP.get_window("TestWindow")->set_height(y);
        p2.x--;
        p2.y--;
        APP.get_window("TestWindow2")->set_position(&p1);
        APP.get_window("TestWindow2")->set_size(&p1, &p2);
        APP.pause(10);
    }
    APP.hide();
    APP.pause(500);
    APP.show();
    APP.pause(500);
    std::cout << std::endl;
}
